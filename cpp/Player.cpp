//
// Created by vitaly on 18.03.19.
//
//pointed: 25A3 unknown: 25A1  shoot: 2612  killed: 2620 free:
//boat
//VERTICAL 25ae
//HORIZONTAL 25ac
#include <string>
#include "../model/Player.h"
#include "../model/UI.h"
#include "../model/Keyboard.h"
#include <iostream>

void Player::initShips()
{
    battleship = 0;
    cruiser[0] = 0;
    cruiser[1] = 0;
    for(int i = 0; i < 3; i++)
        destroyer[i] = 0;
    for(int i = 0; i < 4; i++)
        submarine[i] = 0;
}

Player::Player(std::string role) {
    for(int i = 1; i <= 10; i++)
        for(int j = 1; j <= 10; j++)
        {
            playerArea[i][j] = 0;
            enemyArea[i][j] = 0;
        }
    setRole(role == "human"); //TRUE if human, else FALSE
    setName("Player_" + std::to_string(rand() % 99 + 1)); //name as Player_NN
    initShips();

    //log
    getRole() ? std::cout << "Human" : std::cout << "AI";
    std::cout << " is being created as " << getName() << std::endl;


}



void Player::setName(std::string name)
{
       this-> name = name;
}

void Player::setRole(bool role)
{
    this->role = role;
}


std::string Player::getName()
{
    return this->name;
}


std::string Player::getStat()
{
    std::string stats = "";
    stats += this->getName();
    return stats;
}


bool Player::getRole()
{
    return this->role;
}


void Player::printMyArea()
{
    for(int i = 1; i <= 10; i++)
    {
        for(int j = 1; j <= 10; j++)
        {
            //std::cout << playerArea[i][j] << " ";
            switch (playerArea[i][j])
            {
                case Player::UNKNOWN_CODE:
                    std::cout << UI::UNKNOWN << " ";
                    break;

                case Player::FREE_CODE:
                    std::cout << UI::FREE << " ";
                    break;

                case Player::KILLED_CODE:
                    std::cout << UI::KILLED << " ";
                    break;
                case Player::SHOOT_CODE:
                    std::cout << UI::SHOOT << " ";
                    break;
                case Player::VERTICALBOAT_CODE:
                    std::cout << UI::VERTICALBOAT << " ";
                    break;

                case Player::HORIZONTALBOAT_CODE:
                    std::cout << UI::HORIZONTALBOAT << " ";
                    break;
                case Player::NEARBY_CODE:
                    std::cout << "X" << " ";
                    break;
                default:
                    std::cout << "? ";
                    break;
            }
        }

        std::cout << std::endl;
    }


}

void Player::printEnemyArea()
{
    for(int i = 1; i <= 10; i++)
    {
        for(int j = 1; j <= 10; j++)
        {
            //std::cout << playerArea[i][j] << " ";
            //if (playerArea[i][i] == 0) std::cout <<  UI::KILLED << " ";
            switch (enemyArea[i][j])
            {
                case Player::UNKNOWN_CODE:
                    std::cout << UI::UNKNOWN << " ";
                    break;

                case Player::FREE_CODE:
                    std::cout << UI::FREE << " ";
                    break;

                case Player::KILLED_CODE:
                    std::cout << UI::KILLED << " ";
                    break;
                case Player::SHOOT_CODE:
                    std::cout << UI::SHOOT << " ";
                    break;

                default:
                    std::cout << "? ";
                    break;
            }
        }

        std::cout << std::endl;
    }
}

void Player::printPointedEnemyArea(int iSelected, int jSelected)
{
    for(int i = 01; i <= 10; i++)
    {
        for(int j = 1; j <= 10; j++)
        {
            if (i == iSelected && j == jSelected)
            {
                std::cout << UI::CURSOR << " ";
            }
            else
            {
                switch (enemyArea[i][j])
                {
                    case Player::UNKNOWN_CODE:
                        std::cout << UI::UNKNOWN << " ";
                        break;

                    case Player::FREE_CODE:
                        std::cout << UI::FREE << " ";
                        break;

                    case Player::KILLED_CODE:
                        std::cout << UI::KILLED << " ";
                        break;
                    case Player::SHOOT_CODE:
                        std::cout << UI::SHOOT << " ";
                        break;

                    default:
                        std::cout << "? ";
                        break;
                }
            }
        }
        std::cout << std::endl;
    }
}

