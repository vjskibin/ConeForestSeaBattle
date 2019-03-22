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
#include "../model/AI.h"
#include <iostream>

void Player::initShips()
{
//    battleship = 0;
//    cruiser[0] = 0;
//    cruiser[1] = 0;
//    for(int i = 0; i < 3; i++)
//        destroyer[i] = 0;
//    for(int i = 0; i < 4; i++)
//        submarine[i] = 0;
}

Player::Player(std::string role) {
    for(int i = 1; i <= 10; i++)
        for(int j = 1; j <= 10; j++)
        {
            playerArea[i][j] = Player::FREE_CODE;
            enemyArea[i][j] = Player::UNKNOWN_CODE;
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
    std::string role;
    if (getRole() == 1) role = " (human)";
    else role = "(computer)";
    return this->name + role;
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

                    case Player::NEARBY_CODE:
                        std::cout << "X";
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
    std::cout << "Now fills: " << getName() << std::endl;

    if (!getRole())
    {
        Keyboard::getch();
        std::cout << "Computer already placed his ships!" << std::endl;
    }
    std::cout << "Press any key to continue... ";
    Keyboard::getch();

    int responseCode = 0;
    int length = 4;

    for(int id = 0; id < 10; id++)
    {
        switch (id)
        {
            case 0: length = 4;
                break;
            case 1:
                length = 3;
                break;

            case 3:
                length = 2;
                break;

            case 6:
                length = 1;
            default:
                break;
        }

        if (getRole()) //if human plays
        {
            responseCode = 0;
            while (responseCode != Player::SUCCEDPLACEMENT_CODE)
            {
                placeShipWithResponse(length, id, responseCode);
            }
        }
        else //if computer
            AI::recommendAndSetShipPlacement(*this, length, id);
    }




//    responseCode = 0;
//    while (responseCode != Player::SUCCEDPLACEMENT_CODE)
//        placeShipWithResponse(3,1, responseCode);
//
//    responseCode = 0;
//    while (responseCode != Player::SUCCEDPLACEMENT_CODE)
//        placeShipWithResponse(3,2, responseCode);
//
//    responseCode = 0;
//    while (responseCode != Player::SUCCEDPLACEMENT_CODE)
//        placeShipWithResponse(2,3, responseCode);

//    responseCode = 0;
//    while (responseCode != Player::SUCCEDPLACEMENT_CODE)
//        placeShipWithResponse(2,4, responseCode);
//
//    responseCode = 0;
//    while (responseCode != Player::SUCCEDPLACEMENT_CODE)
//        placeShipWithResponse(2,5, responseCode);
//
//    responseCode = 0;
//    while (responseCode != Player::SUCCEDPLACEMENT_CODE)
//        placeShipWithResponse(1,6, responseCode);
//
//    responseCode = 0;
//    while (responseCode != Player::SUCCEDPLACEMENT_CODE)
//        placeShipWithResponse(1,7, responseCode);
//
//    responseCode = 0;
//    while (responseCode != Player::SUCCEDPLACEMENT_CODE)
//        placeShipWithResponse(1,8, responseCode);
//
//    responseCode = 0;
//    while (responseCode != Player::SUCCEDPLACEMENT_CODE)
//        placeShipWithResponse(1,9, responseCode);

}



void Player::areaNavigate(int &x, int &y)
{
    char direction;
    x = 1; y = 1;
    UI::clearScreen();
    std::cout << getName() << "'s turn: " << std::endl;
    printPointedEnemyArea(x,y);
    direction = Keyboard::getche();
    if (!getRole()) //if computer plays
    {
        int recommendedHit[2];
        AI::recommendHitForPlayer(*this, recommendedHit);
        x = recommendedHit[0];
        y = recommendedHit[1];
        return;
    }
    bool errorOccured = false;
    while(direction != 'e')
    {
        UI::clearScreen();
        std::cout << getName() << "'s turn: " << std::endl;
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
        printPointedEnemyArea(x,y);
        if (errorOccured) {
            std::cout << std::endl << "[ERROR] Wrong direction" << std::endl;
            errorOccured = false;
        }
        //std::cout << (int) direction;
        direction = Keyboard::getche();
    }
//    UI::clearScreen();
//    std::cout << getName() << "'s turn: " << std::endl;
//    printPointedEnemyArea(x,y);
    //Keyboard::getch();
    UI::clearScreen();

}


void Player::attack(Player & enemy, int x, int y,bool & turnAgain) {
    bool dumb = false;
    if ((enemy.getCellState(x,y) == Player::VERTICALBOAT_CODE || enemy.getCellState(x,y) == Player::HORIZONTALBOAT_CODE)  && getEnemyCellInfo(x,y) == Player::UNKNOWN_CODE)
    {
        enemy.setCellState(Player::SHOOT_CODE,x,y);
        int shipId = -1;
        shipId = enemy.findShipIdByXY(x,y);
        setEnemyCellInfo(Player::SHOOT_CODE,x,y);
        enemy.sayToShipHeGotHit(shipId);
        if (!enemy.getShipStateById(shipId)) //if shot ship is dead
        {
            int headX,headY,length;
            bool rotation;
            headX = enemy.getHeadX(shipId);
            headY = enemy.getHeadY(shipId);
            rotation = enemy.getRotation(shipId);
            length = enemy.getLength(shipId);
            enemy.killShip(shipId);
            addKilledShipOnArea(headX,headY,length,rotation);
        }//if shipId has all fired cells

        turnAgain = enemy.getAliveShipsCount() >= 1;
    }
    else if (getEnemyCellInfo(x,y) == Player::UNKNOWN_CODE)
    {
        setEnemyCellInfo(Player::FREE_CODE,x,y);
        turnAgain = false;
    }
    else
    {
        turnAgain = true;
        dumb = true;
    }

    UI::clearScreen();
    std::cout << getName() << "'s turn: " << std::endl;
    printEnemyArea();
    if (dumb) std::cout << "Wrong choice, try again..." << std::endl;
    else if (!turnAgain && !dumb) std::cout << "Press any key for the next turn..." << std::endl;
    else std::cout << "Nice hit!" << std::endl;


    Keyboard::getch();

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
    bool errorOccured = false; //error while placing
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
                errorOccured = true;

        }

        printShipPlacement(rotation,shipHead, shipTail);
        if (errorOccured)
        {
            std::cout << std::endl << "[ERROR] Wrong direction" << std::endl;
        }
        if (responseCode == Player::FAILEDPLACEMENT_CODE) std::cout << std::endl << "[ERROR] You can't place your ship here" << std::endl;
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
    {
        this->playerFleet[id].setPosition(id,length,shipHead,shipTail,rotation);
        this->playerFleet[id].setStatus(true);
        responseCode = Player::SUCCEDPLACEMENT_CODE;
    }


}

