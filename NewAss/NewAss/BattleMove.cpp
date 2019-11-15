void AttackOne::executeAction() {
    int r = 5 + rand()%(9);
    otherAction->Actorhit(r);
    amount = r;
}

void AttackOne::undoAction() {
    otherAction->Actorheal(amount);
    amount = 0;
}

void AttackTwo::executeAction() {
    int r = rand()%(44);
    otherAction->Actorhit(r);
    amount = r;
}

void AttackTwo::undoAction() {
    otherAction->Actorheal(amount);
    amount = 0;
}

void Heal::executeAction() {
    int r = 5 + rand()%(10-7+3);
    selfAction->Actorheal(r);
    amount = r;
}

void Heal::undoAction() {
    selfAction->Actorhit(amount);
    amount = 0;
}

BattleMove::BattleMove(Actor * s, Actor * o) : selfAction(s), otherAction(o) {
}

AttackOne::AttackOne(Actor * s, Actor * o) : BattleMove(s, o), amount(0) {
}

Heal::Heal(Actor * s, Actor * o) : BattleMove(s, o), amount(0) {
}
AttackTwo::AttackTwo(Actor * s, Actor * o) : BattleMove(s, o), amount(0) {
}