void Player::printPointedMyArea(int iSelected, int jSelected)
{
    for(int i = 1; i <= 10; i++)
    {
        for(int j = 1; j <= 10; j++)
        {
            if (i == iSelected && j == jSelected)
            {
                std::cout << UI::CURSOR << " ";
            }
            else
            {
                switch (playerArea[i][j])
                {
                    case Player::UNKNOWN_CODE:
                        std::cout << UI::UNKNOWN << " ";
                        break;

                    case Player::FREE_CODE:
                        std::cout << UI::FREE << " ";
                        break;

                    case Player::KILLED_CODE:
                        std::cout << UI::KILLED << " ";
                        break;
                    case Player::SHOOT_CODE:
                        std::cout << UI::SHOOT << " ";
                        break;
                    case Player::NEARBY_CODE:
                        std::cout << "X" << " ";
                        break;

                    default:
                        std::cout << "? ";
                        break;
                }
            }
        }
        std::cout << std::endl;
    }
}



void Player::fillArea()
{
    UI::clearScreen();
    std::cout << "Now fills: " << getRole() << " as " << getName() << std::endl << "Press any key to continue... ";
    Keyboard::getch();

    int responseCode = 0;
    while (responseCode != Player::SUCCEDPLACEMENT_CODE)
        placeShipWithResponse(4,1, responseCode);

    responseCode = 0;
    while (responseCode != Player::SUCCEDPLACEMENT_CODE)
        placeShipWithResponse(3,1, responseCode);

    responseCode = 0;
    while (responseCode != Player::SUCCEDPLACEMENT_CODE)
        placeShipWithResponse(3,2, responseCode);

    responseCode = 0;
    while (responseCode != Player::SUCCEDPLACEMENT_CODE)
        placeShipWithResponse(2,1, responseCode);

    responseCode = 0;
    while (responseCode != Player::SUCCEDPLACEMENT_CODE)
        placeShipWithResponse(2,2, responseCode);

    responseCode = 0;
    while (responseCode != Player::SUCCEDPLACEMENT_CODE)
        placeShipWithResponse(2,3, responseCode);

    responseCode = 0;
    while (responseCode != Player::SUCCEDPLACEMENT_CODE)
        placeShipWithResponse(1,1, responseCode);

    responseCode = 0;
    while (responseCode != Player::SUCCEDPLACEMENT_CODE)
        placeShipWithResponse(1,2, responseCode);

    responseCode = 0;
    while (responseCode != Player::SUCCEDPLACEMENT_CODE)
        placeShipWithResponse(1,3, responseCode);

    responseCode = 0;
    while (responseCode != Player::SUCCEDPLACEMENT_CODE)
        placeShipWithResponse(1,4, responseCode);

}



void Player::areaNavigate(int &x, int &y)
{
    char direction;
    UI::clearScreen();
    printPointedMyArea(x,y);
    direction = Keyboard::getche();
    bool errorOccured = false;

    while(direction != 'e')
    {
        UI::clearScreen();
        //std::cout << "|" << std::endl;
        switch(direction) {
            case 'w':
                if (x > 1) x--;
                break;
            case 'a':
                if (y > 1) y--;
                break;
            case 's':
                if (x < 10) x++;
                break;
            case 'd':
                if (y < 10) y++;
                break;

            default:
                errorOccured = true;

        }
        printPointedMyArea(x,y);
        if (errorOccured) {
            std::cout << std::endl << "[ERROR] Wrong direction" << std::endl;
            errorOccured = false;
        }
        //std::cout << (int) direction;
        direction = Keyboard::getche();
    }

    UI::clearScreen();

}

void Player::printShipPlacement(bool rotation, int * shipHead, int * shipTail)
{
    for(int i = 1; i <= 10; i++)
    {
        for(int j = 1; j <= 10; j++)
        {
            if (i >= shipHead[0] && i <= shipTail[0] && j >= shipHead[1] && j <= shipTail[1])
                rotation ? std::cout << UI::HORIZONTALBOAT << " " : std::cout << UI::VERTICALBOAT << " ";
            else {

                switch (playerArea[i][j]) {
                    case Player::UNKNOWN_CODE:
                        std::cout << UI::UNKNOWN << " ";
                        break;

                    case Player::FREE_CODE:
                        std::cout << UI::FREE << " ";
                        break;

                    case Player::KILLED_CODE:
                        std::cout << UI::KILLED << " ";
                        break;
                    case Player::SHOOT_CODE:
                        std::cout << UI::SHOOT << " ";
                        break;
                    case Player::VERTICALBOAT_CODE:
                        std::cout << UI::VERTICALBOAT << " ";
                        break;

                    case Player::HORIZONTALBOAT_CODE:
                        std::cout << UI::HORIZONTALBOAT << " ";
                        break;

                    case Player::NEARBY_CODE:
                        std::cout << "X" << " ";
                        break;

                    default:
                        std::cout << "? ";
                        break;
                }
            }
        }

        std::cout << std::endl;
    }
}




