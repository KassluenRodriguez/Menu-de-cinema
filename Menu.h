#pragma once
#include <iostream>
#include <clocale>
#include <ctime>
#include <string>
#include "Pelicula.h"
#include "Salas.h"
#include "Horarios.h"
using namespace std;

class Menu {
private:
    Pelicula* pelicula;
    Salas* salas;
    Horarios* horarios;

    int totalpelis, totalbutacas;
    int consecutivos[100];
    int totalReservas;
public:
    Menu();
    ~Menu();
    void menus();
    void Archivo();
    void Mantenimiento();
    int Reserva();
    void venta();

    void editarsalas();
    void editarpeliculas();
    void editarHorarios();
    int agregarConsecutivo();
    
}; 

Menu::Menu():totalpelis(0),totalbutacas(0),totalReservas(0) {
    pelicula = new Pelicula[3];
    salas = new Salas[4];  
    horarios = new Horarios[3];
    for (int i = 0; i < 100; ++i) {
        consecutivos[i] = 0;
    }
}

Menu::~Menu() {
    delete[] pelicula;
    delete[] salas;
    delete[] horarios;
}

int Menu::agregarConsecutivo() {
    static int consecutivo = 1000;
    return consecutivo++;
}


void Menu::menus() {
    int opcion;
    do {
        cout << "------Bienvenido a Cinepolis---------" << endl << endl;
        cout << "1- Ir al archivo" << endl;
        cout << "2- Ir a mantenimiento " << endl;
        cout << "3- Reservar " << endl;
        cout << "4- Venta " << endl;
        cout << "5- Salir" << endl;
        cin >> opcion;
        cout << endl;
        cout << "-------------------------------------" << endl << endl;

        switch (opcion) {
        case 1:
            Archivo();
            break;

        case 2:
            Mantenimiento();
            break;

        case 3:
            Reserva();
            break;

        case 4: 
            venta();
            break;

        case 5:
            cout << "Saliendo del programa..." << endl;
            exit(0);

         default: {
            cout << "Opci�n inv�lida. Intente nuevamente." << endl;
            break;
         }
        }
        
    } while (true);
}


void Menu::Archivo() {
    int opcion;
    do {
        cout << "Hola, mi nombre es Kassluen Rodriguez Baules," << endl;
        cout << "soy estudiante de la Universidad Nacional," << endl;
        cout << "el cual soy el creador de este proyecto," << endl;
        cout << "con esfuerzo y mucha insistencia a los compa�eros y al profe, lo realice" << endl << endl;
        cout << "1-Volver al menu principal" << endl;
        cin >> opcion;

        if (opcion == 1) {
            menus();
            break;
        }
    } while (true);
}


void Menu::Mantenimiento() {
    int opcion;
    do {
        cout << "------------Mantenimiento------------" << endl << endl;
        cout << "1- Editar pel�culas" << endl;
        cout << "2- Editar salas" << endl;
        cout << "3- Editar horarios" << endl;
        cout << "4- Volver al men� principal" << endl;
        cin >> opcion;
        switch (opcion)
        {
        case 1: 
            editarpeliculas();
            break;
        
        case 2: 
            editarsalas();
            break;
        
        case 3: 
            editarHorarios();
            break;
        
        case 4: 
            menus();
            break;
        
        default: {
            cout << "opcion invalida....." << endl;
            break;
        }
        }
    } while (true);
}


void Menu::editarpeliculas() {
    string nombre, pais;
    int a�o, duracion, rese�a;

    cout << "�Cu�ntas pel�culas quiere ingresar?: ";
    cin >> totalpelis;
    if (totalpelis < 1 || totalpelis > 3) {
        cout << "N�mero inv�lido de pel�culas. Intente nuevamente." << endl;
        return;
    }
    for (int i = 0; i < totalpelis; i++) {
        cin.ignore();
        cout << "Digite el nombre de la pel�cula " << i + 1 << endl;
        getline(cin, nombre);
        pelicula[i].setnombre(nombre);

        cout << "Digite el a�o de la pel�cula: " << i + 1 << endl;
        cin >> a�o;
        pelicula[i].seta�o(a�o);

        cout << "Digite la duraci�n de la pel�cula: " << i + 1 << endl;
        cin >> duracion;
        pelicula[i].setduracion(duracion);
        cin.ignore();
        cout << "Digite el pa�s de la pel�cula: " << i + 1 << endl;
        getline(cin, pais);
        pelicula[i].setpais(pais);

        cout << "Digite una rese�a de la pel�cula del 1 al 10: " << endl;
        cin >> rese�a;
        pelicula[i].setreviews(rese�a);
    }
}

