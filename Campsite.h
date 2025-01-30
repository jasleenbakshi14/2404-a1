#ifndef CAMPSITE_H
#define CAMPSITE_H

#include <string>
#include "Camper.h"
#include "Category.h"
#include "Date.h"
#include "defs.h"

class Campsite {
private:
    int siteNumber;
    cat::Category category;
    std::string description;
    int maxPeople;
    double pricePerDay;
    Camper campers[MAX_ARRAY];
    int numCampers;

public:
    Campsite(int siteNumber, cat::Category category, const std::string& description, int maxPeople, double pricePerDay);
    ~Campsite();
    
    bool addCamper(const std::string& name, const std::string& plateNumber, int numPeople, const Date& checkIn, const Date& checkOut);
    bool removeCamper(const std::string& name);
    
    void print() const;
    void printCampers() const;
    void printCamper(const Date& date) const;
};

#endif


