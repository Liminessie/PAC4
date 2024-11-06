#include <iostream>
#include <thread>
#include <windows.h>
#include <string>
#include <chrono>
#include <cstdlib>

using namespace std;

// to move the console position!!
void moveToPosition(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hConsole, pos);
}


void animalRunning(string track, string animal, int line) {
    int steps = 0;
    srand(static_cast<unsigned int>(time(0)) + line);  // Different random seed for any animal

    // assigning the track position
    moveToPosition(0, line);
    cout << track;

    while (steps < track.length()) {
        if (trackOn[steps] == '_') {

            trackOn[steps] = animal[0];// showing the current position
            cout << trackOn;

            int randomPause = 100 + rand() % 400;
            this_thread::sleep_for(chrono::milliseconds(randomPause));

            // printing the track
            trackOn[steps] = '_';
        }

        steps++;

        // who wins?
        if (steps == track.length()) {
            moveToPosition(0, line + 1);
            cout << animal << " Win!! >:D" << endl;
            break;
        }
    }
}

int main() {
    // defining the "track" :D haha
    string track = "_______________________________________________________________________";

    //
    thread duck(animalRunning, track, "D", 2);
    thread goose(animalRunning, track, "G", 3);
    thread swan(animalRunning, track, "S", 4);

    duck.join();
    goose.join();
    swan.join();

    return 0;
}
