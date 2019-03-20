//
// Created by vitaly on 18.03.19.
//

#include "../model/AI.h"

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
                break;
            };
        }
    }

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
