#pragma once
#include <iostream>
using namespace std;

class Salas {
private:
    float precio = 40.0000;
    float totalPrecioReservas = 0;
    int numero;
    int** cantidad;
    bool** ocupadas;
    int filas, columnas;
    int peliculaAsignada;

    void liberarMemoria();  

public:
    Salas(float _precio = 4.0, int _numero = 0, int filas = 100, int columnas = 100);
    ~Salas();

    void setprecio(float _precio) { precio = _precio; }
    float getprecio() const { return precio; }

    void agregarReserva(float monto) { totalPrecioReservas += monto; }
    float getTotalReservas() const { return totalPrecioReservas; }

    void setnumero(int _numero) { numero = _numero; }
    int getnumero() const { return numero; }

    void setcantidad(int fila, int columna, int valor) { cantidad[fila][columna] = valor; }
    int getcantidad(int fila, int columna) const { return cantidad[fila][columna]; }

    void setDimension(int filas, int columnas);
    int getFilas() const { return filas; }
    int getColumnas() const { return columnas; }

    void setPeliculaAsignada(int indicePelicula) {
        peliculaAsignada = indicePelicula;
    }
    int getPeliculaAsignada() const {
        return peliculaAsignada;
    }

    void marcarOcupada(int i, int j) { ocupadas[i][j] = true; }
    void desmarcarOcupada(int i, int j) { ocupadas[i][j] = false; }
    bool esOcupada(int i, int j) const { return ocupadas[i][j]; }
};

Salas::Salas(float _precio, int _numero, int filas, int columnas) 
    : precio(_precio), numero(_numero), filas(filas), columnas(columnas) {
    srand(time(0));
    cantidad = new int*[filas];
    ocupadas = new bool*[filas];
    for (int i = 0; i < filas; ++i) {
        cantidad[i] = new int[columnas]{};
        ocupadas[i] = new bool[columnas];
        for (int j = 0; j < columnas; ++j)
            ocupadas[i][j] = (rand() % 2 == 0);
    }
}

Salas::~Salas() {
    liberarMemoria();
}

void Salas::liberarMemoria() {
    for (int i = 0; i < filas; ++i) {
        delete[] cantidad[i];
        delete[] ocupadas[i];
    }
    delete[] cantidad;
    delete[] ocupadas;
}

void Salas::setDimension(int filas, int columnas) {
    liberarMemoria();
    this->filas = filas;
    this->columnas = columnas;
    cantidad = new int*[filas];
    ocupadas = new bool*[filas];
    for (int i = 0; i < filas; ++i) {
        cantidad[i] = new int[columnas]{};
        ocupadas[i] = new bool[columnas];
        for (int j = 0; j < columnas; ++j)
            ocupadas[i][j] = (rand() % 2 == 0);
    }
}