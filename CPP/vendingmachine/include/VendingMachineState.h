#ifndef VENDING_MACHINE_STATE_H
#define VENDING_MACHINE_STATE_H

#include "Product.h"
#include "Coin.h"
#include "Note.h"

class VendingMachine;

class VendingMachineState {
public:
    virtual ~VendingMachineState() {}
    virtual void selectProduct(VendingMachine* vendingMachine, const Product& product) = 0;
    virtual void insertCoin(VendingMachine* vendingMachine, Coin coin) = 0;
    virtual void insertNote(VendingMachine* vendingMachine, Note note) = 0;
    virtual void dispenseProduct(VendingMachine* vendingMachine) = 0;
    virtual void returnChange(VendingMachine* vendingMachine) = 0;
};

#endif // VENDING_MACHINE_STATE_H
