#ifndef BATTLE_MOVE_H
#define BATTLE_MOVE_H

class Move {
	public:
        void virtual undoAction() = 0;
		void virtual executeAction() = 0;
};

class BattleMove : public Move {// Move that can either hurt the opponent, or heal the player
    protected:
        Actor* selfAction;
        Actor* otherAction;

    public:
		BattleMove(Actor * s, Actor * o);
    
};

class AttackOne : public BattleMove {// Move that generate a random damage between 10 and 15
    private:
        int amount;

    public:
		AttackOne(Actor * s, Actor * o);
		void executeAction();
		void undoAction();
	
};

class AttackTwo : public BattleMove {// Move that generate a random damage between 0 and 25
    private:
        int amount;

    public:
		AttackTwo(Actor * s, Actor * o);
		void executeAction();
		void undoAction();
	
};

class Heal : public BattleMove {// Move that generate a random heal amount between 10 and 15

    private:
        int amount;
    public:
		Heal(Actor * s, Actor * o);
		void executeAction();
		void undoAction();
	
};

#endif
