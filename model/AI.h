//
// Created by vitaly on 18.03.19.
//

#ifndef CONEFORESTSEABATTLE_AI_H
#define CONEFORESTSEABATTLE_AI_H


#include "Player.h"

class AI {
private:

    //findUnknownCellNearby смотрит, где есть неизвестная клетка рядом с
    //уже подстреленной
    //координаты такой сохраняются в массив из двух элементов, переданный последним
    //параметром по ссылке
    static void findUnknownCellNearby(Player &, int, int, int *);

    //unknownCellNearby - возвращает true, если рядом с подстреленной клеткой (координаты передаются
    // вторым и третьим параметром) есть хотя бы одна неизвестная
    static bool unknownCellsNearby(Player &, int, int);

    //функция nicePlace смотрит, можно ли впихнуть на сгенерированные координаты головы корабля
    //сам корабль, если да, то возвращает true
    //headX и headY - координаты головы
    // rotation - если true, то корабль горизонтальный, иначе вертикальный
    // player - инстанс игрока, включает инфу о его поле
    static bool nicePlace(Player &, int headX, int headY, int length, bool rot);
public:

    //функция находит координаты той точки, куда можно стрельнуть и сохраняет их
    //в массив, переданный вторым параметром
    static void recommendHitForPlayer(Player &, int *);

    //функция генерирует местоположение корабля компьютера и устанавливает его на поле
    //Использует приватные функции этого класса
    static void recommendAndSetShipPlacement(Player &, int len, int id);

};


#endif //CONEFORESTSEABATTLE_AI_H
