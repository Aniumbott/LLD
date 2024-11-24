#ifndef PARKING_SPOT_H
#define PARKING_SPOT_H

#include "Vehicle.h"
#include <stdexcept>

class ParkingSpot {
private:
  Vehicle *parked_vehicle;
  int spot_number;
  VehicleType vehicle_type;

public:
  ParkingSpot(int spot_number, VehicleType type = VehicleType::CAR) {
    this->spot_number = spot_number;
    this->vehicle_type = type;
    this->parked_vehicle = nullptr;
  }

  bool is_available() { return parked_vehicle == nullptr; }

  void park_vehicle(Vehicle *vehicle) {
    if (!vehicle) {
      throw std::invalid_argument("Cannot park null vehicle");
    }
    if (!is_available()) {
      throw std::runtime_error("Spot is already occupied");
    }
    if (vehicle_type != vehicle->get_vehicle_type()) {
      throw std::invalid_argument("Invalid vehicle type for this spot");
    }
    this->parked_vehicle = vehicle;
  }

  void unpark_vehicle() {
    if (!parked_vehicle) {
      throw std::runtime_error("No vehicle to unpark");
    }
    this->parked_vehicle = nullptr;
  }

  VehicleType get_vehicle_type() const { return vehicle_type; }
  Vehicle *get_parked_vehicle() const { return parked_vehicle; }
  int get_spot_number() const { return spot_number; }
};

#endif

