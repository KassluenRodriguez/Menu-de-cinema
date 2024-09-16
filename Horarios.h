#pragma once
#include <iostream>
#include <string>
using namespace std;

class Schedule {
private:
    int day;
    int month;
    int year;
    int startHour;
    int endHour;
public:
    Schedule(int day = 0, int month = 0, int year = 0, int startHour = 0, int endHour = 0);
    ~Schedule();

    void setDate(int _day, int _month, int _year);
    string getDate() const;

    void setStartHour(int _startHour);
    int getStartHour() const;

    void setEndHour(int _endHour);
    int getEndHour() const;
};

Schedule::Schedule(int _day, int _month, int _year, int _startHour, int _endHour)
    : day(_day), month(_month), year(_year), startHour(_startHour), endHour(_endHour) {}

Schedule::~Schedule() {}

void Schedule::setDate(int _day, int _month, int _year) {
    day = _day;
    month = _month;
    year = _year;
}

string Schedule::getDate() const {
    return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
}

void Schedule::setStartHour(int _startHour) {
    startHour = _startHour;
}

int Schedule::getStartHour() const {
    return startHour;
}

void Schedule::setEndHour(int _endHour) {
    endHour = _endHour;
}

int Schedule::getEndHour() const {
    return endHour;
}
