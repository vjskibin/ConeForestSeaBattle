Works on OSX/Ubuntu.

For running on Windows:
1. Delete all calls for static methods Keyboard::getch() and Keyboard::getche(). Use getch() instead.
2. Unclude conio.h library in all files which uses the following method.
3. You do not need cpp/Keyboard.cpp and model/Keyboard.h anymore. Delete it.
4. Delete all #include "Keyboard.h".
5. Never run this again.
