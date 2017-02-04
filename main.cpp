// This program creates a screen form for user input.
// from the user.

#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

struct UserInfo
{
    string name;
    int age;
    char gender;
};

void placeCursor(HANDLE, int, int);
void displayPrompts(HANDLE);
void getUserInput(HANDLE, userInfo&);
void displayData(HANDLE, userInfo);

int main()
{
    userInfo input;              // input is a UserInfo structure
                                // that has 3 member variables

    // Get the handle to standard output device (the consol)
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);

    displayPrompts(screen);
    getUserInput(screen, input);
    displayData(screen, input);

    return 0;
}

/************************************************************
 *                      placeCursor                         *
 ************************************************************/
void placeCursor(HANDLE screen, int row, int col)
{
    COORD positin;
    position.X = row;
    position.Y = col;
    SetConsoleCursorPosition(screen, position);
}


/************************************************************
 *                      displayPrompts                      *
 ************************************************************/