void Player::placeShipWithResponse(int length, int id, int & responseCode) {
    int shipHead[2], shipTail[2]; //start and end coordinates of the ship [0] - i, [1] - j
    shipHead[0] = 1; //set to the left top corner
    shipHead[1] = 1;
    shipTail[0] = 1;
    shipTail[1] = length;
    bool rotation = true; //horizontal if true, false if vertical
    char direction = 'r'; //and its turns to vertical
    while(direction != 'e') {
        UI::clearScreen();
        switch (direction) {
            case 'w':
                if (shipHead[0] > 1)
                {
                    shipHead[0]--;
                    shipTail[0]--;
                }
                break;
            case 'a':
                if (shipHead[1] > 1)
                {
                    shipHead[1]--;
                    shipTail[1]--;
                }
                break;
            case 's':
                if (shipHead[0] < 10)
                {
                    shipHead[0]++;
                    shipTail[0]++;
                }
                break;
            case 'd':
                if (shipHead[1] < 10)
                {
                    shipHead[1]++;
                    shipTail[1]++;
                }
                break;
            case 'r':
                if(rotation)
                {
                    shipTail[1] = shipHead[1];
                    shipTail[0] = shipHead[0] + length - 1;
                }
                else
                {
                    shipTail[0] = shipHead[0];
                    shipTail[1] = shipHead[1] + length - 1;
                }
                rotation = !rotation;
                break;

            default:
                std::cout << std::endl << "[ERROR] Wrong direction";
        }
        printShipPlacement(rotation,shipHead, shipTail);
        direction = Keyboard::getche();
    }
    UI::clearScreen();
    bool placedOnArea = true; //tumbler for checking if placement is correct
    if(rotation) //horizontal
    {
        for (int i = shipHead[1]; i <= shipTail[1]; i++)
            //check if the ship placed not only on free cells
            if(!onArea(shipHead[0],i) ||
                playerArea[shipHead[0]][i] == Player::VERTICALBOAT_CODE ||
                playerArea[shipHead[0]][i] == Player::HORIZONTALBOAT_CODE ||
                playerArea[shipHead[0]][i] == Player::NEARBY_CODE)
            {
                placedOnArea = false;
                break;
            }

        if(placedOnArea)
        {
            for (int i = shipHead[1]; i <= shipTail[1]; i++)
            {
                playerArea[shipHead[0]][i] = Player::HORIZONTALBOAT_CODE;
                if (shipHead[0] > 1)
                    playerArea[shipHead[0]-1][i] = Player::NEARBY_CODE;
                if(shipHead[0] < 10)
                    playerArea[shipHead[0]+1][i] = Player::NEARBY_CODE;
            }

            for(int i = shipHead[0]-1; i <= shipHead[0]+1; i++)
            {
                if (onArea(i, shipHead[1] - 1)) playerArea[i][shipHead[1] - 1] = Player::NEARBY_CODE;
                if (onArea(i, shipTail[1] + 1)) playerArea[i][shipTail[1] + 1] = Player::NEARBY_CODE;
            }
        }

    }
    else //vertical
    {
        for (int i = shipHead[0]; i <= shipTail[0]; i++)
            //check if the ship placed not only on free cells
            if(!onArea(i,shipHead[1]) ||
                    playerArea[i][shipTail[1]] == Player::NEARBY_CODE ||
                    playerArea[i][shipTail[1]] == Player::HORIZONTALBOAT_CODE ||
                    playerArea[i][shipTail[1]] == Player::VERTICALBOAT_CODE)
            {
                placedOnArea = false;
                break;
            }
        if (placedOnArea)
        {
            for (int i = shipHead[0]; i <= shipTail[0]; i++)
            {
                playerArea[i][shipHead[1]] = Player::VERTICALBOAT_CODE;
                if (shipHead[1] > 1)
                    playerArea[i][shipHead[1] - 1] = Player::NEARBY_CODE;
                if (shipHead[1] < 10)
                    playerArea[i][shipHead[1] + 1] = Player::NEARBY_CODE;
            }

            for(int j = shipHead[1]-1; j <= shipHead[1]+1; j++)
            {
                if (onArea(shipHead[0] - 1, j)) playerArea[shipHead[0] - 1][j] = Player::NEARBY_CODE;
                if (onArea(shipTail[0] + 1, j)) playerArea[shipTail[0] + 1][j] = Player::NEARBY_CODE;
            }
        }


    }


    printMyArea();
    if (!placedOnArea)
    {
        std::cout << std::endl << "[ERROR] Can't place here" << std::endl;
        responseCode = Player::FAILEDPLACEMENT_CODE;
    }
    else
        responseCode = Player::SUCCEDPLACEMENT_CODE;

}

bool Player::onArea(int i, int j)
{
    return i >= 1 && i <= 10 && j >= 1 && j <= 10;
}




