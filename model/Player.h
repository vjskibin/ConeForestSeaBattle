//
// Created by vitaly on 18.03.19.
//

#ifndef CONEFORESTSEABATTLE_PLAYER_H
#define CONEFORESTSEABATTLE_PLAYER_H

#include <iostream>
#include "Ship.h"
class Player {
private:
    std::string name;
    bool role; //T when human, F when computer
    short int playerArea[12][12];
    short int enemyArea[12][12];

//    Ship battleship;
//    Ship cruisers[2];
//    Ship destroyers[3];
//    Ship submarines[4];
    Ship playerFleet[10];




public:
    static const short int UNKNOWN_CODE = 0;
    static const short int FREE_CODE = 100;
    static const short int SHOOT_CODE = 300;
    static const short int KILLED_CODE = 200; //find a joke here

    static const short int VERTICALBOAT_CODE = 101;
    static const short int HORIZONTALBOAT_CODE = 102;

    static const short int NEARBY_CODE = 502;

    static const short int SUCCEDPLACEMENT_CODE = 10;
    static const short int FAILEDPLACEMENT_CODE = 11;

    void initShips();

    Player();
    Player(std::string);

    bool getRole();
    std::string getName();


    void setName(std::string);
    void setRole(bool);
    std::string getStat();

    void fillArea();

    void printMyArea();
    void printEnemyArea();
    void printPointedEnemyArea(int i, int j);
    void printPointedMyArea(int, int);
    void areaNavigate(int&, int&);
    void attack(Player &,int,int,bool&);

    short int getCellState(int,int);
    void setCellState(short int, int, int);
    void setEnemyCellInfo(short int, int, int);
    short int getEnemyCellInfo(int, int);
    void sayToShipHeGotHit(int);
    int findShipIdByXY(int, int);
    bool getShipStateById(int);
    int getHeadX(int);
    int getHeadY(int);
    int getLength(int);
    bool getRotation(int);
    void addKilledShipOnArea(int, int, int, bool);
    void killShip(int);

    void placeShipWithResponse(int length, int id, int &);
    void printShipPlacement(bool, int*, int*);

    int getAliveShipsCount();
    bool onArea(int,int);
};


#endif //CONEFORESTSEABATTLE_PLAYER_H
