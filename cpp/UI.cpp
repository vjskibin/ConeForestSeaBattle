//
// Created by vitaly on 18.03.19.
//
#ifdef _WIN32
#include <windows.h>
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif
#include "../model/UI.h"
#include "../model/Keyboard.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

const std::string UI::UNKNOWN = "\u25a1";
const std::string UI::CURSOR = "\u25a3";
const std::string UI::FREE = "\u25e6";
const std::string UI::SHOOT = "\u2612";
const std::string UI::KILLED = "\u2620";
const std::string UI::HORIZONTALBOAT = "\u25ac";
const std::string UI::VERTICALBOAT = "\u25ae";

void UI::clearScreen()
{
    system(CLEAR);
}

void UI::showMenu(char & goGame) {
    using namespace std;
    UI::clearScreen();
    cout << endl << "=================== SUPER MEGA ULTRA UBER SEA BATTLE =====================";
    cout << endl;
    cout << endl << "1. Start a new game";
    cout << endl << "2. Help";
    cout << endl << "3. Exit";
    cout << endl;
    cout << endl << "==========================================================================";
    cout << endl;
    goGame = Keyboard::getche();
    switch (goGame)
    {
        case '1':
            goGame = '1';
            break;

        case '2':
            UI::showHelp();
            goGame = '2';
            break;

        case '3':
            goGame = '3';
            break;

        default:

            break;
    }
}

void UI::showHelp() {
    using namespace std;
    char goGame = '2';
    UI::clearScreen();
    cout << endl << "=================== SUPER MEGA ULTRA UBER HELP FOR U =====================";
    cout << endl;
    cout << endl << "W A S D - movements";
    cout << endl << "R - rotate ship";
    cout << endl << "E - set/choose";
    cout << endl << UI::UNKNOWN << " - unknown cell";
    cout << endl << UI::FREE << " - the cell with no ship";
    cout << endl << UI::SHOOT << " - the cell that was shot down";
    cout << endl << UI::KILLED << " - just a part of a killed ship";
    cout << endl << UI::CURSOR << " - the cell you aim at";
    cout << endl;
    cout << endl << "E. Back";
    cout << endl;
    cout << endl << "==========================================================================";
    Keyboard::getch();
    UI::showMenu(goGame);
}
