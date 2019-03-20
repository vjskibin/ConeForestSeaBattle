#include <iostream>
#include <termios.h>
#include <stdio.h>
#include "../model/Player.h"
#include "../model/Battle.h"
#include "../model/UI.h"
#include "../model/Keyboard.h"

#ifdef _WIN32
#include <windows.h>
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

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
    cout << "Start a new game? [Press y/n]" << endl;
    char c = Keyboard::getche();
    if (c == 'n' || c == 'N') return 0;
    system(CLEAR);
    srand(time(NULL));
    Player player("human"), computer("AI");


    UI::clearScreen();

    Battle battle;
    battle.initPlayers(player,computer);
    battle.prepareForBattle();
    Keyboard::getch();
    return 0;
}


