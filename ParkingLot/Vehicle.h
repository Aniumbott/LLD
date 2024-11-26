#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
using namespace std;

enum VehicleType { NULL_VEHICLE = 0, CAR = 1, TRUCK = 2, MOTORCYCLE = 3 };

class Vehicle {
private:
  string license_plate;
  VehicleType vehicle_type;

public:
  Vehicle(string license_plate, VehicleType vehicle_type) {
    this->license_plate = license_plate;
    this->vehicle_type = vehicle_type;
  }
  VehicleType get_vehicle_type() { return vehicle_type; }
  string get_license_plate() { return license_plate; }
};

class Truck : public Vehicle {
public:
  Truck(string license_plate) : Vehicle(license_plate, VehicleType::TRUCK) {}
};

class Car : public Vehicle {
public:
  Car(string license_plate) : Vehicle(license_plate, VehicleType::CAR) {}
};

class Motorcycle : public Vehicle {
public:
  Motorcycle(string license_plate)
      : Vehicle(license_plate, VehicleType::MOTORCYCLE) {}
};

#endif
