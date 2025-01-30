#ifndef CAMPGROUND_H
#define CAMPGROUND_H

#include "Campsite.h"
#include "defs.h"

class Campground {
private:
    Campsite campsites[MAX_ARRAY];
    int numCampsites;

public:

    Campground();

    void addCampsite(int siteNumber, cat::Category category, const std::string& description, int maxPeople, double pricePerDay);
    void removeCampsite(int siteNumber);
    void addCamper(int siteNumber, const std::string& name, const std::string& plateNumber, int numPeople, const Date& checkIn, const Date& checkOut);
    void removeCamper(int siteNumber, const std::string& name);

    // Print functions
    void printCampsites() const;
    void printCampers(int siteNumber) const;
    void printCampers(const Date& date) const;
    void printCampsitesByCategory(cat::Category category) const;
};

#endif
