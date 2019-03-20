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

void UI::printLegend()
{

}

void UI::showMenu() {

}
