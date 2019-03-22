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
    //конструктор
    Ship();

    //сохраняет переданную инфу о корабле в инстанс
    //shipId - очевидно
    //shipLength - длина корабля
    //shipHead - массив координат головы корабля
    //shipTail - массив коорднат хвоста корабля
    //rotation - true, если расположен горизонтально, иначе вертикально
    void setPosition(int shipId, int shipLength, int * shipHead, int * shipTail, bool rotation);

    //устанаваливает, жив корабль или нет, true, если да
    void setStatus(bool isAlive);

    //геттеры
    int getShipId();
    bool getStatus();
    int getShipLength();
    int getShipHeadi();
    int getShipHeadj();
    bool getRotation();

    //сеттеры
    void setShipLength(int shipLength);
    void setShipId(int shipId);

    // возаращет true, если корабль содержит клетку с переданными координатами
    bool containsCell(int, int);

    //увеличивает количество раненых клеток
    void addCellInFire();

    //возвращает true, если все клетки корабля ранены
    bool allCellsInFire();
};


#endif //CONEFORESTSEABATTLE_SHIP_H
