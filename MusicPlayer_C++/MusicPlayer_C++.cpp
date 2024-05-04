// MusicPlayer_C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <Windows.h>
#include <mmsystem.h>
#include <iostream>
#include <string>
using namespace std;
#pragma comment(lib, "winmm.lib")

int main();
int menu();
int playSound(const wchar_t* filename);

int main() {

    cout << "Welcome! \n";
    
    menu();
    
    return 0;
}

/***************************************************
 * Menu system
 * Loop until the user quits the program. Song choices
 * are handpicked for the user.
 * INPUT
 *     option : user selected number that corresponds
 *              to a song
 *     goOn : Bool where TRUE ends the main loop
 *     filename : holds the location of the song file
 *               chosen by user.
 **************************************************/
int menu()
{
    // Variable declaration
    int option;
    bool goOn = FALSE;
    const wchar_t* filename = nullptr;

    //Main Loop. Menu and call to playSound function
    while (goOn == FALSE)
    {
        //Menu output
        cout << "\nChoose a song \n 0:End \n 1:Epic \n 2:Thrill \n : ";
        cin >> option;

        // If statements depending on number chosen by user.
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

/***************************************************
 * PLAY SOUND FILE
 * Take file that is chosen by user and play the 
 * audio within it.
 * INPUT
 *     filename : filename in project folder
 *     input : user can press enter to end song
 *     PlaySound : Internal function that plays sounds
 **************************************************/
int playSound(const wchar_t* filename) {

    string input;

    cout << "\nMusic playing \nPress enter to stop \n";

    getline(cin, input);
    // Plays song file
    PlaySound(filename, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    getline(cin, input);
    PlaySound(0, 0, 0); //Stop Music

    cout << "Music Finished \n";

    return 0;
}