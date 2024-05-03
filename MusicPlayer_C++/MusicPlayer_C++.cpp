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
    cout << "Welcome\n";
    // Play a WAV file

    int option;
    cout << "Choose a song \n 0:End \n 1:Epic \n 2:Thrill\n";
    cin >> option;
    cout << "Playing Music \n";

    bool goOn = FALSE;
    const wchar_t* filename = nullptr;
    while (goOn == FALSE)
    {
        if (option == 1)
        {
            filename = L"HOTD_Song.wav";
            goOn = TRUE;

            playSound(filename);
        }
        else if (option == 2)
        {
            filename = L"Hardpoints_Song.wav";
            goOn = TRUE;

            playSound(filename);
        }
        else if (option == 0)
        {
            cout << "Goodbye!";
            goOn = TRUE;
        }
        else
        {
            cout << "Please choose a number that is available";
            goOn = FALSE;
        }

    };
    

    return 0;
}

int playSound(const wchar_t* filename) {

    PlaySound(filename, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

    string input;
    getline(cin, input);
    PlaySound(0, 0, 0);
    cout << "Stopped music \n";

    getline(cin, input);
    PlaySound(0, 0, 0);
    cout << "Playing music \n";
    PlaySound(filename, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

    getline(cin, input);

    cout << "Music Finished \n";

    return 0;
}