#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Prototipos de funciones
void Juego();
void MostrarTablero(const vector<vector<char>>& tablero);
bool EsGanador(const vector<vector<char>>& tablero, char jugador);
bool EsEmpate(const vector<vector<char>>& tablero);
pair<int, int> Jugada();
bool EsNumero(const string& str);

int main() {
    cout << "Bienvenido al juego de Tres en Raya!" << endl;
    cout << "===================================" << endl;
    cout << "Reglas del juego:" << endl;
    cout << "- Dos jugadores se turnan para marcar casillas en un tablero de 3x3." << endl;
    cout << "- El objetivo es colocar tres fichas del mismo tipo en línea, ya sea horizontal, vertical o diagonal." << endl;
    cout << "- El primer jugador usa 'O' y el segundo jugador usa 'X'." << endl;
    cout << "- Ingrese la posicion de su jugada utilizando numeros del 1 al 3 para fila y columna." << endl;
    cout << "===================================" << endl;

    string opcion;
    do {
        Juego();
        cout << endl;
        cout << "Si quiere seguir jugando presione Y, de lo contrario presione cualquier otra tecla: ";
        cin >> opcion;
        system("cls"); // Se limpia la consola
    } while (opcion == "Y" || opcion == "y");
}

void Juego() {
    vector<string> jugador(2);
    vector<vector<char>> tablero(3, vector<char>(3, ' '));
    char OX[2] = { 'O', 'X' };
    int turno = 0;

    for (int i = 0; i < 2; i++) {
        cout << "Nombre del jugador " << i + 1 << ": ";
        cin >> jugador[i];
        cout << endl;
    }

    while (turno < 9) {
        MostrarTablero(tablero);
        int jugadorActual = turno % 2;
        cout << "Es el turno de " << jugador[jugadorActual] << " -> | " << OX[jugadorActual] << " |" << endl;
        auto [fila, columna] = Jugada();

        if (tablero[fila][columna] != ' ') {
            cout << "Jugada invalida, esa posicion ya esta ocupada." << endl;
            continue;
        }

        tablero[fila][columna] = OX[jugadorActual];

        if (EsGanador(tablero, OX[jugadorActual])) {
            MostrarTablero(tablero);
            cout << "El ganador es " << jugador[jugadorActual] << endl;
            return;
        }

        if (EsEmpate(tablero)) {
            MostrarTablero(tablero);
            cout << "Es un empate." << endl;
            return;
        }

        turno++;
    }
}

void MostrarTablero(const vector<vector<char>>& tablero) {
    system("cls");
    cout << " " << tablero[0][0] << " | " << tablero[0][1] << " | " << tablero[0][2] << " " << endl;
    cout << "---+---+---" << endl;
    cout << " " << tablero[1][0] << " | " << tablero[1][1] << " | " << tablero[1][2] << " " << endl;
    cout << "---+---+---" << endl;
    cout << " " << tablero[2][0] << " | " << tablero[2][1] << " | " << tablero[2][2] << " " << endl;
}

bool EsGanador(const vector<vector<char>>& tablero, char jugador) {
    for (int i = 0; i < 3; i++) {
        if (tablero[i][0] == jugador && tablero[i][1] == jugador && tablero[i][2] == jugador)
            return true;
        if (tablero[0][i] == jugador && tablero[1][i] == jugador && tablero[2][i] == jugador)
            return true;
    }
    if (tablero[0][0] == jugador && tablero[1][1] == jugador && tablero[2][2] == jugador)
        return true;
    if (tablero[0][2] == jugador && tablero[1][1] == jugador && tablero[2][0] == jugador)
        return true;
    return false;
}

bool EsEmpate(const vector<vector<char>>& tablero) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (tablero[i][j] == ' ')
                return false;
    return true;
}

pair<int, int> Jugada() {
    string jugada;
    int fila, columna;
    do {
        cout << "Ingrese la jugada (primer numero para la fila, segundo numero para la columna, ambos del 1 al 3: ";
        cin >> jugada;
        if (jugada.length() == 2 && EsNumero(jugada.substr(0, 1)) && EsNumero(jugada.substr(1, 1))) {
            fila = jugada[0] - '1';
            columna = jugada[1] - '1';
            if (fila >= 0 && fila < 3 && columna >= 0 && columna < 3)
                break;
        }
        cout << "Jugada invalida, ingrese números entre 1 y 3." << endl;
    } while (true);
    return { fila, columna };
}

bool EsNumero(const string& str) {
    for (char c : str)
        if (!isdigit(c))
            return false;
    return true;
}
