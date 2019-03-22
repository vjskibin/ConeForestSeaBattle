//
// Created by vitaly on 18.03.19.
//

#ifndef CONEFORESTSEABATTLE_BATTLE_H
#define CONEFORESTSEABATTLE_BATTLE_H

#include "Player.h"

class Battle {

private:
    int turn;
    Player *player;
    Player *enemy;
public:
    //конструктор
    Battle();

    //инициализирует игроков, ничего интересного
    //просто присваивает переданные значения приватным полям класса
    void initPlayers(Player &, Player &);

    //функция заполняет поля игроков
    //внутри вызывается функция fillArea()
    void prepareForBattle();

    //просто мусор, который может пригодиться
    void incTurn();


    //функция, описывающая ход одного игрока
    void playerTurn();

    //а эта другого
    //обе идентичны, только в одной описывается ход игрока player,
    // а в другой enemy
    void enemyTurn();


    //зацикливает функции playerTurn() и enemyTurn() до тех пор, пока хотя бы
    //у одного из игроков не закончатся корабли
    void startBattle();

    //вызывает функцию, выводящую на экран победителя
    //параметром передается инстанс победителя игры
    void showStats(Player &);

    //мусор для вида
    void finish();
};


#endif //CONEFORESTSEABATTLE_BATTLE_H
