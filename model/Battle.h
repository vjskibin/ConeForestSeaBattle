//
// Created by vitaly on 18.03.19.
//

#ifndef CONEFORESTSEABATTLE_BATTLE_H
#define CONEFORESTSEABATTLE_BATTLE_H

#include "Player.h"

class Battle {

private:
    int turn;
    Player *player;
    Player *enemy;
public:
    Battle();
    Battle(Player &, Player &);
    void initPlayers(Player &, Player &);
    void prepareForBattle();

    void incTurn();

    void playerTurn();
    void enemyTurn();

    void startBattle();
    void showStats(Player &);
    void finish();
};


#endif //CONEFORESTSEABATTLE_BATTLE_H
