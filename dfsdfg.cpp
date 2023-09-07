#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Tamaño de la matriz
const int FILAS = 3;
const int COLUMNAS = 4;

// Función para mostrar la matriz
void mostrar(const vector<vector<char>>& matriz) {
    cout << "Matriz del área:" << endl;
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

// Función para contar las filas sin muertos vivientes
int contarFilasSinMuertos(const vector<vector<char>>& matriz) {
    int contador = 0;
    for (int i = 0; i < FILAS; i++) {
        bool tieneMuerto = false;
        for (int j = 0; j < COLUMNAS; j++) {
            if (matriz[i][j] == 'x') {
                tieneMuerto = true;
                break;
            }
        }
        if (!tieneMuerto) {
            contador++;
        }
    }
    return contador;
}

// Función para contar las columnas sin muertos vivientes
int contarColumnasSinMuertos(const vector<vector<char>>& matriz) {
    int contador = 0;
    for (int j = 0; j < COLUMNAS; j++) {
        bool tieneMuerto = false;
        for (int i = 0; i < FILAS; i++) {
            if (matriz[i][j] == 'x') {
                tieneMuerto = true;
                break;
            }
        }
        if (!tieneMuerto) {
            contador++;
        }
    }
    return contador;
}

// Función para determinar las coordenadas de los muertos vivientes
void coordenadas(const vector<vector<char>>& matriz, vector<int>& filas, vector<int>& columnas) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (matriz[i][j] == 'x') {
                filas.push_back(i);
                columnas.push_back(j);
            }
        }
    }
}

// Función para contar la cantidad de muertos vivientes
int contarMuertos(const vector<vector<char>>& matriz) {
    int contador = 0;
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (matriz[i][j] == 'x') {
                contador++;
            }
        }
    }
    return contador;
}

// Función para determinar si dos o más muertos vivientes están en la primera columna
bool muertosEnPrimera(const vector<vector<char>>& matriz) {
    int contadorMuertos = 0;
    for (int i = 0; i < FILAS; i++) {
        if (matriz[i][0] == 'x') {
            contadorMuertos++;
        }
    }
    return contadorMuertos >= 2;
}

// Función para generar la posición aleatoria de los muertos vivientes
void generarAleatorios(vector<vector<char>>& matriz) {
    srand(static_cast<unsigned int>(time(nullptr)));
    int cantidadMuertos = rand() % (FILAS * COLUMNAS); // Número aleatorio de muertos vivientes
    for (int i = 0; i < cantidadMuertos; i++) {
        int fila = rand() % FILAS;
        int columna = rand() % COLUMNAS;
        matriz[fila][columna] = 'x'; // Coloca un muerto viviente en la posición aleatoria
    }
}

int main() {
    vector<vector<char>> mapa(FILAS, vector<char>(COLUMNAS, 'o')); // Matriz inicialmente llena de zonas seguras
    generarAleatorios(mapa); // Genera muertos vivientes aleatorios

    // Mostrar la matriz que describe el área
    mostrar(mapa);

    // Contar filas sin muertos vivientes
    int filasSinMuertos = contarFilasSinMuertos(mapa);
    cout << "Número de filas sin muertos vivientes: " << filasSinMuertos << endl;

    // Contar columnas sin muertos vivientes
    int columnasSinMuertos = contarColumnasSinMuertos(mapa);
    cout << "Número de columnas sin muertos vivientes: " << columnasSinMuertos << endl;

    // Determinar las coordenadas de los muertos vivientes
    vector<int> filasMuertos, columnasMuertos;
    coordenadas(mapa, filasMuertos, columnasMuertos);
    cout << "Coordenadas de los muertos vivientes:" << endl;
    for (size_t i = 0; i < filasMuertos.size(); i++) {
        cout << "Muerto viviente en fila " << filasMuertos[i] << ", columna " << columnasMuertos[i] << endl;
    }

    // Mostrar la cantidad de muertos vivientes
    int muertos = contarMuertos(mapa);
    cout << "Cantidad de muertos vivientes: " << muertos << endl;

    // Determinar si dos o más muertos vivientes están en la primera columna
    if (muertosEnPrimera(mapa)) {
        cout << "No es posible entrar al complejo." << endl;
    } else {
        cout << "Es posible entrar al complejo." << endl;
    }

    return 0;
}