void Menu::editarsalas() {
    int sala;
    if (totalpelis == 0) {
        cout << "no hay peliculas disponibles..., intente nuevamente" << endl;
    }
   
    cout << "Digite el n�mero de sala (1-3): " << endl;
    cin >> sala;

    if (sala < 0 || sala >= 4) {
        cout << "N�mero de sala inv�lido. Intente nuevamente." << endl;
        return;
    }

     int filas, columnas;
     cout << "Digite el n�mero de filas de butacas: ";
     cin >> filas;
     cout << "Digite el n�mero de columnas de butacas: ";
     cin >> columnas;

    salas[sala - 1].setDimension(filas, columnas); 

    cout << "Asignar pel�cula a esta sala. Pel�culas disponibles:" << endl;
    for (int i = 0; i < totalpelis; i++) {
        cout << i + 1 << ". " << pelicula[i].getnombre() << endl;
    }
    int peliculaAsignada;
    cin >> peliculaAsignada;
    peliculaAsignada--; 
    salas[sala-1].setnumero(peliculaAsignada);
}

void Menu::editarHorarios() {
    int opcion;
    do {
        cout << "1- Ingresar fecha" << endl;
        cout << "2- Ingresar hora inicial y final" << endl;
        cout << "3- Volver al men� principal" << endl;
        cin >> opcion;
        switch (opcion) {
        case 1: {
            if (totalpelis > 0) {
                int dia, mes, a�o;
                for (int i = 0; i < totalpelis; i++) {
                    cout << "Ingrese la fecha del estreno de la pel�cula en formato DD/MM/AAAA para " << pelicula[i].getnombre() << ": ";
                    cin >> dia >> mes >> a�o;
                    horarios[i].setfecha(dia, mes, a�o);
                    cout << "Fecha guardada: " << horarios[i].getfecha() << endl;
                }
            }
            else {
                cout << "No se han ingresado pel�culas." << endl;
            }
            break;
         }
         case 2: 
            int horaInicial, horafinal;
            for (int i = 0; i < totalpelis; i++) {
                cout << "Digite la hora inicial de la pel�cula " << pelicula[i].getnombre() << endl;
                cin >> horaInicial;
                horarios[i].sethoraIni(horaInicial);
                horafinal = horaInicial + pelicula[i].getduracion();
                horarios[i].sethorafinal(horafinal);
                cout << "La pelicula iniciara a las " << horarios[i].gethoraIni() << " y terminara a las " << horarios[i].gethorafinal() << endl;
            }

            break;
        
          case 3: 
            menus();
            break;
        
        }


    } while (true);
}

int Menu::Reserva() {
    if (totalpelis == 0) {
        cout << "Ingrese una pelicula..." << endl;
        return -1;
    }

    cout << "�Qu� pel�cula quiere reservar? " << endl;
    for (int i = 0; i < totalpelis; ++i)
        cout << i + 1 << " - " << pelicula[i].getnombre() << endl;

    int seleccion;
    cin >> seleccion;

    int peliculaSeleccionada = seleccion - 1;
    Salas& sala = salas[peliculaSeleccionada];

    cout << "Ha seleccionado la pel�cula: " << pelicula[peliculaSeleccionada].getnombre() << endl;
    cout << "En la sala: " << sala.getnumero() << endl;
    cout << "Fecha: " << horarios[peliculaSeleccionada].getfecha() << endl;
    cout << "Hora: " << horarios[peliculaSeleccionada].gethoraIni() << " a " << horarios[peliculaSeleccionada].gethorafinal() << endl;

    cout << "Distribuci�n de butacas:" << endl;
    for (int fila = 0; fila < sala.getFilas(); ++fila) {
        for (int col = 0; col < sala.getColumnas(); ++col)
            cout << (sala.esOcupada(fila, col) ? "O  " : char('A' + fila) + to_string(col + 1) + " ");
        cout << endl;
    }

    cout << "�Cu�ntos asientos desea reservar?" << endl;
    int cantidadAsientos;
    cin >> cantidadAsientos;

    float totalPrecio = 0;
    for (int i = 0; i < cantidadAsientos; ++i) {
        char filaChar;
        int col;
        cout << "Ingrese fila y columna (ejemplo A1): ";
        cin >> filaChar >> col;
        int fila = filaChar - 'A';

        if (sala.esOcupada(fila, col - 1))
            cout << "Butaca ocupada." << endl;
        else {
            sala.marcarOcupada(fila, col - 1);
            totalPrecio += sala.getprecio();
            cout << "Reservado butaca " << filaChar << col << endl;
        }
    }
     
    sala.agregarReserva(totalPrecio);
    int consecutivo = agregarConsecutivo();
    consecutivos[totalReservas] = consecutivo;
    totalReservas++;

    cout << "Su numero de reserva es: " << consecutivo << endl << endl;
    return consecutivo;
}


void  Menu::venta() {
    int consecutivo;

    cout << "Ingrese el n�mero de reserva para proceder con la venta: ";
    cin>> consecutivo;

    bool encontrado = false;
    for (int i = 0; i < totalReservas; i++) {
        if (consecutivos[i] == consecutivo) {
            encontrado = true;

            cout << "El precio total de su reserva es " << salas[i].getprecio() << "colones" << endl;
            string cedula, tarjeta;
            cout << " ingrese su cedula: ";
            cin >> cedula;
            cout << "ingrese su tarjeta: ";
            cin >> tarjeta;

            cout << "Pago exitoso. Gracias por su compa!" << endl;
            consecutivos[i] = -1;
            break;
        }
    }
    if (!encontrado) {
        cout << "El consecutivo ingresado no es valido." << endl;
    }

}
