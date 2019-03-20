//
// Created by vitaly on 18.03.19.
//

#ifndef CONEFORESTSEABATTLE_KEYBOARD_H
#define CONEFORESTSEABATTLE_KEYBOARD_H
#include <iostream>
#include <termios.h>
#include <stdio.h>

class Keyboard {
private:

    //==== PRIVATE CLEAR SCREEN METHODS ====
    static struct termios old, newOne;
    static void initTermios(int);
    static void resetTermios();
    static char getch_(int);
    //==== END OF CLEAR SCREEN METHODS =====




public:

    //==== PUBLIC CLEAR SCREEN METHODS ====
    static char getch(); //without echo
    static char getche(); //with echo
    //==== END OF CLEAR SCREEN METHODS ===


};


#endif //CONEFORESTSEABATTLE_KEYBOARD_H
