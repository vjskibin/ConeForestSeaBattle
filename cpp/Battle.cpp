//
// Created by vitaly on 18.03.19.
//

#include "../model/Battle.h"
#include "../model/UI.h"
#include "../model/Keyboard.h"

Battle::Battle() {
    this->turn = 0;
}

Battle::Battle(Player & player, Player & enemy) {
    this->turn = 0;
    this->player = &player;
    this->enemy = &enemy;
}

void Battle::initPlayers(Player & player, Player & enemy) {
    this->player = &player;
    this->enemy = &enemy;
}


void Battle::prepareForBattle() {
    player->fillArea();
    enemy->fillArea();
}

void Battle::playerTurn() {
    int x,y;
    bool turnAgain = true;
    do {
        player->areaNavigate(x,y);
        player->attack(*enemy,x,y,turnAgain);
    } while (turnAgain);

}

void Battle::enemyTurn() {
    int x = 1,y = 1;
    bool turnAgain = true;
    do {
        enemy->areaNavigate(x,y);
        enemy->attack(*player,x,y,turnAgain);
    } while (turnAgain);

}


void Battle::startBattle() {
    UI::clearScreen();
    std::cout << "Press any key to start the battle..." << std::endl;
    Keyboard::getch();

    do
    {
        playerTurn();
        if (enemy->getAliveShipsCount() < 1)
        {
            showStats(*player);
            break;
        }


        enemyTurn();
        if(player->getAliveShipsCount() < 1)
        {
            showStats(*enemy);
            break;
        }

    } while(true);


}

void Battle::showStats(Player & player) {
    UI::clearScreen();
    std::cout << player.getName() << " won this battle! Congratulations!" << std::endl;
    Keyboard::getch();
}

void Battle::incTurn() {
    this->turn++;
}

void Battle::finish() {
}





