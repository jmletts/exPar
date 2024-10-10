#include <iostream>

using namespace std;

const int SIZE = 3;

int main() {
    char tablero[SIZE][SIZE] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char jugador = 'X';
    int fila, columna;
    int movimientos = 0;

    while (movimientos < SIZE * SIZE) {
        // Imprimir el tablero
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                cout << tablero[i][j] << " ";
            }
            cout << endl;
        }

        cout << "Turno del jugador " << jugador << ". Ingresa fila y columna (0, 1 o 2): ";
        cin >> fila >> columna;

        // Verificar movimiento
        if (fila >= 0 && fila < SIZE && columna >= 0 && columna < SIZE && tablero[fila][columna] == ' ') {
            tablero[fila][columna] = jugador;
            movimientos++;

            // Verificar ganador
            for (int i = 0; i < SIZE; ++i) {
                if ((tablero[i][0] == jugador && tablero[i][1] == jugador && tablero[i][2] == jugador) || // filas
                    (tablero[0][i] == jugador && tablero[1][i] == jugador && tablero[2][i] == jugador)) { // columnas
                    cout << "El jugador " << jugador << " ha ganado!" << endl;
                    return 0;
                }
            }
            if ((tablero[0][0] == jugador && tablero[1][1] == jugador && tablero[2][2] == jugador) || // diagonal
                (tablero[0][2] == jugador && tablero[1][1] == jugador && tablero[2][0] == jugador)) {
                cout << "El jugador " << jugador << " ha ganado!" << endl;
                return 0;
            }

            // Cambiar de jugador
            jugador = (jugador == 'X') ? 'O' : 'X';
        } else {
            cout << "Movimiento invalido. Intenta de nuevo." << endl;
        }
    }

    cout << "¡Es un empate!" << endl;
    return 0;
}
