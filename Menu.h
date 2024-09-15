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
            cout << "Opción inválida. Intente nuevamente." << endl;
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
        cout << "con esfuerzo y mucha insistencia a los compañeros y al profe, lo realice" << endl << endl;
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
        cout << "1- Editar películas" << endl;
        cout << "2- Editar salas" << endl;
        cout << "3- Editar horarios" << endl;
        cout << "4- Volver al menú principal" << endl;
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
    int año, duracion, reseña;

    cout << "¿Cuántas películas quiere ingresar?: ";
    cin >> totalpelis;
    if (totalpelis < 1 || totalpelis > 3) {
        cout << "Número inválido de películas. Intente nuevamente." << endl;
        return;
    }
    for (int i = 0; i < totalpelis; i++) {
        cin.ignore();
        cout << "Digite el nombre de la película " << i + 1 << endl;
        getline(cin, nombre);
        pelicula[i].setnombre(nombre);

        cout << "Digite el año de la película: " << i + 1 << endl;
        cin >> año;
        pelicula[i].setaño(año);

        cout << "Digite la duración de la película: " << i + 1 << endl;
        cin >> duracion;
        pelicula[i].setduracion(duracion);
        cin.ignore();
        cout << "Digite el país de la película: " << i + 1 << endl;
        getline(cin, pais);
        pelicula[i].setpais(pais);

        cout << "Digite una reseña de la película del 1 al 10: " << endl;
        cin >> reseña;
        pelicula[i].setreviews(reseña);
    }
}

void Menu::editarsalas() {
    int sala;
    if (totalpelis == 0) {
        cout << "no hay peliculas disponibles..., intente nuevamente" << endl;
    }
   
    cout << "Digite el número de sala (1-3): " << endl;
    cin >> sala;

    if (sala < 0 || sala >= 4) {
        cout << "Número de sala inválido. Intente nuevamente." << endl;
        return;
    }

     int filas, columnas;
     cout << "Digite el número de filas de butacas: ";
     cin >> filas;
     cout << "Digite el número de columnas de butacas: ";
     cin >> columnas;

    salas[sala - 1].setDimension(filas, columnas); 

    cout << "Asignar película a esta sala. Películas disponibles:" << endl;
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
        cout << "3- Volver al menú principal" << endl;
        cin >> opcion;
        switch (opcion) {
        case 1: {
            if (totalpelis > 0) {
                int dia, mes, año;
                for (int i = 0; i < totalpelis; i++) {
                    cout << "Ingrese la fecha del estreno de la película en formato DD/MM/AAAA para " << pelicula[i].getnombre() << ": ";
                    cin >> dia >> mes >> año;
                    horarios[i].setfecha(dia, mes, año);
                    cout << "Fecha guardada: " << horarios[i].getfecha() << endl;
                }
            }
            else {
                cout << "No se han ingresado películas." << endl;
            }
            break;
         }
         case 2: 
            int horaInicial, horafinal;
            for (int i = 0; i < totalpelis; i++) {
                cout << "Digite la hora inicial de la película " << pelicula[i].getnombre() << endl;
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

    cout << "¿Qué película quiere reservar? " << endl;
    for (int i = 0; i < totalpelis; ++i)
        cout << i + 1 << " - " << pelicula[i].getnombre() << endl;

    int seleccion;
    cin >> seleccion;

    int peliculaSeleccionada = seleccion - 1;
    Salas& sala = salas[peliculaSeleccionada];

    cout << "Ha seleccionado la película: " << pelicula[peliculaSeleccionada].getnombre() << endl;
    cout << "En la sala: " << sala.getnumero() << endl;
    cout << "Fecha: " << horarios[peliculaSeleccionada].getfecha() << endl;
    cout << "Hora: " << horarios[peliculaSeleccionada].gethoraIni() << " a " << horarios[peliculaSeleccionada].gethorafinal() << endl;

    cout << "Distribución de butacas:" << endl;
    for (int fila = 0; fila < sala.getFilas(); ++fila) {
        for (int col = 0; col < sala.getColumnas(); ++col)
            cout << (sala.esOcupada(fila, col) ? "O  " : char('A' + fila) + to_string(col + 1) + " ");
        cout << endl;
    }

    cout << "¿Cuántos asientos desea reservar?" << endl;
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

    cout << "Ingrese el número de reserva para proceder con la venta: ";
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
