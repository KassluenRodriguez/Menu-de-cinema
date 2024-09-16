#pragma once
#include <iostream>
#include <clocale>
#include <ctime>
#include <string>
#include "Movie.h"
#include "Salas.h"
#include "Horarios.h"
using namespace std;

class Menu {
private:
    Movie* movie;
    Rooms* rooms;
    Schedule* schedules;

    int totalMovies, totalSeats;
    int consecutives[100];
    int totalReservations;
public:
    Menu();
    ~Menu();
    void menus();
    void File();
    void Maintenance();
    int Reservation();
    void Sale();

    void editRooms();
    void editMovies();
    void editSchedules();
    int addconsecutives();

};

Menu::Menu() : totalMovies(0), totalSeats(0), totalReservations(0) {
    movie = new Movie[3];
    rooms = new Rooms[4];
    schedules = new Schedule[3];
    for (int i = 0; i < 100; ++i) {
        consecutives[i] = 0;
    }
}

Menu::~Menu() {
    delete[] movie;
    delete[] rooms;
    delete[] schedules;
}

int Menu::addconsecutives() {
    static int reservationNumber = 1000;
    return reservationNumber++;
}

void Menu::menus() {
    int option;
    do {
        cout << "------Bienvenido a Cinepolis---------" << endl << endl;
        cout << "1- Ir al archivo" << endl;
        cout << "2- Ir a mantenimiento " << endl;
        cout << "3- Reservar " << endl;
        cout << "4- Venta " << endl;
        cout << "5- Salir" << endl;
        cin >> option;
        cout << endl;
        cout << "-------------------------------------" << endl << endl;

        if (option == 1) {
            File();
        }
        else if (option == 2) {
            Maintenance();
        }
        else if (option == 3) {
            Reservation();
        }
        else if (option == 4) {
            Sale();
        }
        else if (option == 5) {
            cout << "Saliendo del programa..." << endl;
            exit(0);
        }
        else {
            cout << "Opción inválida. Intente nuevamente." << endl;
        }

    } while (true);
}


void Menu::File() {
    int option;
    do {
        cout << "Hola, mi nombre es Kassluen Rodriguez Baules," << endl;
        cout << "soy estudiante de la Universidad Nacional," << endl;
        cout << "el cual soy el creador de este proyecto," << endl;
        cout << "con esfuerzo y mucha insistencia a los compañeros y al profe, lo realice" << endl << endl;
        cout << "1-Volver al menu principal" << endl;
        cin >> option;

        if (option == 1) {
            menus();
            break;
        }
    } while (true);
}

void Menu::Maintenance() {
    int option;
    do {
        cout << "------------Mantenimiento------------" << endl << endl;
        cout << "1- Editar películas" << endl;
        cout << "2- Editar salas" << endl;
        cout << "3- Editar horarios" << endl;
        cout << "4- Volver al menú principal" << endl;
        cin >> option;

        if (option == 1) {
            editMovies();
        }
        else if (option == 2) {
            editRooms();
        }
        else if (option == 3) {
            editSchedules();
        }
        else if (option == 4) {
            menus();
        }
        else {
            cout << "opcion invalida....." << endl;
        }
    } while (true);
}

void Menu::editMovies() {
    string name, country;
    int year, duration, review;

    cout << "¿Cuántas películas quiere ingresar?: ";
    cin >> totalMovies;
    if (totalMovies < 1 || totalMovies > 3) {
        cout << "Número inválido de películas. Intente nuevamente." << endl;
        return;
    }
    for (int i = 0; i < totalMovies; i++) {
        cin.ignore();
        cout << "Digite el nombre de la película " << i + 1 << endl;
        getline(cin, name);
        movie[i].setName(name);

        cout << "Digite el año de la película: " << i + 1 << endl;
        cin >> year;
        movie[i].setYear(year);

        cout << "Digite la duración de la película: " << i + 1 << endl;
        cin >> duration;
        movie[i].setDuration(duration);
        cin.ignore();
        cout << "Digite el país de la película: " << i + 1 << endl;
        getline(cin, country);
        movie[i].setCountry(country);

        cout << "Digite una reseña de la película del 1 al 10: " << endl;
        cin >> review;
        movie[i].setReviews(review);
    }
}


void Menu::editRooms() {
    int room;
    if (totalMovies == 0) {
        cout << "No hay películas disponibles..., intente nuevamente" << endl;
        return;
    }

    cout << "Digite el número de sala (1-3): " << endl;
    cin >> room;

    if (room < 1 || room > 3) {
        cout << "Número de sala inválido. Intente nuevamente." << endl;
        return;
    }

    int rows, columns;
    cout << "Digite el número de filas de butacas: ";
    cin >> rows;
    cout << "Digite el número de columnas de butacas: ";
    cin >> columns;

    rooms[room - 1].setDimensions(rows, columns);

    cout << "Asignar película a esta sala. Películas disponibles:" << endl;
    for (int i = 0; i < totalMovies; i++) {
        cout << i + 1 << ". " << movie[i].getName() << endl;
    }
    int assignedMovie;
    cin >> assignedMovie;
    assignedMovie--;
    rooms[room - 1].setNumber(assignedMovie);
}

