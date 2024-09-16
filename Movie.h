#pragma once
#include <iostream>
using namespace std;

class Movie {
private:
    string name = " ";
    int year = 0;
    float duration = 0.0;
    string country = " ";
    int reviews = 0;
public:
    Movie(string, int, float, string, int);
    ~Movie();
    Movie();

    void setName(string _name);
    string getName() const;

    void setYear(int _year);
    int getYear() const;

    void setDuration(float _duration);
    float getDuration() const;

    void setCountry(string _country);
    string getCountry() const;

    void setReviews(int _reviews);
    int getReviews() const;
};

Movie::Movie(string _name, int _year, float _duration, string _country, int _reviews) {
    name = _name;
    year = _year;
    duration = _duration;
    country = _country;
    reviews = _reviews;
}

Movie::~Movie() {}

Movie::Movie() {}

void Movie::setName(string _name) {
    name = _name;
}

string Movie::getName() const {
    return name;
}

void Movie::setYear(int _year) {
    year = _year;
}

int Movie::getYear() const {
    return year;
}

void Movie::setDuration(float _duration) {
    duration = _duration;
}

float Movie::getDuration() const {
    return duration;
}

void Movie::setCountry(string _country) {
    country = _country;
}

string Movie::getCountry() const {
    return country;
}

void Movie::setReviews(int _reviews) {
    reviews = _reviews;
}

int Movie::getReviews() const {
    return reviews;
}
