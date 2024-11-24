#include "ParkingLot.h"

int main() {
  ParkingLot *parking_lot = ParkingLot::get_instance();

  // Add levels
  parking_lot->add_level(
      new Level(1, 9)); // 3 spots each for cars, trucks, motorcycles
  parking_lot->add_level(
      new Level(2, 6)); // 2 spots each for cars, trucks, motorcycles

  // Create vehicles
  Car *car = new Car("ABC123");
  Truck *truck = new Truck("XYZ456");
  Motorcycle *motorcycle = new Motorcycle("M1234");

  // Park vehicles
  if (parking_lot->park_vehicle(car))
    cout << "Car parked successfully" << endl;
  if (parking_lot->park_vehicle(truck))
    cout << "Truck parked successfully" << endl;
  if (parking_lot->park_vehicle(motorcycle))
    cout << "Motorcycle parked successfully" << endl;

  cout << "\nInitial parking lot status:" << endl;
  parking_lot->display_availability();

  // Unpark a vehicle
  if (parking_lot->unpark_vehicle(motorcycle))
    cout << "Motorcycle unparked successfully" << endl;

  cout << "\nUpdated parking lot status:" << endl;
  parking_lot->display_availability();

  // Cleanup
  delete car;
  delete truck;
  delete motorcycle;

  return 0;
}
