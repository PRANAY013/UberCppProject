#ifndef TRIP_H
#define TRIP_H

class Trip {
public:
    enum class State {
        Requested,
        Assigned,
        Enroute,
        Pickup,
        InRide,
        Completed,
        Canceled
    };

    Trip(State state);

    State getState() const;
    void setState(State newState);

private:
    State state;
};

#endif // TRIP_H
