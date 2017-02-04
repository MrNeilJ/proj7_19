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
 void displayPrompts(HANDLE screen)
{
    placeCursor(screen, 3, 25);
    cout << "******* Data Entry Form *******" << endl;
    placeCursor(screen, 5, 25);
    cout << "Name:  " << endl;
    placeCursor(screen, 7, 25);
    cout << "Age:             Gender (M/F): " << endl;
}

/************************************************************
 *                      getUserInput                        *
 ************************************************************/
 void getUserInput(HANDLE scree, userInfo &input)
{
    placeCursor(screen, 5, 31);
    getline(cin, input.name);
    placeCursor(screen, 7, 30);
    cin >> input.age;
    placeCursor(screen, 7, 55);
    cin >> input.gender;
}

/************************************************************
 *                      displayData                         *
 ************************************************************/
 void displayData(HANDLE screen, userInfo input)
{
    placeCursor(screen, 10, 0);
    cout << "Here is the data you entered.\n";
    cout << "Name  : " << input.name   << endl;
    cout << "Age:  : " << input.age    << endl;
    cout << "Gender: " << input.gender << endl;
}