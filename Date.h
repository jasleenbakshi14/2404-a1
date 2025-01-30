#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

using namespace std;

class Date {
public:
    Date();
    Date(int year, int month, int day);
    Date(Date&);

    void setDay(int);
    void setMonth(int);
    void setYear(int);
    void setDate(int, int, int);
    void setDate(Date&);

    int getDay();
    int getMonth();
    int getYear();
    string getMonthName();
    string getShortMonthName();

    bool isLeapYear(int year);

    bool lessThan(const Date&);
    bool equals(const Date&);

    //void print();
    int convertToDays();

private:
    int getDaysInMonth();

    int day;
    int month;
    int year;
};

#endif

