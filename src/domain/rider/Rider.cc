#include "Rider.h"

Rider::Rider(int id, double rating, const std::string& preferences)
    : id(id), rating(rating), preferences(preferences) {}

int Rider::getId() const {
    return id;
}

double Rider::getRating() const {
    return rating;
}

const std::string& Rider::getPreferences() const {
    return preferences;
}
