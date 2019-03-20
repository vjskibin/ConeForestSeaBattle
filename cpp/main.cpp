#include <iostream>
#include <termios.h>
#include <stdio.h>
#include "../model/Player.h"
#include "../model/Battle.h"
#include "../model/UI.h"
#include "../model/Keyboard.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    srand(time(NULL));
    char goGame = '0';

    while(goGame != '3')
    {
        UI::showMenu(goGame);
        if(goGame == '1')
        {
            Battle battle;

            Player player("human"), computer("AI");
            battle.initPlayers(player,computer);

            battle.prepareForBattle();
            battle.startBattle();
            battle.finish();
        }

    }

    return 0;
}


