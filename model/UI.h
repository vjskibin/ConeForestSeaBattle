//
// Created by vitaly on 18.03.19.
//

#ifndef CONEFORESTSEABATTLE_UI_H
#define CONEFORESTSEABATTLE_UI_H

#include <string>
//pointed: 25A3 unknown: 25A1  shoot: 2612  killed: 2620 free:
//boat
//VERTICAL 25ae
//HORIZONTAL 25ac
class UI {
public:

    //коды символов:
    static const std::string UNKNOWN; //неизвестной клетки
    static const std::string FREE; //свободной
    static const std::string SHOOT; //подстреленной
    static const std::string KILLED; //убитой
    static const std::string CURSOR; //курсора

    static const std::string VERTICALBOAT; //вертикального корабля
    static const std::string HORIZONTALBOAT; //горизонтального корабля


    static void clearScreen(); //функция очистки экрана
    static void showMenu(char &); //показать меню
    static void showHelp(); //показать окно с помощью
};


#endif //CONEFORESTSEABATTLE_UI_H
