// MusicPlayer_C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <Windows.h>
#include <mmsystem.h>
#include <iostream>
#include <string>
using namespace std;
#pragma comment(lib, "winmm.lib")

int main();
int playSound(const wchar_t* filename);

int main() {
    // Play a WAV file
    cout << "Welcome \n";

    // Variable declaration
    int option;
    bool goOn = FALSE;
    const wchar_t* filename = nullptr;

    while (goOn == FALSE)
    {
        cout << "Choose a song \n 0:End \n 1:Epic \n 2:Thrill \n : ";
        cin >> option;

        if (option == 1)
        {
            filename = L"HOTD_Song.wav";
            goOn = FALSE;

            playSound(filename);
        }
        else if (option == 2)
        {
            filename = L"Hardpoints_Song.wav";
            goOn = FALSE;

            playSound(filename);
        }
        else if (option == 0)
        {
            cout << "Goodbye!";
            goOn = TRUE;
        }
        else
        {
            cout << "Please choose a number that is available \n";
            goOn = FALSE;
        }

    };
    
    return 0;
}

/********************************************************************
*playSound
*This function plays and stops the song given by the user
*Press enter to start and stop music
*input = Enter 
*
**********************************************************************/
int playSound(const wchar_t* filename) {

    string input;

    cout << "Music playing \nPress enter to stop \n";
    PlaySound(filename, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

    getline(cin, input);
    PlaySound(filename, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    getline(cin, input);
    PlaySound(0, 0, 0);

    cout << "Music Finished \n";

    return 0;
}