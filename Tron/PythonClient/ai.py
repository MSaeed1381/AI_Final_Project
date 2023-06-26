# python imports
import math
import random
from enum import Enum
import copy as cp

from numpy.random import randint
from numpy.random import rand

# chillin imports
from chillin_client import RealtimeAI

# project imports
from ks.models import ECell, EDirection, Position
from ks.commands import ChangeDirection, ActivateWallBreaker


def dir_to_pos(direction):
    dir_to_pos_map = {
        EDirection.Up: Position(0, -1),
        EDirection.Down: Position(0, +1),
        EDirection.Right: Position(+1, 0),
        EDirection.Left: Position(-1, 0)
    }
    return dir_to_pos_map[direction]


class Utility:
    def print_board(self, board):
        for i in range(len(board)):
            for j in range(len(board[0])):
                print(board[i][j], end='')
            print()


class Move(Enum):
    Left = 0
    Up = 1
    Right = 2
    Down = 3


class State:
    def __init__(self, board, n, m, my_dir, other_dir,
                 my_rem_time, other_rem_time, my_cool_time, other_cool_time,
                 my_health, other_health,
                 my_position, other_position,
                 depth, my_score, other_score):

        self.n = n
        self.m = m
        self.board = board
        self.my_direction = my_dir
        self.other_direction = other_dir
        self.my_rem_time = my_rem_time
        self.other_rem_time = other_rem_time
        self.my_cool_time = my_cool_time
        self.other_cool_time = other_cool_time
        self.my_health = my_health
        self.other_health = other_health
        self.my_position = my_position
        self.other_position = other_position
        self.depth = depth
        self.my_score = my_score
        self.other_score = other_score


