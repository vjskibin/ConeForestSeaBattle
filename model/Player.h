//
// Created by vitaly on 18.03.19.
//

#ifndef CONEFORESTSEABATTLE_PLAYER_H
#define CONEFORESTSEABATTLE_PLAYER_H

#include <iostream>

class Player {
private:
    std::string name;
    bool role; //T when human, F when computer
    unsigned short int playerArea[12][12];
    unsigned short int enemyArea[12][12];

    unsigned short int battleship;
    unsigned short int cruiser[2];
    unsigned short int destroyer[3];
    unsigned short int submarine[4];


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

    void placeShipWithResponse(int length, int id, int &);
    void printShipPlacement(bool, int*, int*);

    bool onArea(int,int);
};


#endif //CONEFORESTSEABATTLE_PLAYER_H
