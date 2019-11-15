#ifndef MOVE_MANAGER
#define MOVE_MANAGER


// #include "Stack.hpp"
#include "LStack.hpp"

class MoveManager : public Stack<Move*> {  // change to Stack<Move*>
    
    public:
    void UndoLastMove() {// undo the last move in the stack
               this->top()->undoAction();
               this->popStack();
    }
    
    void ExecuteMove(Move* moveAction) { // takes a move as argument and push into the stack
            moveAction->executeAction();
            this->pushStack(moveAction);
    }

       
};

#endif
