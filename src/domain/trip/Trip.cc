#include "Trip.h"

Trip::Trip(State state)
    : state(state) {}

Trip::State Trip::getState() const {
    return state;
}
