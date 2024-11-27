#ifndef IDLE_STATE_H
#define IDLE_STATE_H

#include "VendingMachineState.h"

class IdleState : public VendingMachineState {
public:
    void selectProduct(VendingMachine* vendingMachine, const Product& product) override;
    void insertCoin(VendingMachine* vendingMachine, Coin coin) override;
    void insertNote(VendingMachine* vendingMachine, Note note) override;
    void dispenseProduct(VendingMachine* vendingMachine) override;
    void returnChange(VendingMachine* vendingMachine) override;
};

#endif // IDLE_STATE_H