void Menu::editSchedules() {
    int option;
    do {
        cout << "1- Ingresar fecha" << endl;
        cout << "2- Ingresar hora inicial y final" << endl;
        cout << "3- Volver al menú principal" << endl;
        cin >> option;

        if (option == 1) {
            if (totalMovies > 0) {
                int day, month, year;
                for (int i = 0; i < totalMovies; i++) {
                    cout << "Ingrese la fecha del estreno de " << movie[i].getName() << " en formato DD/MM/AAAA: ";
                    cin >> day >> month >> year;
                    schedules[i].setDate(day, month, year);
                    cout << "Fecha guardada: " << schedules[i].getDate() << endl;
                }
            }
            else {
                cout << "No se han ingresado películas." << endl;
            }
        }
        else if (option == 2) {
            int startHour, endHour;
            for (int i = 0; i < totalMovies; i++) {
                cout << "Digite la hora inicial de la película " << movie[i].getName() << endl;
                cin >> startHour;
                schedules[i].setStartHour(startHour);
                endHour = startHour + movie[i].getDuration();
                schedules[i].setEndHour(endHour);
                cout << "La película iniciará a las " << schedules[i].getStartHour() << " y terminará a las " << schedules[i].getEndHour() << endl;
            }
        }
        else if (option == 3) {
            menus();
        }
        else {
            cout << "Opción inválida....." << endl;
        }
    } while (true);
}

int Menu::Reservation() {
    if (totalMovies == 0) {
        cout << "Ingrese una película..." << endl;
        return -1;
    }

    cout << "¿Qué película quiere reservar? " << endl;
    for (int i = 0; i < totalMovies; ++i)
        cout << i + 1 << " - " << movie[i].getName() << endl;

    int selection;
    cin >> selection;

    int selectedMovie = selection - 1;
    Rooms& room = rooms[selectedMovie];

    cout << "Ha seleccionado la película: " << movie[selectedMovie].getName() << endl;
    cout << "En la sala: " << room.getNumber() << endl;
    cout << "Fecha: " << schedules[selectedMovie].getDate() << endl;
    cout << "Hora: " << schedules[selectedMovie].getStartHour() << " a " << schedules[selectedMovie].getEndHour() << endl;

    cout << "Distribución de butacas: /ocupadas = O/" << endl;
    cout << "  ";
    for (int col = 1; col <= room.getColumns(); ++col) {
        if (col < 10) { cout << "  " << col << " "; }
        else { cout << " " << col << " "; }
    }
    cout << endl;

    for (int row = 0; row < room.getRows(); ++row) {
        cout << char('A' + row) << "|";
        for (int col = 0; col < room.getColumns(); ++col) {
            if (room.isOccupied(row, col)) {
                cout << " O  ";
            }
            else {
                if (col < 9) {
                    cout << " " << char('A' + row) << (col + 1) << " ";
                }
                else {
                    cout << char('A' + row) << (col + 1) << " ";
                }
            }
        }
        cout << endl;
    }

    cout << "¿Cuántos asientos desea reservar?" << endl;
    int numSeats;
    cin >> numSeats;

    float totalPrice = 0;
    for (int i = 0; i < numSeats; ++i) {
        char rowChar;
        int col;
        cout << "Ingrese fila y columna (ejemplo A1): ";
        cin >> rowChar >> col;
        int row = rowChar - 'A';

        if (room.isOccupied(row, col - 1))
            cout << "Butaca ocupada." << endl;
        else {
            room.markOccupied(row, col - 1);
            totalPrice += room.getPrice();
            cout << "Reservado butaca " << rowChar << col << endl;
        }
    }

    room.addReservation(totalPrice);
    int consecutive = addconsecutives();
    consecutives[totalReservations] = consecutive;
    totalReservations++;

    cout << "Su número de reserva es: " << consecutive << endl << endl;
    return consecutive;
}

void Menu::Sale() {
    int consecutive;

    cout << "Ingrese el número de reserva para proceder con la venta: ";
    cin >> consecutive;

    bool found = false;
    for (int i = 0; i < totalReservations; i++) {
        if (consecutives[i] == consecutive) {
            found = true;

            cout << "El precio total de su reserva es " << rooms[i].getPrice() << " mil " << endl;
            string id, card;
            cout << "Ingrese su cédula: ";
            cin >> id;
            cout << "Ingrese su tarjeta: ";
            cin >> card;

            cout << "Pago exitoso. ¡Gracias por su compra!" << endl;
            consecutives[i] = -1;
            break;
        }
    }
    if (!found) {
        cout << "El número de reserva ingresado no es válido." << endl;
    }
}
