#pragma once
#include <iostream>
using namespace std;
class Pelicula {
private: 
	string nombre = " ";
	int año = 0;
	float duracion = 0.0;
	string pais = " ";
	int reviews = 0;
public:
	Pelicula(string, int, float, string, int);
	~Pelicula();
	Pelicula();
	
	void setnombre(string _nombre);
	string getnombre();

	void setaño(int _año);
	int getaño();
	void setduracion(float);
	float getduracion();

	void setpais(string);
	string getpais();

	void setreviews(int);
	int getreviews();
};



Pelicula::Pelicula(string _nombre, int _año, float _duracion, string _pais, int _reviews) {
	nombre = _nombre;
	año = _año;
	duracion = _duracion;
	pais = _pais; 
	reviews = _reviews;
}
Pelicula::~Pelicula() {}
Pelicula::Pelicula() {}

void Pelicula::setnombre(string _nombre) {
	nombre = _nombre;
}
string  Pelicula::getnombre() {
	return nombre;
}
void Pelicula::setaño(int _año) {
	año = _año;
}
int Pelicula::getaño() {
	return año;
}

void Pelicula::setduracion(float _duracion) {
	duracion = _duracion;
}
float Pelicula::getduracion(){
	return duracion;
}
void Pelicula::setpais(string _pais) {
	pais = _pais;
}
string Pelicula::getpais() {
	return pais;
}
void Pelicula::setreviews(int _reviews) {
	reviews = _reviews;
}
int Pelicula::getreviews() {
	return reviews;
}