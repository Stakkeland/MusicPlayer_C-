// MusicPlayer_C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <Windows.h>
#include <mmsystem.h>
#include <iostream>
#include <string>
using namespace std;
#pragma comment(lib, "winmm.lib")

int main();
int playSound();

int main() {
    cout << "Welcome\n";
    // Play a WAV file

    int option = 1;
    while (option != 0) {
        cout << "Choose an option (0: end 1:enter filename)\n";
        cin >> option;
        cout << "Playing Music \n";
        playSound();
        cout << "Music Finished \n";
    }

    return 0;
}

int playSound() {
    const wchar_t* filename = L"C:\Users\Sawyer Stakkeland\OneDrive\Documents\BYUI\8. 2024 Spring\Applied Programming_CSE310\MusicPlayer_C++\HOTD Song.wav";
    cout << "Please enter the filename: \n";
    //cin >> filename;

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

    return 0;
}