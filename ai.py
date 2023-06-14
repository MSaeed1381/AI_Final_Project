# -*- coding: utf-8 -*-
# python imports
import math
import random

# chillin imports
from chillin_client import RealtimeAI
import numpy as np

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
            elif self.world.board[x][y + 1] == ECell.BlueWall and \
                my_team == "Yellow" and agent.wall_breaker_rem_time > 0:
                score = self.world.constants.coefficient_score_wall * 2
            elif self.world.board[x][y + 1] == ECell.BlueWall and \
                my_team == "Yellow" and agent.wall_breaker_rem_time <= 0:
                score = self.world.constants.coefficient_score_wall
            elif self.world.board[x][y + 1] == ECell.YellowWall and \
                my_team == "Blue" and agent.wall_breaker_rem_time > 0:
                score = self.world.constants.coefficient_score_wall * 2
            elif self.world.board[x][y + 1] == ECell.YellowWall and \
                my_team == "Blue" and agent.wall_breaker_rem_time <= 0:
                score = self.world.constants.coefficient_score_wall
                ######### this state for collision of two agent 
            elif  self.world.board[x][y + 1] == self.my_side==self.other_side:
                 score = -self.world.constants.area_wall_crash_score

            return score

        if dir.Down:
            if self.world.board[x][y - 1] == ECell.Empty :
                score = self.world.constants.coefficient_score_wall
            elif self.world.board[x][y - 1] == ECell.AreaWall:
                score = -self.world.constants.area_wall_crash_score
            elif self.world.board[x][y - 1] == ECell.BlueWall and \
                my_team == "Yellow" and agent.wall_breaker_rem_time > 0:
                score = self.world.constants.coefficient_score_wall * 2
            elif self.world.board[x][y - 1] == ECell.BlueWall and \
                my_team == "Yellow" and agent.wall_breaker_rem_time <= 0:
                score = self.world.constants.coefficient_score_wall
            elif self.world.board[x][y - 1] == ECell.YellowWall and \
                my_team == "Blue" and agent.wall_breaker_rem_time > 0:
                score = self.world.constants.coefficient_score_wall * 2
            elif self.world.board[x][y - 1] == ECell.YellowWall and \
                my_team == "Blue" and agent.wall_breaker_rem_time <= 0:
                score = self.world.constants.coefficient_score_wall
                ######### this state for collision of two agent 
            elif  self.world.board[x][y - 1] == self.my_side==self.other_side:
                 score = -self.world.constants.area_wall_crash_score    

            return score


        if dir.Right:
            if self.world.board[x + 1][y] == ECell.Empty :
                score = self.world.constants.coefficient_score_wall
            elif self.world.board[x + 1][y] == ECell.AreaWall:
                score = -self.world.constants.area_wall_crash_score
            elif self.world.board[x + 1][y] == ECell.BlueWall and \
                my_team == "Yellow" and agent.wall_breaker_rem_time > 0:
                score = self.world.constants.coefficient_score_wall * 2
            elif self.world.board[x + 1][y] == ECell.BlueWall and \
                my_team == "Yellow" and agent.wall_breaker_rem_time <= 0:
                score = self.world.constants.coefficient_score_wall
            elif self.world.board[x + 1][y] == ECell.YellowWall and \
                my_team == "Blue" and agent.wall_breaker_rem_time > 0:
                score = self.world.constants.coefficient_score_wall * 2
            elif self.world.board[x + 1][y] == ECell.YellowWall and \
                my_team == "Blue" and agent.wall_breaker_rem_time <= 0:
                score = self.world.constants.coefficient_score_wall
                ######### this state for collision of two agent 
            elif  self.world.board[x + 1][y] == self.my_side==self.other_side:
                 score = -self.world.constants.area_wall_crash_score    

            return score
        
        if dir.Left:
            if self.world.board[x - 1][y] == ECell.Empty :
                score = self.world.constants.coefficient_score_wall
            elif self.world.board[x - 1][y] == ECell.AreaWall:
                score = -self.world.constants.area_wall_crash_score
            elif self.world.board[x - 1][y] == ECell.BlueWall and \
                my_team == "Yellow" and agent.wall_breaker_rem_time > 0:
                score = self.world.constants.coefficient_score_wall * 2
            elif self.world.board[x - 1][y] == ECell.BlueWall and \
                my_team == "Yellow" and agent.wall_breaker_rem_time <= 0:
                score = self.world.constants.coefficient_score_wall
            elif self.world.board[x - 1][y] == ECell.YellowWall and \
                my_team == "Blue" and agent.wall_breaker_rem_time > 0:
                score = self.world.constants.coefficient_score_wall * 2
            elif self.world.board[x - 1][y] == ECell.YellowWall and \
                my_team == "Blue" and agent.wall_breaker_rem_time <= 0:
                score = self.world.constants.coefficient_score_wall
                ######### this state for collision of two agent 
            elif  self.world.board[x - 1][y] == self.my_side==self.other_side:
                 score = -self.world.constants.area_wall_crash_score  

        return score

        
    def alpha_beta_cutoff(self):    
             max_val = -np.inf
             



        
    def decide(self):
        print('decide')
        alpha = -math.inf
        beta = math.inf
        limit = 3
        # self.send_command(ChangeDirection(EDirection.Left))

        if self.world.agents[self.my_side].wall_breaker_cooldown == 0:
            self.send_command(ActivateWallBreaker())