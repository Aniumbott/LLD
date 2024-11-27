
#ifndef VENDING_MACHINE_H
#define VENDING_MACHINE_H

#include "DispenseState.h"
#include "IdleState.h"
#include "Inventory.h"
#include "ReadyState.h"
#include "ReturnChangeState.h"
#include "VendingMachineState.h"
#include <memory>

class VendingMachine {
public:
  static VendingMachine &getInstance();

  void selectProduct(const Product &product);
  void insertCoin(Coin coin);
  void insertNote(Note note);
  void dispenseProduct();
  void returnChange();

  void setState(VendingMachineState *state);
  void addCoin(Coin coin);
  void addNote(Note note);
  void resetPayment();
  void resetSelectedProduct();

  Inventory inventory;
  double totalPayment;
  Product *selectedProduct;

  IdleState idleState;
  ReadyState readyState;
  DispenseState dispenseState;
  ReturnChangeState returnChangeState;

private:
  VendingMachine();
  static VendingMachine instance;
  VendingMachineState *currentState;
};

#endif // VENDING_MACHINE_H
