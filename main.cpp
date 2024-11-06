#include <iostream>
#include <thread>
#include <windows.h>
#include <string>
#include <chrono>

using namespace std;

void moveToPosition(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hConsole, pos);
}

void animalRunning(string track, string animal, int line) {
    int steps = 0;
    string trackOn = track;


    srand(static_cast<unsigned int>(time(0)) + line);  //Setting randomizator. "line" to use differents random seeds

    while (steps < trackOn.length()) {
        system("cls");


        moveToPosition(steps, line);// Setting position

        if (trackOn[steps] == '_') {
            trackOn[steps] = animal[0]; //Showing position
            cout << trackOn;

            // Pausa aleatoria entre 100 ms y 500 ms
            int randomPause = 100 + rand() % 400;  // Pause between 100 and 500 ms
            this_thread::sleep_for(chrono::milliseconds(randomPause));

            // Limpiar el símbolo del animal de la posición actual
            trackOn[steps] = '_';
        }

        steps++;

        // Determining the winner
        if (steps == trackOn.length()) {
            moveToPosition(0, line + 1);
            cout << animal << " win!! >:D" << endl;
            break;
        }
    }
}
int main() {
    // ATTENTION PLEASE!! :D
    // NOTE: Compile it with g++ -o main.exe main.cpp -pthread to avoid compilation problems!!! ;)
    //Drawing the race course :) haha
    string track = "_______________________________________________________________________";

    //Calling the function!!!
    thread duck(animalRunning, track, "D", 2);
    thread goose(animalRunning, track, "G", 3);
    thread swan(animalRunning, track, "S", 4);

    duck.join();
    goose.join();
    swan.join();

    return 0;
}
