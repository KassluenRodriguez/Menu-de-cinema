#pragma once
#include <iostream>
using namespace std;

class Rooms {
private:
    float price = 9;
    float totalReservationPrice = 0;
    int number;
    int** seats;
    bool** occupied;
    int rows, columns;
    int assignedMovie;

    void freeMemory();

public:
    Rooms(float _price = 4.0, int _number = 0, int rows = 100, int columns = 100, int assignedMovie = 0);

    ~Rooms();

    void setPrice(float _price) { price = _price; }
    float getPrice() const { return price; }

    void addReservation(float amount) { totalReservationPrice += amount; }
    float getTotalReservations() const { return totalReservationPrice; }

    void setNumber(int _number) { number = _number; }
    int getNumber() const { return number; }

    void setSeats(int row, int column, int value) { seats[row][column] = value; }
    int getSeats(int row, int column) const { return seats[row][column]; }

    void setDimensions(int rows, int columns);
    int getRows() const { return rows; }
    int getColumns() const { return columns; }

    void setAssignedMovie(int movieIndex) {
        assignedMovie = movieIndex;
    }
    int getAssignedMovie() const {
        return assignedMovie;
    }

    void markOccupied(int i, int j) { occupied[i][j] = true; }
    void unmarkOccupied(int i, int j) { occupied[i][j] = false; }
    bool isOccupied(int i, int j) const { return occupied[i][j]; }
};

Rooms::Rooms(float _price, int _number, int rows, int columns, int assignedMovie)
    : price(_price), number(_number), rows(rows), columns(columns), assignedMovie(assignedMovie) {
    srand(time(0));
    seats = new int* [rows];
    occupied = new bool* [rows];
    for (int i = 0; i < rows; ++i) {
        seats[i] = new int[columns] {};
        occupied[i] = new bool[columns];
        for (int j = 0; j < columns; ++j)
            occupied[i][j] = (rand() % 2 == 0);
    }
}

Rooms::~Rooms() {
    freeMemory();
}

void Rooms::freeMemory() {
    for (int i = 0; i < rows; ++i) {
        delete[] seats[i];
        delete[] occupied[i];
    }
    delete[] seats;
    delete[] occupied;
}

void Rooms::setDimensions(int rows, int columns) {
    freeMemory();
    this->rows = rows;
    this->columns = columns;
    seats = new int* [rows];
    occupied = new bool* [rows];
    for (int i = 0; i < rows; ++i) {
        seats[i] = new int[columns] {};
        occupied[i] = new bool[columns];
        for (int j = 0; j < columns; ++j)
            occupied[i][j] = (rand() % 2 == 0);
    }
}
