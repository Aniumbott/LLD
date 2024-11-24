#ifndef LEVEL_H
#define LEVEL_H

#include "ParkingSpot.h"
#include <iostream>
#include <vector>

class Level {
private:
  int floor;
  vector<ParkingSpot> parking_spots;

public:
  Level(int floor, int num_spots) {
    this->floor = floor;
    // Create a mix of different spot types
    for (int i = 0; i < num_spots; i++) {
      VehicleType type;
      if (i % 3 == 0)
        type = VehicleType::CAR;
      else if (i % 3 == 1)
        type = VehicleType::TRUCK;
      else
        type = VehicleType::MOTORCYCLE;

      this->parking_spots.push_back(ParkingSpot(i, type));
    }
  }

  bool park_vehicle(Vehicle *vehicle) {
    if (!vehicle)
      return false;

    for (ParkingSpot &spot : parking_spots) {
      if (spot.is_available() &&
          spot.get_vehicle_type() == vehicle->get_vehicle_type()) {
        try {
          spot.park_vehicle(vehicle);
          return true;
        } catch (const std::exception &e) {
          continue;
        }
      }
    }
    return false;
  }

  bool unpark_vehicle(Vehicle *vehicle) {
    if (!vehicle)
      return false;

    for (ParkingSpot &spot : parking_spots) {
      if (spot.get_parked_vehicle() == vehicle) {
        try {
          spot.unpark_vehicle();
          return true;
        } catch (const std::exception &e) {
          return false;
        }
      }
    }
    return false;
  }

  void display_availability() {
    cout << "Level " << floor << " availability:" << endl;
    for (ParkingSpot &spot : parking_spots) {
      cout << "Spot " << spot.get_spot_number() << " ("
           << (spot.get_vehicle_type() == VehicleType::CAR     ? "CAR"
               : spot.get_vehicle_type() == VehicleType::TRUCK ? "TRUCK"
                                                               : "MOTORCYCLE")
           << "): " << (spot.is_available() ? "Available" : "Occupied") << endl;
    }
    cout << endl;
  }
};

#endif
