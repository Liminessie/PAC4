#include <iostream>
#include <thread>
#include <windows.h>
#include <string>
#include <chrono>
#include <cstdlib>

using namespace std;

// Función para mover el cursor de la consola a una posición específica
void moveToPosition(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hConsole, pos);
}

// Función para que cada animal avance en la pista
void animalRunning(string track, string animal, int line) {
    int steps = 0;
    srand(static_cast<unsigned int>(time(0)) + line);  // Diferente semilla para cada línea/animal

    // Mostrar la pista fija al inicio
    moveToPosition(0, line);
    cout << track;

    while (steps < track.length()) {
        // Mueve el cursor a la posición de cada animal en la línea correspondiente
        moveToPosition(steps, line);

        // Colocar el animal en su posición actual
        cout << animal;

        // Pausa aleatoria entre 100 ms y 500 ms
        int randomPause = 100 + rand() % 400;
        this_thread::sleep_for(chrono::milliseconds(randomPause));

        // Limpiar la posición actual del animal
        moveToPosition(steps, line);
        cout << "_"; // printing the track again...

        steps++;

        // Determinar el ganador cuando el animal alcance el final de la pista
        if (steps == track.length()) {
            moveToPosition(0, 5);
            cout << animal << " WinsS!! >:D" << endl;
            break;
        }
    }
}

int main() {
    system("cls");
    // Definir la pista de la carrera
    string track = "___________________________";

    // creating threads
    thread duck(animalRunning, track, "D", 2);
    thread goose(animalRunning, track, "G", 3);
    thread swan(animalRunning, track, "S", 4);

    // Esperar a que todos los hilos terminen
    duck.join();
    goose.join();
    swan.join();

    return 0;
}
