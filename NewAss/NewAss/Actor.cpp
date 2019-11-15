// operator overloading used here.....
ostream & operator<< (ostream & printingData, const Actor & ActorAction) {
    printingData << ActorAction.Actortype << ", (" << to_string(ActorAction.Actorhealth) << ")";
    return printingData;
}

void Actor::Actorhit(int damage) {
    cout <<"\n\n"<< (*this) << " attatck and amount of damage is --> (" << damage << ") \n\n\n";
    Actorhealth -= damage;
}

void Actor::Actorheal(int amount) {
    cout << (*this) << "  heal by the amount--> --> (" << amount << ") \n\n\n";
    Actorhealth += amount;
}


void Actor::ActordoMove(MoveManager & movemanager, const MoveType & moveType, Actor * otherActor )  {
    cout<<"\n\n" << Actortype << " (" << Actorhealth << ") chooses --> " << MoveTypeStrings[(int)moveType] << '\n';
    movemanager.ExecuteMove(MoveFactory::BuildMove(moveType, this, otherActor));
}

Actor & Actor::operator= (const Actor & ActorAction) {
    Actorhealth = ActorAction.Actorhealth;
    Actortype = ActorAction.Actortype;
    Actormoves = ActorAction.Actormoves;
    return *this;
}

Actor::Actor(int h, string t) : Actorhealth(h), Actortype(t) {
}

Actor::Actor(const Actor & ActorAction) : Actorhealth(ActorAction.Actorhealth), Actortype(ActorAction.Actortype), Actormoves(ActorAction.Actormoves) {
}

const vector<MoveType> & Actor::getMovesForActor() const {
    return Actormoves;
}

bool Actor::ActorisDead() const {
    return Actorhealth <= 0;
}