void Player::setPlayerFleet(int id, int length, int * shipHead, int * shipTail, bool rotation)
{
    this->playerFleet[id].setPosition(id,length,shipHead,shipTail,rotation);
    this->playerFleet[id].setStatus(true);
}

bool Player::onArea(int i, int j)
{
    return i >= 1 && i <= 10 && j >= 1 && j <= 10;
}

short int Player::getCellState(int i, int j) {
    return playerArea[i][j];
}

void Player::setCellState(short int state, int i, int j) {
    playerArea[i][j] = state;
}

void Player::setEnemyCellInfo(short int state, int i, int j)
{
    enemyArea[i][j] = state;
}

short int Player::getEnemyCellInfo(int i, int j)
{
    return enemyArea[i][j];
}


int Player::getAliveShipsCount()
{
    int count = 0;
    for (auto &i : playerFleet)
    {
        if(i.getStatus()) count++;
    }
    return count;
}

int Player::findShipIdByXY(int x, int y) {
    for (auto &i : playerFleet)
    {
        if (i.containsCell(x,y))
        {
         //   std::cout << std::endl << "Ship ID: " << i.getShipId();
            return i.getShipId();
        }


    }

}

void Player::sayToShipHeGotHit(int id) {
    playerFleet[id].addCellInFire();

}

bool Player::getShipStateById(int id)
{
    return playerFleet[id].getStatus();
}

void Player::killShip(int shipId)
{
    int headX,headY,length;
    headX = playerFleet[shipId].getShipHeadi();
    headY = playerFleet[shipId].getShipHeadj();
    length = playerFleet[shipId].getShipLength();

    if(playerFleet[shipId].getRotation())
    {
        for(int j = headY; j <= headY+length-1; j++)
        {
            playerArea[headX][j] = Player::KILLED_CODE;

        }

    }
    else
    {
        for(int i = headY; i <= headY + length - 1; i++)
            playerArea[i][headY] = Player::KILLED_CODE;
    }


}

int Player::getHeadX(int shipId)
{
    return playerFleet[shipId].getShipHeadi();
}

int Player::getHeadY(int shipId)
{
    return playerFleet[shipId].getShipHeadj();
}

int Player::getLength(int shipId)
{
    return playerFleet[shipId].getShipLength();
}

bool Player::getRotation(int shipId)
{
    return playerFleet[shipId].getRotation();
}

void Player::addKilledShipOnArea(int headX, int headY, int length, bool rotation)
{
    if (rotation) //if horizontal
    {
        for(int j = headY; j <= headY + length - 1; j++)
            setEnemyCellInfo(Player::KILLED_CODE,headX,j);

        for (int j = headY; j <= headY + length - 1 ; j++)
        {
            if (headX > 1)
                setEnemyCellInfo(Player::FREE_CODE, headY - 1, j);
            if(headX < 10)
                setEnemyCellInfo(Player::FREE_CODE,headX + 1,j);
        }

        for(int i = headX - 1; i <= headX + 1; i++)
        {
            if (onArea(i, headY - 1)) setEnemyCellInfo(Player::FREE_CODE,i,headY - 1);
            if (onArea(i, headY + length)) setEnemyCellInfo(Player::FREE_CODE,i,headY + length);
        }
    }
    else
    {
        for(int i = headX; i <= headX + length - 1; i++)
            setEnemyCellInfo(Player::KILLED_CODE, i, headY);
        for (int i = headX; i <= headX + length - 1 ; i++)
        {
            if (headY > 1)
                setEnemyCellInfo(Player::FREE_CODE,i,headY - 1);
            if(headY < 10)
                setEnemyCellInfo(Player::FREE_CODE,i,headY + 1);
        }

        for(int j = headY - 1; j <= headY + 1; j++)
        {
            if (onArea(headX - 1, j)) setEnemyCellInfo(Player::FREE_CODE,headX - 1,j);
            if (onArea(headX + length, j)) setEnemyCellInfo(Player::FREE_CODE,headX + length,j);
        }
    }
}




