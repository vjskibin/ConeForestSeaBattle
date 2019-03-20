//
// Created by vitaly on 18.03.19.
//

#include "../model/Keyboard.h"
#include <iostream>
#include <termios.h>
#include <stdio.h>

//======================== GETCH() IMPLEMENTATION START =========================

struct termios Keyboard::old, Keyboard::newOne;

/* Initialize new terminal i/o settings */
void Keyboard::initTermios(int echo)
{
    tcgetattr(0, &old); /* grab old terminal i/o settings */
    newOne = old; /* make new settings same as old settings */
    newOne.c_lflag &= ~ICANON; /* disable buffered i/o */
    if (echo) {
        newOne.c_lflag |= ECHO; /* set echo mode */
    } else {
        newOne.c_lflag &= ~ECHO; /* set no echo mode */
    }
    tcsetattr(0, TCSANOW, &newOne); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void Keyboard::resetTermios()
{
    tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char Keyboard::getch_(int echo)
{
    char ch;
    initTermios(echo);
    ch = getchar();
    resetTermios();
    return ch;
}

/* Read 1 character without echo */
char Keyboard::getch()
{
    return getch_(0);
}

/* Read 1 character with echo */
char Keyboard::getche()
{
    return getch_(1);
}

//========================= GETCH() IMPLEMENTATION END ==========================