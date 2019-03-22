//
// Created by vitaly on 18.03.19.
//

#ifndef CONEFORESTSEABATTLE_AI_H
#define CONEFORESTSEABATTLE_AI_H


#include "Player.h"

class AI {
private:
    Player player;

    static void findUnknownCellNearby(Player &, int, int, int *);
    static bool unknownCellsNearby(Player &, int, int);
    static bool nicePlace(Player &, int headX, int headY, int length, bool rot);
public:

    static void recommendHitForPlayer(Player &, int *);
    static void recommendAndSetShipPlacement(Player &, int len, int id);

};


#endif //CONEFORESTSEABATTLE_AI_H
