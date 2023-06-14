# -*- coding: utf-8 -*-
# python imports
import math
import random

# chillin imports
from chillin_client import RealtimeAI

# project imports
from ks.models import ECell, EDirection, Position
from ks.commands import ChangeDirection, ActivateWallBreaker


class AI(RealtimeAI):

    def __init__(self, world):
        super(AI, self).__init__(world)

    def initialize(self):
        print('initialize')

    def valids(self):
        agent = self.world.agents[self.my_side]
        valid_moves = []
        for move in EDirection:
            if self.valid_dir(move):
                valid_moves.append(move)

    def valid_dir(self, dir:EDirection):
        agent = self.world.agents[self.my_side]
        my_team = self.my_side
        x =  agent.position.x
        y =  agent.position.y
        score = 0
        if dir.Up:
            if self.world.board[x][y + 1] == ECell.Empty :
                score = self.world.constants.coefficient_score_wall
            elif self.world.board[x][y + 1] == ECell.AreaWall:
                score = -self.world.constants.area_wall_crash_score
            elif self.world.board[x][y + 1] == ECell.BlueWall and my_team == "Yellow" and agent.wall_breaker_rem_time > 0:
                score = self.world.constants.coefficient_score_wall * 2
            elif self.world.board[x][y + 1] == ECell.BlueWall and my_team == "Yellow" and agent.wall_breaker_rem_time <= 0:
                score = self.world.constants.coefficient_score_wall
        # elif dir.Down:
        #     if self.world.board[x][y - 1] == ECell.Empty:
        #         return True, self.world.constants.coefficient_score_wall
        # elif dir.Right:
        #     if self.world.board[x + 1][y] == ECell.Empty:
        #         return True, self.world.constants.coefficient_score_wall
        # else:
        #     if self.world.board[x - 1][y] == ECell.Empty:
        #         return True, self.world.constants.coefficient_score_wall
        return score


    # def valid_dir_with_wallbreaker(self, dir:EDirection):
    #     agent = self.world.agents[self.my_side]
    #     x =  agent.position.x
    #     y =  agent.position.y
    #     if dir.Up:
    #         if self.world.board[x][y + 1] != ECell.Empty and agent.wall_breaker_rem_time > 0:
    #             return True
    #     elif dir.Down:
    #         if self.world.board[x][y - 1] != ECell.Empty and agent.wall_breaker_rem_time > 0:
    #             return True
    #     elif dir.Right:
    #         if self.world.board[x + 1][y] != ECell.Empty and agent.wall_breaker_rem_time > 0:
    #             return True
    #     else:
    #         if self.world.board[x - 1][y] != ECell.Empty and agent.wall_breaker_rem_time > 0:
    #             return True
    #     return False

    def decide(self):
        print('decide')
        alpha = -math.inf
        beta = math.inf
        limit = 3
        # self.send_command(ChangeDirection(EDirection.Left))

        if self.world.agents[self.my_side].wall_breaker_cooldown == 0:
            self.send_command(ActivateWallBreaker())