class AI(RealtimeAI):

    def __init__(self, world):
        super(AI, self).__init__(world)
        self.state = None

    def is_valid(self, x, y):
        return 0 <= x < len(self.world.board[0]) and 0 <= y < len(self.world.board)

    def initialize(self):
        print('initialize')
        agent = self.world.agents[self.my_side]
        other = self.world.agents[self.other_side]
        self.state = State(self.world.board, len(self.world.board[0]),
                           len(self.world.board), agent.direction, other.direction,
                           self.world.constants.wall_breaker_duration, self.world.constants.wall_breaker_duration,
                           self.world.constants.wall_breaker_cooldown, self.world.constants.wall_breaker_cooldown,
                           self.world.constants.init_health, self.world.constants.init_health,
                           agent.position, other.position,
                           self.world.constants.max_cycles * 2, 0, 0)

    def tournament_selection(self, ways, scores, q=10):
        selected = []
        for i in range(len(ways)):
            participants = random.sample(range(len(ways)), q)
            winner = participants[0]
            for p in participants[1:]:
                if scores[p] < scores[winner]:
                    winner = p
            selected.append(ways[winner])
        return selected

    def crossover(self, parent1, parent2, cross_rate):
        child1, child2 = parent1.copy(), parent2.copy()
        if rand() < cross_rate:
            pt = randint(1, len(parent1) - 2)
            child1 = parent1[:pt] + parent2[pt:]
            child2 = parent2[:pt] + parent2[pt:]
        return [child1, child2]

    def mutation(self, bitstring, mutation_rate):
        for i in range(len(bitstring)):
            if rand() < mutation_rate:
                to_replace = randint(0, len(bitstring))
                temp = bitstring[i]
                bitstring[i] = bitstring[to_replace]
                bitstring[to_replace] = temp

    def find_initial_chromosome(self, state, depth):
        board_copy = cp.deepcopy(state)
        chromosome = []
        for i in range(depth):
            action = random.choice(self.valid_dirs(board_copy, 1 if i % 2 == 0 else 0))
            chromosome.append(action)
            self.do_action(board_copy, action, 1 if i % 2 == 0 else 0, self.my_side, self.other_side)
        return chromosome

    def find_chromosome_state(self, state, chromosome):
        for i, val in enumerate(chromosome):
            self.do_action(state, val, 1 if i % 2 == 0 else 0, self.my_side, self.other_side)
        return state

    def genetic_algorithm(self, state, mutation_rate, cross_rate, depth, iteration_size, population_size):
        population = [self.find_initial_chromosome(state, depth) for _ in range(population_size)]
        best, best_eval = 0, self.winning_move(self.find_chromosome_state(cp.deepcopy(state), population[0]))
        for gen in range(iteration_size):
            scores = [self.winning_move(self.find_chromosome_state(cp.deepcopy(state), c)) for c in population]
            for i in range(population_size):
                if scores[i] < best_eval:
                    best, best_eval = population[i], scores[i]
            selected = self.tournament_selection(population, scores)
            children = []
            for i in range(0, len(selected), 2):
                parent1, parent2 = selected[i], selected[i + 1]
                for child in self.crossover(parent1, parent2, cross_rate):
                    self.mutation(child, mutation_rate)
                    children.append(child)
            population = children
        return [best, best_eval]

    def valid_dirs(self, state, SIDE):
        valids = []

        if SIDE:
            dir = state.my_direction
            wall_breaker_cooldown = state.my_cool_time
            wall_rem_time = state.my_rem_time
            x = state.my_position.x
            y = state.my_position.y

        else:
            dir = state.other_direction
            wall_breaker_cooldown = state.other_cool_time
            wall_rem_time = state.other_rem_time
            x = state.other_position.x
            y = state.other_position.y

        for move in EDirection:
            to_go = Position(x + dir_to_pos(move).x, y + dir_to_pos(move).y)
            if (dir.value + 2) % 4 != move.value and self.is_valid(to_go.x, to_go.y):
                if wall_breaker_cooldown > 0 or wall_rem_time > 0:
                    valids.append((move, 0))
                else:
                    valids.append((move, 0))
                    valids.append((move, 1))
        return valids

    def is_terminal_node(self, state):
        if state.board[state.my_position.y][state.my_position.x] == ECell.AreaWall or \
                state.depth == 0 or state.my_health == 0 or state.other_health == 0 or \
                state.board[state.other_position.y][state.other_position.x] == ECell.AreaWall:
            return True

        return False

    def winning_move(self, state):
        board = state.board
        my_wall_count = 0
        other_wall_count = 0
        for i in range(len(board)):
            for j in range(len(board[0])):
                if self.my_side == 'Yellow':
                    if board[i][j] == ECell.BlueWall:
                        other_wall_count += 1
                    elif board[i][j] == ECell.YellowWall:
                        my_wall_count += 1

                else:  # blue
                    if board[i][j] == ECell.BlueWall:
                        my_wall_count += 1
                    elif board[i][j] == ECell.YellowWall:
                        other_wall_count += 1

        score = (my_wall_count - other_wall_count)
        return score + state.my_score - state.other_score

    def do_action(self, state, action, SIDE, MY_SIDE, OTHER_SIDE):  # SIDE = 1 my side
        direction, activate_wallbreaker = action

        state.depth -= 1
        if SIDE:
            x = state.my_position.x
            y = state.my_position.y

            state.board[y][x] = ECell.YellowWall if MY_SIDE == 'Yellow' else ECell.BlueWall
            state.my_direction = direction

            pos = dir_to_pos(direction)
            x += pos.x
            y += pos.y

            # update state
            state.my_position = Position(x, y)
            if state.board[y][x] == ECell.AreaWall:
                state.my_health = 0
                state.my_score += self.world.constants.area_wall_crash_score

            if activate_wallbreaker == 1:  # activated wallbreaker
                state.my_rem_time = self.world.constants.wall_breaker_duration
                state.my_cool_time = self.world.constants.wall_breaker_cooldown
                state.my_score += self.world.constants.wall_score_coefficient

            else:
                if state.my_rem_time > 0:  # wallbreaker active
                    state.my_rem_time -= 1
                elif state.my_cool_time > 0:  # wallbreaker deactivate
                    state.my_cool_time -= 1

                    if state.board[y][x] == ECell.BlueWall and MY_SIDE == "Yellow":
                        state.my_health -= 1
                        state.my_score += self.world.constants.enemy_wall_crash_score
                    elif state.board[y][x] == ECell.YellowWall and MY_SIDE == "Blue":
                        state.my_health -= 1
                        state.my_score += self.world.constants.enemy_wall_crash_score
                    elif state.board[y][x] == ECell.YellowWall and MY_SIDE == "Yellow":
                        state.my_health -= 1
                        state.my_score += self.world.constants.my_wall_crash_score
                    elif state.board[y][x] == ECell.BlueWall and MY_SIDE == "Blue":
                        state.my_health -= 1
                        state.my_score += self.world.constants.my_wall_crash_score

        else:
            x = state.other_position.x
            y = state.other_position.y

            state.board[y][x] = ECell.YellowWall if OTHER_SIDE == 'Yellow' else ECell.BlueWall
            state.other_direction = direction

            pos = dir_to_pos(direction)
            x += pos.x
            y += pos.y

            # update state
            state.other_position = Position(x, y)
            if state.board[y][x] == ECell.AreaWall:
                state.other_health = 0
                state.other_score += self.world.constants.area_wall_crash_score

            if activate_wallbreaker == 1:  # activated wallbreaker
                state.other_rem_time = self.world.constants.wall_breaker_duration
                state.other_cool_time = self.world.constants.wall_breaker_cooldown
                state.other_score += self.world.constants.wall_score_coefficient

            else:
                if state.other_rem_time > 0:  # wallbreaker active
                    state.other_rem_time -= 1
                elif state.other_cool_time > 0:  # wallbreaker deactivate
                    state.other_cool_time -= 1

                    if state.board[y][x] == ECell.BlueWall and OTHER_SIDE == "Yellow":
                        state.other_health -= 1
                        state.other_score += self.world.constants.enemy_wall_crash_score
                    elif state.board[y][x] == ECell.YellowWall and OTHER_SIDE == "Blue":
                        state.other_health -= 1
                        state.other_score += self.world.constants.enemy_wall_crash_score
                    elif state.board[y][x] == ECell.YellowWall and OTHER_SIDE == "Yellow":
                        state.other_health -= 1
                        state.other_score += self.world.constants.my_wall_crash_score
                    elif state.board[y][x] == ECell.BlueWall and OTHER_SIDE == "Blue":
                        state.other_health -= 1
                        state.other_score += self.world.constants.my_wall_crash_score

    def minimax(self, board, depth, alpha, beta, maximizingPlayer):
        valid_directions = self.valid_dirs(board, 1 if maximizingPlayer else 0)
       # print(self.winning_move(board))
        is_terminal = self.is_terminal_node(board)
        if depth == 0 or is_terminal:
            if is_terminal:
                if self.winning_move(board) > 0:
                    return None, 100000000000000
                elif self.winning_move(board) < 0:
                    return None, -100000000000000
                else:  # Game is over, no more valid moves
                    return None, 0
            else:  # Depth is zero
                return None, self.winning_move(board)
        if maximizingPlayer:
            print(valid_directions)
            value = -math.inf
            column = random.choice(valid_directions)
            for action in valid_directions:
                board_copy = cp.deepcopy(board)
                self.do_action(board_copy, action, 1, self.my_side, self.other_side)
                new_score = self.minimax(board_copy, depth - 1, alpha, beta, False)[1]
                if new_score > value:
                    value = new_score
                    column = action
                alpha = max(alpha, value)
                if alpha >= beta:
                    break
            return column, value

        else:  # Minimizing player
            value = math.inf
            if len(valid_directions) > 0:
                column = random.choice(valid_directions)
            for action in valid_directions:
                board_copy = cp.deepcopy(board)
                self.do_action(board_copy, action, 0, self.my_side, self.other_side)
                new_score = self.minimax(board_copy, depth - 1, alpha, beta, True)[1]
                if new_score < value:
                    value = new_score
                    column = action
                beta = min(beta, value)
                if alpha >= beta:
                    break
            return column, value

    def decide(self):
        agent = self.world.agents[self.my_side]
        other = self.world.agents[self.other_side]
        print(self.state.my_score, self.state.other_score)
        state = State(self.world.board, len(self.world.board[0]),
                      len(self.world.board), agent.direction, other.direction,
                      agent.wall_breaker_rem_time, other.wall_breaker_rem_time,
                      agent.wall_breaker_cooldown, other.wall_breaker_cooldown,
                      agent.health, other.health,
                      agent.position, other.position,
                      self.world.constants.max_cycles * 2, self.world.scores[self.my_side] +
                      (agent.health * self.world.constants.my_wall_crash_score),
                      self.world.scores[self.other_side] +
                      (other.health * self.world.constants.my_wall_crash_score))

        print('decide')
        # action, value = self.minimax(state, 6, -math.inf, math.inf, True)
        # direction, activate = action
        best, value = self.genetic_algorithm(state, 0.01, 0.9, 6, 1000, 100)
        direction, activate = best[0]
        # print(action, value)
        print(best[0], value)
        if activate:
            self.send_command(ActivateWallBreaker())
        self.send_command(ChangeDirection(direction))


if __name__ == '__main__':
    pass
