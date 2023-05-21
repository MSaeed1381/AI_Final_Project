#include "ai.h"

#include <iostream>
#include <vector>
#include <map>

#include "effolkronium/random.hpp"

using namespace std;
using Random = effolkronium::random_static;

using namespace koala::chillin::client;
using namespace ks::models;
using namespace ks::commands;


AI::AI(World *world): RealtimeAI<World*>(world)
{
}

AI::~AI()
{
}

void AI::initialize()
{
    cout << "initialize" << endl;
}

void AI::decide()
{
    cout << "decide" << endl;

    auto randomDirection = Random::get(
        {EDirection::Up, EDirection::Right, EDirection::Down, EDirection::Left}
    );
    changeDirection(randomDirection);

    if (this->world->agents()[this->mySide].wallBreakerCooldown() == 0)
        activateWallBreaker();
}


void AI::changeDirection(EDirection direction)
{
    ChangeDirection cmd;
    cmd.direction((ECommandDirection) direction);
    this->sendCommand(&cmd);
}

void AI::activateWallBreaker()
{
    ActivateWallBreaker cmd;
    this->sendCommand(&cmd);
}
