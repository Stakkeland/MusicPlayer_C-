// MusicPlayer_C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <Windows.h>
#include <iostream>
#include <format>
using namespace std;
#pragma comment(lib, "winmm.lib")

int main() {
    cout << "Welcome\n";
    // Play a WAV file

    int option = 1;
    while (option != 0) {
        cout << "Choose an option (0: end 1:enter filename)\n";
        cin >> option;
        playSound();
    }

    return 0;
}

int playSound() {
    string filename = "sound.wav";
    cout << "Please enter the filename: \n";
    cin >> filename;

    PlaySound(filename.c_str(), NULL, SND_FILENAME);

    return 0;
}