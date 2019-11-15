#ifndef BATTLE_MOVE_FACTORY_H
#define BATTLE_MOVE_FACTORY_H

class MoveFactory {
  public:
  static BattleMove* BuildMove(MoveType type, Actor* self, Actor* other) {
  BattleMove* move;
  
  switch(type){
  
      case MoveType::FirstAttack:
      move =  new AttackOne(self, other);
      break;
    
      case MoveType::SecondAttack:
      move = new AttackTwo(self, other);
      break;
    
      case MoveType::Heal:
      move =  new Heal(self, other);
      break;
    
      default:
      throw "\n\nInvalid Move.";
            
  }
            return move; 
        }
};

#endif
