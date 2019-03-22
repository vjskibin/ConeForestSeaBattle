//
// Created by vitaly on 18.03.19.
//

#include "../model/AI.h"
#include "../model/Keyboard.h"
#include "../model/UI.h"

void AI::findUnknownCellNearby(Player & player, int i, int j, int * recommendedHit)
{
    if(player.getEnemyCellInfo(i + 1, j) == Player::UNKNOWN_CODE)
    {
        recommendedHit[0] = i + 1;
        recommendedHit[1] = j;
        std::cout << std::endl << "i+1: " << i + 1 << " j: " << j << std::endl;
    }

    else if(player.getEnemyCellInfo(i - 1, j) == Player::UNKNOWN_CODE)
    {
        recommendedHit[0] = i - 1;
        recommendedHit[1] = j;
        std::cout << std::endl << "i-1: " << i - 1 << " j: " << j << std::endl;
    }

    else if(player.getEnemyCellInfo(i, j + 1) == Player::UNKNOWN_CODE)
    {
        recommendedHit[0] = i;
        recommendedHit[1] = j + 1;
        std::cout << std::endl << "i: " << i << " j + 1: " << j + 1 << std::endl;
    }

    else if(player.getEnemyCellInfo(i, j - 1) == Player::UNKNOWN_CODE)
    {
        recommendedHit[0] = i;
        recommendedHit[1] = j - 1;
        std::cout << std::endl << "i: " << i + 1 << " j - 1: " << j - 1 << std::endl;
    }
}

bool AI::unknownCellsNearby(Player & player,int i, int j)
{
    return (player.getEnemyCellInfo(i + 1,j) == Player::UNKNOWN_CODE && i < 10) ||
            (player.getEnemyCellInfo(i,j+1) == Player::UNKNOWN_CODE && j < 10) ||
            (player.getEnemyCellInfo(i - 1, j) == Player::UNKNOWN_CODE && i > 1) ||
            (player.getEnemyCellInfo(i, j - 1) == Player::UNKNOWN_CODE && j > 1);

}


void AI::recommendHitForPlayer(Player & player, int * recommendedHit) {
    srand(time(NULL));
    recommendedHit[0] = -1;
    recommendedHit[1] = -1;
    bool found = false;
    for(int i = 1; i <= 10; i++)
    {
        for(int j = 1; j <= 10; j++)
        {
            if (player.getEnemyCellInfo(i,j) == Player::SHOOT_CODE && unknownCellsNearby(player, i, j))
            {
                findUnknownCellNearby(player, i, j, recommendedHit);

                found = true;
                std::cout << std::endl << "found?: " <<found << std::endl;
                Keyboard::getch();
                break;
            }
        }
        if(found) break;
    }
    //std::cout << std::endl << "found?: " << (char*) found << std::endl;
    if (!found)
    {

        recommendedHit[0] = rand() % 10 + 1;
        recommendedHit[1] = rand() % 10 + 1;
        while(player.getEnemyCellInfo(recommendedHit[0],recommendedHit[1]) != Player::UNKNOWN_CODE)
        {
            recommendedHit[0] = rand() % 10 + 1;
            recommendedHit[1] = rand() % 10 + 1;
        }
    }
}

void AI::recommendAndSetShipPlacement(Player & player, int length, int id) {
    int headX, headY;
    bool rotation;

    headX = rand() % 10 + 1;
    headY = rand() % 10 + 1;
    rotation = (rand() % 2 == 0);


    while(!nicePlace(player, headX, headY, length, rotation))
    {
        headX = rand() % 10 + 1;
        headY = rand() % 10 + 1;
        rotation = (rand() % 2 == 0);
    }

    int shipHead[2],shipTail[2];
    shipHead[0] = headX;
    shipHead[1] = headY;

    if(rotation)
    {
        shipTail[0] = headX;
        shipTail[1] = headY + length - 1;
    }
    else
    {
        shipTail[0] = headX  + length - 1;
        shipTail[1] = headY;
    }

    if(rotation) //horizontal
    {
        for (int i = shipHead[1]; i <= shipTail[1]; i++) {
            player.setCellState(Player::HORIZONTALBOAT_CODE,shipHead[0],i);
            if (shipHead[0] > 1)
                player.setCellState(Player::NEARBY_CODE,shipHead[0] - 1,i);
            if (shipHead[0] < 10)
                player.setCellState(Player::NEARBY_CODE,shipHead[0] + 1,i);
        }

        for (int i = shipHead[0] - 1; i <= shipHead[0] + 1; i++) {
            if (player.onArea(i, shipHead[1] - 1)) player.setCellState(Player::NEARBY_CODE, i,shipHead[1] - 1);
            if (player.onArea(i, shipTail[1] + 1)) player.setCellState(Player::NEARBY_CODE,i,shipTail[1] + 1);
        }

    }
    else //vertical
    {

        for (int i = shipHead[0]; i <= shipTail[0]; i++) {
            player.setCellState(Player::VERTICALBOAT_CODE,i,shipHead[1]);
            if (shipHead[1] > 1)
                player.setCellState(Player::NEARBY_CODE,i,shipHead[1] - 1);
            if (shipHead[1] < 10)
                player.setCellState(Player::NEARBY_CODE, i,shipHead[1] + 1);
        }

        for (int j = shipHead[1] - 1; j <= shipHead[1] + 1; j++) {
            if (player.onArea(shipHead[0] - 1, j)) player.setCellState(Player::NEARBY_CODE, shipHead[0] - 1,j);
            if (player.onArea(shipTail[0] + 1, j)) player.setCellState(Player::NEARBY_CODE, shipTail[0] + 1,j);
        }

    }

    player.setPlayerFleet(id,length,shipHead,shipTail,rotation);

    //UNCOMMENT HERE TO SEE ALL ENEMY'S SHIPS
//    UI::clearScreen();
//    player.printMyArea();
//    Keyboard::getch();
//    UI::clearScreen();
}

bool AI::nicePlace(Player & player, int headX, int headY, int length, bool rotation) {

    bool check = true;
    if (rotation) //if horizontal
    {
        for(int j = headY; j <= headY + length - 1; j++)
        {
            if (!player.onArea(headX,j) || player.getCellState(headX,j) != Player::FREE_CODE)
            {
                check = false;
                break;
            }
        }

    }
    else
    {
        for(int i = headX; i <= headX + length - 1; i++)
        {
            if (!player.onArea(i,headY) || player.getCellState(i,headY) != Player::FREE_CODE)
            {
                check = false;
                break;
            }
        }
    }
    return check;
}
