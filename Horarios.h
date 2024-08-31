#pragma once
#include <iostream>
#include <string>
using namespace std;

class Horarios {
private:
    int dia;
    int mes;
    int año;
    int horaIni;
    int horafinal;
public:
    Horarios(int dia = 0, int mes = 0, int año = 0, int horaIni = 0, int horafinal = 0);
    ~Horarios();

    void setfecha(int _dia, int _mes, int _año);
    string getfecha() const;

    void sethoraIni(int _horaIni);
    int gethoraIni() const;

    void sethorafinal(int _horafinal);
    int gethorafinal() const;
};

Horarios::Horarios(int _dia, int _mes, int _año, int _horaIni, int _horafinal)
    : dia(_dia), mes(_mes), año(_año), horaIni(_horaIni), horafinal(_horafinal) {}

Horarios::~Horarios() {}

void Horarios::setfecha(int _dia, int _mes, int _año) {
    dia = _dia;
    mes = _mes;
    año = _año;
}

string Horarios::getfecha() const {
    return to_string(dia) + "/" + to_string(mes) + "/" + to_string(año);
}

void Horarios::sethoraIni(int _horaIni) {
    horaIni = _horaIni;
}

int Horarios::gethoraIni() const {
    return horaIni;
}

void Horarios::sethorafinal(int _horafinal) {
    horafinal = _horafinal;
}

int Horarios::gethorafinal() const {
    return horafinal;
}
