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

    static const std::string UNKNOWN;
    static const std::string FREE;
    static const std::string SHOOT;
    static const std::string KILLED;
    static const std::string CURSOR;

    static const std::string VERTICALBOAT;
    static const std::string HORIZONTALBOAT;


    static void printLegend();
    static void clearScreen();
    static void showMenu();
};


#endif //CONEFORESTSEABATTLE_UI_H
