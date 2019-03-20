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
    player->areaNavigate(x,y);
    player->attack(*enemy,x,y);
}

void Battle::enemyTurn() {
    int x,y;
    enemy->areaNavigate(x,y);
    enemy->attack(*player,x,y);
}


void Battle::startBattle() {
    UI::clearScreen();
    std::cout << "Press any key to start the battle..." << std::endl;
    Keyboard::getch();



    do
    {
        playerTurn();
        enemyTurn();
    } while(enemy->getAliveShipsCount() > 0 && player -> getAliveShipsCount() > 0);


}

void Battle::showStats() {

}

void Battle::incTurn() {
    this->turn++;
}





