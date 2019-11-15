
#ifndef ACTOR_FACTORY_H
#define ACTOR_FACTORY_H

class ActorFactory {
  public:
  static Actor* CreateActorFactory(ActorType actor) {

   switch(actor) {
    case ActorType::Ghost:
        return new Ghost;
    case ActorType::Knight:
        return new Knight;
    case ActorType::Warrior:
        return new Warrior;
    default:
        throw "\n\n\t\tOho !! Non-existent move Entered";
   }
 }
};
#endif
