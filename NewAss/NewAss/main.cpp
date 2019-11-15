// This is undoubale battle application using templates,stack by parag khodke.
// This program has some Validation if user enteres invalid choide from the options as well.
// Operator overloading is used here to print the data..
// Templates and stack is also used in this applications.
// Command pttern is also used in this program

#include <iostream>
#include "Runner.hpp"

using namespace std;

int main() {
  string userName;
  cout<<"Kindly Enter Your Name to play Undoable battle game ??\n";
    getline(cin, userName);
  cout<<"\nHello  "<< userName <<",.. Welcome to Undoable Battle Game by Parag_Khodke\n";
  RunUndoableGame().run_Undoable_Battle_Game();
  cout<<"\nplease try again with another battle game\n\n\nThank you for using Undoable battle Game\n\n";
  return 0;
}
