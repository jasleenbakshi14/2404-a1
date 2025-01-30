#include "Campsite.h"
#include <iostream>

using namespace std;

Campsite::Campsite(int siteNumber, cat::Category category, const string& description, int maxPeople, double pricePerDay) {
    this->siteNumber = siteNumber;
    this->category = category;
    this->description = description;
    
    // valid values for maxPeople and pricePerDay
    this->maxPeople = (maxPeople >= 1) ? maxPeople : 1;
    this->pricePerDay = (pricePerDay > 0) ? pricePerDay : 1.0;

    numCampers = 0;
}

Campsite::~Campsite() {
}

bool Campsite::addCamper(const string& name, const string& plateNumber, int numPeople, const Date& checkIn, const Date& checkOut) {
    if (numCampers >= MAX_ARRAY) {
        cout << "Error: Campsite is full." << endl;
        return false;
    }
    if (numPeople > maxPeople) {
        cout << "Error: Number of people exceeds the maximum allowed." << endl;
        return false;
    }

    for (int i = 0; i < numCampers; i++) {
        if (!(checkOut.lessThan(campers[i].getCheckIn()) || campers[i].getCheckOut().lessThan(checkIn))) {
            cout << "Error: Date conflict with another camper." << endl;
            return false;
        }
    }
    campers[numCampers] = Camper(name, plateNumber, numPeople, checkIn, checkOut);
    numCampers++;
    cout << "Camper " << name << " added successfully." << endl;
    return true;
}

bool Campsite::removeCamper(const string& name) {
    int index = -1;
    for (int i = 0; i < numCampers; i++) {
        if (campers[i].getName() == name) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Error: Camper not found." << endl;
        return false;
    }

    for (int i = index; i < numCampers - 1; i++) {
        campers[i] = campers[i + 1];
    }
    numCampers--;
    cout << "Camper " << name << " removed successfully." << endl;
    return true;
}

void Campsite::print() const {
    cout << "Site Number: " << siteNumber << endl;
    cout << "Category: " << cat::categoryToString(category) << endl;
    cout << "Description: " << description << endl;
    cout << "Max People: " << maxPeople << endl;
    cout << "Price per Day: $" << pricePerDay << endl;
}

void Campsite::printCampers() const {
    cout << "Campers:" << endl;
    for (int i = 0; i < numCampers; i++) {
        campers[i].print();
    }
}

void Campsite::printCamper(const Date& date) const {
    cout << "Campers on " << date.getMonthName() << " " << date.getDay() << ", " << date.getYear() << ":" << endl;
    bool camperFound = false;
    for (int i = 0; i < numCampers; i++) {
        if (campers[i].getCheckIn().lessThan(date) && date.lessThan(campers[i].getCheckOut())) {
            campers[i].print();
            camperFound = true;
        }
    }
    if (!camperFound) {
        cout << "No camper has reserved the site for the given date." << endl;
    }
}

