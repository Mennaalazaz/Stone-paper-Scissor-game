#include <iostream>
#include <cstdlib>
using namespace std;

enum enGame { Stone = 1, Paper = 2, Scissor = 3 };

struct stGame {
    int ComputerScore = 0;
    int PersonScore = 0;
    int DrawScore = 0;
};

// Prototype For Functions Here
short ReadNumber(string message); 
int RandomNumber(int from, int to); 
string GetChoices(enGame Choices); 
string GameRules(stGame& game, enGame Computer, enGame Person); 
string FinalWinner(stGame game); 
string  Tabs(short NumberOfTabs);
void ResultGame(stGame Game, short roundNumbers); 
void PlayOneRound(short roundNumbers, stGame& game);
void StartGame( short roundNumbers);

int main() {

    srand((unsigned)time(NULL));

    StartGame(ReadNumber("How many Rounds 1 to 10 ?"));
    return 0;
}

// Implementations of the functions here
short ReadNumber(string message) {
    short number;
    do {
        cout << message << endl;
        cin >> number;
    } while (number < 1 || number > 10);
    return number;
}

int RandomNumber(int from, int to) {
    int randNum = rand() % (to - from + 1) + from;
    return randNum;
}

string GetChoices(enGame Choices) {
    switch (Choices) {
    case enGame::Paper: return "Paper";
    case enGame::Stone: return "Stone";
    case enGame::Scissor: return "Scissor";
    default: return ""; // Added a default return to prevent compiler warnings.
    }
}

string GameRules(stGame& game, enGame Computer, enGame Person) {
    if ((Person == enGame::Stone && Computer == enGame::Scissor) ||
        (Person == enGame::Paper && Computer == enGame::Stone) ||
        (Person == enGame::Scissor && Computer == enGame::Paper)) {

        system("color 2f"); // Turn Screen Green
        game.PersonScore++;
        return "Person wins";
    }
    else if ((Computer == enGame::Stone && Person == enGame::Scissor) ||
        (Computer == enGame::Paper && Person == enGame::Stone) ||
        (Computer == enGame::Scissor && Person == enGame::Paper)) {

        system("color 4f"); // Turn Screen Red
        cout << "\a";      // Produce Alert Sound
        game.ComputerScore++;
        return "Computer wins";
    }
    else {
        system("color 6f");  // Turn Screen Yellow
        game.DrawScore++;
        return "No winner";
    }
}

string FinalWinner(stGame game) {
    if (game.ComputerScore > game.PersonScore) return "Computer";
    else if (game.PersonScore > game.ComputerScore) return "Person";
    else return "No winner";
}

string  Tabs(short NumberOfTabs) {
    string t = "";
    for (int i = 1; i < NumberOfTabs; i++) {
      t = t + "\t";       
      cout << t;
}
return t; 
}

void ResultGame(stGame Game, short roundNumbers) {
    cout << Tabs(2)<< "---------------------------------------------------------------" << endl;
    cout << Tabs(2) << "             + + +  G a m e  O v e r  + + +                    " << endl;
    cout << Tabs(2) << "---------------------------------------------------------------" << endl;
    cout << Tabs(2) << "------------------    [Game Results]     ----------------------" << endl;
    cout << Tabs(2) << "Game Rounds " << roundNumbers << endl;
    cout << Tabs(2) << "Player won times " << Game.PersonScore << endl;
    cout << Tabs(2) << "Computer won times " << Game.ComputerScore << endl;
    cout << Tabs(2) << "Draw Times " << Game.DrawScore << endl;
    cout << Tabs(2) << "Final Winner " << FinalWinner(Game) << endl;
    cout << Tabs(2) << "---------------------------------------------------------------" << endl;
    system("color 07"); // Reset the console color to default.
    cout << Tabs(2) << "Do you want to play again [1]Yes / [2]No?" << endl;
    int choice;
    cin >> choice;
    switch (choice) {
    case 1: {
        stGame anotherGame;
        StartGame(ReadNumber("How many Rounds 1 to 10 ?"));
        break; 
    }
    case 2:
        break;
    }
}

void PlayOneRound(short NumberOfRound, stGame& game) {
    int Choice = 0;
    enGame Computer;
    enGame Person;

    cout << "Round[" << NumberOfRound << "] begins:" << endl;

    do {
        cout << "Your Choice: [1]Stone [2]Paper [3]Scissor ?" << endl;
        cin >> Choice;
    } while (Choice < 1 || Choice > 3);

    Person = enGame(Choice);
    Computer = enGame(RandomNumber(1, 3));

    cout << "\n -------------Round[" << NumberOfRound << "]-------------\n";
    cout << "Player Choice: " << GetChoices(Person) << endl;
    cout << "Computer Choice: " << GetChoices(Computer) << endl;
    cout << "Round Winner: " << GameRules(game, Computer, Person) << endl;
}

void StartGame(short roundNumbers) {
    stGame Game;
    for (short i = 1; i <= roundNumbers; i++) {
        PlayOneRound(i, Game);
    }
    ResultGame(Game, roundNumbers);
}


