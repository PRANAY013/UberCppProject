#ifndef RIDER_H
#define RIDER_H

#include <string>

namespace domain {
class Rider {
public:
    Rider(int id, double rating, const std::string& preferences);

    int getId() const;
    double getRating() const;
    const std::string& getPreferences() const;

private:
    int id;
    double rating;
    std::string preferences;
};
} // namespace domain

#endif // RIDER_H
