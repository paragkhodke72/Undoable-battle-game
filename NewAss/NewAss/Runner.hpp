#ifndef RUNNER_H
#define RUNNER_H

class Actor;
using namespace std;

#include "enums.hpp"
#include "BattleMove.hpp"
#include "MoveManager.hpp"
#include "MoveFactory.hpp"
#include "Actor.hpp"
#include "ActorFactory.hpp"
#include "Actor.cpp"
#include "BattleMove.cpp"

class RunUndoableGame
{
    public:
        void run_Undoable_Battle_Game();
};

#include "Runner.cpp"

#endif
