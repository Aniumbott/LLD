#ifndef DISPENSE_STATE_H
#define DISPENSE_STATE_H

#include "VendingMachineState.h"

class DispenseState : public VendingMachineState {
public:
  void selectProduct(VendingMachine *vendingMachine,
                     const Product &product) override;
  void insertCoin(VendingMachine *vendingMachine, Coin coin) override;
  void insertNote(VendingMachine *vendingMachine, Note note) override;
  void dispenseProduct(VendingMachine *vendingMachine) override;
  void returnChange(VendingMachine *vendingMachine) override;
};

#endif // DISPENSE_STATE_H
