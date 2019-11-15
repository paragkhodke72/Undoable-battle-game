
void RunUndoableGame::run_Undoable_Battle_Game() {
    char inputData;
    cout<<"\n-------------------------------------------------------------";
    cout << "\n\t\tKinly first Select Your Player:" << '\n';
    cout << "\t\t1) Ghost" << '\n';
    cout << "\t\t2) Knight" << '\n';
    cout << "\t\t3) Warrior" << '\n';
    cout<<"-------------------------------------------------------------\n\n\n";
    cin >> inputData;

    while(not isdigit(inputData)) {
        if ('1' <= inputData and inputData <= '3')
            break;
        
        cout << "\nOppose!!! please enter again With valid options selections: \n";
        cin >> inputData;
    }

    cout << "\nKindly check your selection optios is: -->  " << ActorTypeStrings[inputData-'0'-1] << "\n"<< '\n';// checking for correct input data

    Actor* ActorObjectCallPlayer = ActorFactory::CreateActorFactory(ActorType(inputData-'0'-1));
    cout<<"\n\n-------------------------------------------------------------";
    cout << "\nNow, Kindly Select Your Opponent to play this battle:" << '\n';
    cout << "1) Ghost" << '\n';
    cout << "2) Knight" << '\n';
    cout << "3) Warrior" << '\n';
    cout<<"-------------------------------------------------------------\n\n";
    cin >> inputData;

    while(not isdigit(inputData)) {
        if ('1' <= inputData and inputData <= '3')
            break;
        
        cout << "\nOppse !! Invalid choice !! please enter again: \n";
        cin >> inputData;
    }

    cout << "\nKindly check that you have choose your opponent as : -->   " << ActorTypeStrings[inputData-'0'-1] << '\n';
    
    Actor* ActorObjectCallOpponent = ActorFactory::CreateActorFactory(ActorType(inputData-'0'-1));

    cout << "\n\nNow We are ready to play this ballte.You VS Opponent\n\nYou --> \t " << (*ActorObjectCallPlayer) << " \nOpponents--> " << (*ActorObjectCallOpponent) << "\n";
   
    MoveManager moveManagerObject;

    while (not (*ActorObjectCallPlayer).ActorisDead() and not (*ActorObjectCallOpponent).ActorisDead()) {

        cout<<"\n\n\n-------------------------------------------------------------";
        cout << "\nNow Kindly Choose Your move from Following options:" << '\n';
        cout << "1) Move P1 -> P2" << '\n';
        cout << "2) Move P2 -> P1" << '\n';
        cout << "3) Undo Last Move" << '\n';
        cout<<"-------------------------------------------------------------\n";
        cin >> inputData;

        while(not isdigit(inputData)) {
            if ('1' <= inputData and inputData <= '3')
                break;
            
            cout << "\nOpppse !!! Invalid.. unknown move, please enter again: \n";
            cin >> inputData;
        }

        int r = rand()%(3);

        if (inputData == '1')
            (*ActorObjectCallPlayer).ActordoMove(moveManagerObject, MoveType(r), ActorObjectCallOpponent);
        else if (inputData == '2')
            (*ActorObjectCallOpponent).ActordoMove(moveManagerObject, MoveType(r), ActorObjectCallPlayer);
        else  {
            try {
                moveManagerObject.UndoLastMove();
            }
            catch(const char* & execute) {
                cout << execute << '\n';
            }
        }
        cout <<"Now Remaning health as following.\n"<< (*ActorObjectCallPlayer) << " and -->" << (*ActorObjectCallOpponent) << "  \n";
    }


}
