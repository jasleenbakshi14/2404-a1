#ifndef CAMPER_H
#define CAMPER_H

#include <string>
#include "Date.h"

using namespace std;

class Camper {
private:
    string name;
    string plate_number;
    int num_people;
    Date check_in;
    Date check_out;

public:
    Camper();
    Camper(const string& inName, const string& inPlateNumber, int inNumPeople, const Date& inCheckIn, const Date& inCheckOut);

    const Date& getCheckIn() const;
    const Date& getCheckOut() const;
    string getName() const;
    int getNumPeople() const;

    bool checkInEarlierThan(Camper& cam);

    void print() const; 
};

#endif

