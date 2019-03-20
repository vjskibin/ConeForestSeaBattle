//
// Created by vitaly on 20.03.19.
//

#ifndef CONEFORESTSEABATTLE_SHIP_H
#define CONEFORESTSEABATTLE_SHIP_H


class Ship {
private:
    int shipId;
    int shipLength;
    int cellsInFire;
    int shipHead[2];
    int shipTail[2];
    bool rotation;

    bool isAlive;

public:
    Ship();
    void setPosition(int shipId, int shipLength, int * shipHead, int * shipTail, bool rotation);
    void setStatus(bool isAlive);

    int getShipId();
    bool getStatus();
    void setShipId(int shipId);

    int getShipLength();

    void setShipLength(int shipLength);
    int getShipHeadi();
    int getShipHeadj();
    bool getRotation();
    bool containsCell(int, int);
    void addCellInFire();
    bool allCellsInFire();
};


#endif //CONEFORESTSEABATTLE_SHIP_H
