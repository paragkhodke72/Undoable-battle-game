#ifndef ENUMS_H
#define ENUMS_H
using namespace std;

enum class ActorType {
    Ghost,
    Knight,
    Warrior
    
};

string ActorTypeStrings[] = {
    "ghosts",
    "knights",
    "warriors"
    
};
enum class MoveType { FirstAttack, SecondAttack, Heal };
string MoveTypeStrings[] = {
    "FirstOnes",
    "AttackTwos",
    "Healing with"
    
};



#endif
