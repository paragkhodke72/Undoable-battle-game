#ifndef Actor_H
#define Actor_H

#include <vector>
using namespace std;
class Actor {
    protected:
        int Actorhealth;
        string Actortype;
        vector<MoveType> Actormoves;
        friend std::ostream & operator<< (std::ostream & out, const Actor & act);
    
	public:
		Actor(int h, std::string s);
		Actor(const Actor & act);
		Actor & operator= (const Actor & act);
		void ActordoMove(MoveManager & mgr, const MoveType & moveType, Actor * other );
		void Actorhit(int damageAmount);// actor is damageAmountd by certain amount
		void Actorheal(int amount);// actor is healed by certain amount
		const std::vector<MoveType> & getMovesForActor() const;// list of battle moves
		bool ActorisDead() const;// checks if the actor is dead
    
};

class Ghost : public Actor {
	public:
    Ghost(int h = 100, std::string t = "Ghost") : Actor(h, t) { // Game character with 100hp and AttackOne, Heal battle moves
			Actormoves.push_back(MoveType::FirstAttack);
			Actormoves.push_back(MoveType::Heal);
		}
};

class Knight : public Actor {
	public:
		Knight(int h = 100, std::string t = "Knight") : Actor(h, t) {
			Actormoves.push_back(MoveType::FirstAttack);
			Actormoves.push_back(MoveType::Heal);
		}
};

class Warrior : public Actor {
	public:
		Warrior(int h = 100, std::string t = "Warrior") : Actor(h, t) {// Game character with 100hp and AttackOne, AttackTwo battle moves
			Actormoves.push_back(MoveType::FirstAttack);
			Actormoves.push_back(MoveType::SecondAttack);
		}
};

#endif
