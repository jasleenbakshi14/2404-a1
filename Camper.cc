#include "Camper.h"
#include <iostream>

using namespace std;

Camper::Camper() {
    name = "John Doe";
    plate_number = "XXX-000";
    num_people = 1;
    check_in = Date(); 
    check_out = Date();
}

Camper::Camper(const string& inName, const string& inPlateNumber, int inNumPeople, const Date& inCheckIn, const Date& inCheckOut) {
    name = inName;
    plate_number = inPlateNumber;
    num_people = inNumPeople;
    check_in = inCheckIn;
    check_out = inCheckOut;
}

const Date& Camper::getCheckIn() const {
    return check_in;
}

const Date& Camper::getCheckOut() const {
    return check_out;
}

string Camper::getName() const {
    return name;
}

int Camper::getNumPeople() const {
    return num_people;
}

bool Camper::checkInEarlierThan(Camper& cam) {
    return check_in.lessThan(cam.getCheckIn());
}

// Print function
void Camper::print() const {
    cout << "Name: " << name << endl;
    cout << "License Plate: " << plate_number << endl;
    cout << "Number of People: " << num_people << endl;
    cout << "Check-in Date: ";
    check_in.print();
    cout << "Check-out Date: ";
    check_out.print();
}
