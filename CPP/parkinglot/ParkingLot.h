#ifndef PARKING_LOT_H
#define PARKING_LOT_H

#include "Level.h"
#include <mutex>

class ParkingLot {
private:
  static ParkingLot *instance;
  vector<Level *> levels;
  static mutex mtx;

  ParkingLot() {} // Private constructor

public:
  static ParkingLot *get_instance() {
    if (instance == nullptr) {
      mtx.lock();
      instance = new ParkingLot();
      mtx.unlock();
    }
    return instance;
  }

  void add_level(Level *level) {
    if (level) {
      levels.push_back(level);
    }
  }

  bool park_vehicle(Vehicle *vehicle) {
    if (!vehicle)
      return false;

    for (Level *level : levels) {
      if (level->park_vehicle(vehicle))
        return true;
    }
    return false;
  }

  bool unpark_vehicle(Vehicle *vehicle) {
    if (!vehicle)
      return false;

    for (Level *level : levels) {
      if (level->unpark_vehicle(vehicle))
        return true;
    }
    return false;
  }

  void display_availability() {
    if (levels.empty()) {
      cout << "No levels in parking lot." << endl;
      return;
    }

    for (Level *level : levels) {
      level->display_availability();
    }
  }
};

// Initialize the static instance pointer
ParkingLot *ParkingLot::instance = nullptr;
mutex ParkingLot::mtx;

#endif
