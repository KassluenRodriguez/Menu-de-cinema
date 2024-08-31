#pragma once
#include <iostream>
using namespace std;

class Salas {
private:
    float precio;
    int numero;
    int cantidad[100][100]; 
    bool ocupadas[100][100];
public:
 
    Salas(float, int[100][100], int);
    Salas();
    ~Salas();

    
    void setprecio(float);
    float getprecio();

    void setnumero(int);
    int getnumero();

    void setcantidad(int, int, int); 
    int getcantidad(int, int); 

    void marcarOcupada(int i, int j);
    void desmarcarOcupada(int i, int j);
    bool esOcupada(int i, int j);
};

Salas::Salas(float _precio, int _cantidad[100][100], int _numero) {
    precio = _precio;
    numero = _numero;
    
   
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            cantidad[i][j] = _cantidad[i][j];
        }
    }
}

Salas::Salas() {
    precio = 0.0;
    numero = 0;

    
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            cantidad[i][j] = 0;
        }
    }
}


Salas::~Salas() {}


void Salas::setprecio(float _precio) {
    precio = _precio;
}

float Salas::getprecio() {
    return precio;
}

void Salas::setnumero(int _numero) {
    numero = _numero;
}

int Salas::getnumero() {
    return numero;
}


void Salas::setcantidad(int fila, int columna, int valor) {
    if (fila >= 0 && fila < 100 && columna >= 0 && columna < 100) {
        cantidad[fila][columna] = valor;
    }
}

int Salas::getcantidad(int fila, int columna) {
    if (fila >= 0 && fila < 100 && columna >= 0 && columna < 100) {
        return cantidad[fila][columna];
    }
    return -1; 
}

void Salas::marcarOcupada(int i, int j) {
    ocupadas[i][j] = true;
}

void Salas::desmarcarOcupada(int i, int j) {
    ocupadas[i][j] = false;
}

bool Salas::esOcupada(int i, int j) {
    return ocupadas[i][j];
}