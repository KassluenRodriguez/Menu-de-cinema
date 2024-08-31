#pragma once
#include <iostream>
#include <string>
#include "Pelicula.h"
#include "Salas.h"
#include "Horarios.h"
#include<clocale>

class Menu {
private:
    Pelicula* pelicula;
    Salas* salas;
    Horarios* horarios;
    int totalpelis, totalbutacas;
public:
    Menu();
    ~Menu();
    void menus();
    void Archivo(); 
    void Mantenimiento();
    void Reserva();

    void editarsalas();
    void editarpeliculas();
    void editarHorarios();
    
};
Menu::Menu():totalpelis(0),totalbutacas(0) {
    pelicula = new Pelicula[3];
    salas = new Salas[4];
    horarios = new Horarios[3];
}

Menu::~Menu() {
    delete[] pelicula;
    delete[] salas;
    delete[] horarios;
}

void Menu::Archivo() {
    int opcion;
    do {
    cout << " Kassluen Rodríguez Baules" << endl;
    cout << "1-Para salir al menu" << endl;
    cin >> opcion;
    } while (opcion);

}

void Menu::menus() {
    int opcion;
    while (true) {  
        cout << "------Bienvenido a Cinepolis---------" << endl << endl;
        cout << "1- Ir al archivo" << endl;
        cout << "2- Ir a mantenimiento " << endl;
        cout << "3- Reservar " << endl;
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
        case 5:
            cout << "Saliendo del programa..." << endl;
            return; 
        default:
            cout << "Opción inválida. Intente nuevamente." << endl;
            break;
        }
    }
}




void Menu::Mantenimiento() {
    int opcion;
    do {
        cout << "------------Mantenimiento------------" << endl << endl;
        cout << "1- Editar peliculas" << endl;
        cout << "2- Editar salas" << endl;
        cout << "3- Editar duracion" << endl;
        cout << "4- Volver al menu principal" << endl;
        cin >> opcion;
        switch (opcion)
        {
        case 1: {
            editarpeliculas();
            break;
        }
        case 2: {
            editarsalas();
            break;
        }
         case 3: {
             editarHorarios();
             break;
        }
         case 4: {
             menus();
               }
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

    cout << "Cuantas peliculas quiere ingresar: ";
    cin >> totalpelis;
    if (totalpelis < 1 || totalpelis > 3) {
        cout << "Numero invalido de peliculas. Intente nuevamente." << endl;
        return;
    }
    for (int i = 0; i < totalpelis; i++) {
        cin.ignore();
        cout << "Digite nombre de la pelicula " << i + 1 << endl;
        getline(cin, nombre);
        pelicula[i].setnombre(nombre);

        cout << "Digite el año de la pelicula: " << i + 1 << endl;
        cin >> año;
        pelicula[i].setaño(año);

        cout << "Digite la duracion de la pelicula: " << i + 1 << endl;
        cin >> duracion;
        pelicula[i].setduracion(duracion);
        cin.ignore();
        cout << "Digite el país de la pelicula: " << i + 1 << endl;
        getline(cin, pais);
        pelicula[i].setpais(pais);

        cout << "Digite una reseña de la pelicula del 1 al 10: " << endl;
        cin >> reseña;
        pelicula[i].setreviews(reseña);
    }
}

void Menu::editarsalas() {
    int sala;
    cout << "Digite el numero de sala (0-3): " << endl;
    cin >> sala;

    if (sala < 0 || sala >= 4) {
        cout << "Numero de sala invalido. Intente nuevamente." << endl;
        return;
    }
    
    cout << "Digite la cantidad de butacas que tendra la sala: " << endl;
    cin >> totalbutacas;

    totalbutacas = totalbutacas / 2;
    int iniciobutacas = 50 - totalbutacas / 2;
    int finbutacas = iniciobutacas + totalbutacas;
    int contador = 0;

    for (int i = iniciobutacas; i < finbutacas; i++) {
        for (int j = iniciobutacas; j < finbutacas; j++) {
            salas[sala].setnumero(sala);
            contador++;
            salas[sala].setcantidad(i, j, contador);
        }
    }
    contador = 0;
    for (int i = iniciobutacas; i < finbutacas; i++) {
        char letra = 'A' + (i - iniciobutacas); 
        for (int j = iniciobutacas; j < finbutacas; j++) {
            cout << letra << salas[sala].getcantidad(i, j) << " ";
        }
        cout << endl;
    }
}

void Menu:: editarHorarios() {
    int opcion;
    do {
        cout << "1-Ingresar fecha" << endl;
        cout << "2-Ingresar hora inicial y final" << endl;
        cout << "3-volver al menu principal" << endl;
        cin >> opcion;
        switch (opcion)
        {
         case 1: {
            if (totalpelis > 0) {
                int dia, mes, año;
                for (int i = 0; i < totalpelis; i++) {
                    cout << "Ingrese la fecha del estreno de la  pelicula en formato DD/MM/AAAA para " << pelicula[i].getnombre() << ": ";
                    cin >> dia >> mes >> año;
                    horarios[i].setfecha(dia, mes, año);
                    cout << "Fecha guardada: " << horarios[i].getfecha() << endl;
                }
            }
            else {
                cout << "No se han ingresado peliculas." << endl;
            }
            break;
         }
          case 2: {
            int horaInicial, horafinal;
            for (int i = 0; i < totalpelis; i++) {
                cout << "Digite el hora inicial de la pelicula  " << pelicula[i].getnombre() << endl;
                cin >> horaInicial;
                horarios[i].sethoraIni(horaInicial);
                horafinal = horaInicial + pelicula[i].getduracion();
                horarios[i].sethorafinal(horafinal);
                cout << "La pelicula iniciara a las " << horarios[i].gethoraIni() << " y terminara a las "
                    << horarios[i].gethorafinal() << endl;
            }

                break;
          }
          case 3: {
              menus();
          break;
          }
        }

        
    } while (true);
}

void Menu::Reserva() {
    for (int i = 0; i < totalpelis; i++) {
        cout << "Que pelicula quiere reservar? " << endl;

        cout << i + 1 << "-" << pelicula[i].getnombre() << endl;
        cout << "En la sala : " << salas[i].getnumero() << endl;
        cout << "Fecha: " << horarios[i].getfecha() << endl;
        cout << "Hora: " << horarios[i].gethoraIni() << " a " << horarios[i].gethorafinal() << endl;

        int filaInicio = 50 - totalbutacas / 2;
     int filaFin = filaInicio + totalbutacas;

     cout << "Distribución de butacas:" << endl;

      for (int fila = filaInicio; fila < filaFin; fila++) {
        for (int col = filaInicio; col < filaFin; col++) {
            if (salas[i].esOcupada(fila, col)) {
                cout << "X "; 
            }
            else {
                cout << char('A' + (fila - filaInicio)) << " "; 
            }
        }
        cout << endl;
      }
     }

}
