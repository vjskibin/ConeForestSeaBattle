#include <iostream>
#include <termios.h>
#include <stdio.h>
#include "../model/Player.h"
#include "../model/Battle.h"
#include "../model/UI.h"
#include "../model/Keyboard.h"


using namespace std;


//cross platform getch() function
void resetTermios();
char getch_(int);
char getch(); //without echo
char getche(); //with echo
//------------------------------


int main()
{
    setlocale(LC_ALL, "");
    srand(time(NULL));

    cout << "Start a new game? [Press y/n]" << endl;
    char c = Keyboard::getche();
    if (c == 'n' || c == 'N') return 0;
    UI::clearScreen();

    Player player("human"), computer("AI");
    std::cout << std::endl << "Press any key to continue..." << std::endl;
    Keyboard::getch();

    UI::clearScreen();

    Battle battle;

    battle.initPlayers(player,computer);
    battle.prepareForBattle();
    battle.startBattle();
    battle.showStats();


    Keyboard::getch();
    return 0;
}


