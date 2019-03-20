//
// Created by vitaly on 18.03.19.
//

#include "../model/Battle.h"

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
}

void Battle::startBattle() {

}

void Battle::showStats() {

}




