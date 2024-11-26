#ifndef READY_STATE_H
#define READY_STATE_H

#include "VendingMachineState.h"

class ReadyState : public VendingMachineState {
public:
  void selectProduct(VendingMachine *vendingMachine,
                     const Product &product) override;
  void insertCoin(VendingMachine *vendingMachine, Coin coin) override;
  void insertNote(VendingMachine *vendingMachine, Note note) override;
  void dispenseProduct(VendingMachine *vendingMachine) override;
  void returnChange(VendingMachine *vendingMachine) override;

private:
  void checkPaymentStatus(VendingMachine *vendingMachine);
};

#endif // READY_STATE_H
