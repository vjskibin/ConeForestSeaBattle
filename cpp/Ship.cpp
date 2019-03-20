//
// Created by vitaly on 20.03.19.
//

#include "../model/Ship.h"
#include <iostream>
Ship::Ship()
{
    this->isAlive = false;
}

void Ship::setPosition(int shipId, int shipLength, int *shipHead, int *shipTail, bool rotation)
{
    this->shipId = shipId;
    this->shipLength = shipLength;
    this->cellsInFire = 0;
    this->shipHead[0] = shipHead[0];
    this->shipHead[1] = shipHead[1];

    this->shipTail[0] = shipTail[0];
    this->shipTail[1] = shipTail[1];
    this->rotation = rotation;

    this->isAlive = false;
}


void Ship::setStatus(bool isAlive) {
    this->isAlive = isAlive;
}

bool Ship::getStatus()
{
    return this->isAlive;
}

int Ship::getShipId()
{
    return shipId;
}

void Ship::setShipId(int shipId)
{
    this->shipId = shipId;
}

int Ship::getShipLength()
{
    return shipLength;
}

void Ship::setShipLength(int shipLength)
{
    this->shipLength = shipLength;
}

bool Ship::containsCell(int x, int y) {
    return x >= shipHead[0] && x <= shipTail[0] && y >= shipHead[1] && y <= shipTail[1];
}

bool Ship::allCellsInFire()
{
    return this->cellsInFire >= this->shipLength;
}

void Ship::addCellInFire() {
    this->cellsInFire++;
    if (allCellsInFire())
    {
        setStatus(false);
        //std::cout << std::endl << "Ship ID: " << getShipId() << " status: " << getStatus();
    }
}

int Ship::getShipHeadi() {
    return shipHead[0];
}

int Ship::getShipHeadj() {
    return shipHead[1];
}

bool Ship::getRotation() {
    return this->rotation;
}



