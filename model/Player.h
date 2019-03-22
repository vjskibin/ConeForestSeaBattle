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

    //у каждого игрока в памяти два поля:
    // playerArea - свое поле игрока с кораблями, изначально все клетки открыты и известны
    //enemyArea - поле соперника, октрывается постепенно с каждым ходом. Изначально состоит
    //просто из неизвестных клеток
    short int playerArea[12][12];
    short int enemyArea[12][12];


    //Массив всех кораблей игрока (всего 10)
    //иожно, конечно, все это сделать через stl, но стоит ли оно того?
    Ship playerFleet[10];




public:

    //все эти константы - это коды, которые могут быть у клетки поля
    static const short int UNKNOWN_CODE = 0; //что на клетке неизвестно
    static const short int FREE_CODE = 100; //клетка свободна
    static const short int SHOOT_CODE = 300; //клетка с постреленным кораблем
    static const short int KILLED_CODE = 200; //клетка с убитым кораблем
    //find a joke here

    static const short int VERTICALBOAT_CODE = 101; //клетка с кораблем, расположенным вертикально
    static const short int HORIZONTALBOAT_CODE = 102;//клетка с кораблем, расположенным горизонтально

    static const short int NEARBY_CODE = 502; //код, используемый в начале игры, нужен, чтобы не дать игроку расположить корабли рядом


    //код, возвращаемый функцией расположения кораблей, если все ок
    static const short int SUCCEDPLACEMENT_CODE = 10;

    //а этот, если игрок накосячил при расположении (поставил один корабль на другой, например)
    static const short int FAILEDPLACEMENT_CODE = 11;


    //всем кораблям - дефолтные значения неизвестных
    void initShips();

    //конструктор
    Player();
    Player(std::string);

    //возвращает роль игрока, true если человек, иначе false
    bool getRole();

    //возвращает имя игрока
    std::string getName();

    //устанавливает имя игрока
    void setName(std::string);

    //устанавливает роль игрока
    void setRole(bool);

    //мусор
    std::string getStat();

    //функция заполнения поля для игрока-человека
    void fillArea();

    //вывод поля игрока
    void printMyArea();

    //вывод поля соперника
    void printEnemyArea();

    //вывод поля соперника с навигацией, чтобы был курсор нарисован
    //на переданных координатах
    void printPointedEnemyArea(int i, int j);

    //функция, реализующая выбор клетки, куда стрелять
    //каждый шаг вызывает printPointedEnemyArea()
    void areaNavigate(int&, int&);

    //функция атаки на определенную клетку игрока переданного первым параметром
    //по координатам, переданным вторым и третьим параметром, последний параметр
    //сохраняет информацию о том, стоит ли после своего хода игроку ходить еще раз (тру - да)
    void attack(Player &,int,int,bool&);

    //возвращает код клетки
    short int getCellState(int,int);

    //устанавливает код клетки
    void setCellState(short int, int, int);

    //устанавливает код клетки на поле противника, которое хранится у игрока
    void setEnemyCellInfo(short int, int, int);

    //возвращает код клетки на поле противника, которое хранится у игрока
    short int getEnemyCellInfo(int, int);

    //сообщить кораблю, что одна из его клеток подбита
    void sayToShipHeGotHit(int);

    //узнает, какой именно корабль находится на клетке с переданными координатами, возвращает его индекс (который совпадает с id)
    int findShipIdByXY(int, int);

    //узнат, жив ли корабль с переданным id
    bool getShipStateById(int);

    //возвращает координату i головы корабля по id
    int getHeadX(int);

    //возвращает координату j головы корабля по id
    int getHeadY(int);

    //возвращает длину корабля по id
    int getLength(int);

    //возвращает true, если корабль расположен горизонтально, false, если вертикально
    //принимает id корабля
    bool getRotation(int);

    //добавляет на поле противника, хранящегося у игрока, убитый корабль
    //(чтобы он отображался именно как убитый, а не сколько-нибудь раненых клеток)
    void addKilledShipOnArea(int, int, int, bool);

    //добавляет информацию в инстанс корабля о том, что он мертв
    void killShip(int);

    //функция добавления корабля на поле игрока-человека
    void placeShipWithResponse(int length, int id, int &);

    //добавляет инфу о расположенном корабле в массив кораблей
    void setPlayerFleet(int id, int length, int * shipHead, int * shipTail, bool rotation);

    //функция, выводящая на экран расположение корабля,
    //используется во время заполнения поля игроком-человеком
    void printShipPlacement(bool, int*, int*);

    //возвращает количество живых кораблей игрока
    int getAliveShipsCount();

    //возвращает true, если переданные координаты клетки расположены на игровом поле
    bool onArea(int,int);
};


#endif //CONEFORESTSEABATTLE_PLAYER_H
