#include "VendingMachine.h"

VendingMachine VendingMachine::instance;

VendingMachine::VendingMachine()
    : idleState(), readyState(), dispenseState(), returnChangeState(),
      inventory(), totalPayment(0.0), selectedProduct(nullptr),
      currentState(&idleState) {}

VendingMachine &VendingMachine::getInstance() { return instance; }

void VendingMachine::selectProduct(const Product &product) {
  currentState->selectProduct(this, product);
}

void VendingMachine::insertCoin(Coin coin) {
  currentState->insertCoin(this, coin);
}

void VendingMachine::insertNote(Note note) {
  currentState->insertNote(this, note);
}

void VendingMachine::dispenseProduct() { currentState->dispenseProduct(this); }

void VendingMachine::returnChange() { currentState->returnChange(this); }

void VendingMachine::setState(VendingMachineState *state) {
  currentState = state;
}

void VendingMachine::addCoin(Coin coin) {
  totalPayment += static_cast<int>(coin) / 100.0;
}

void VendingMachine::addNote(Note note) {
  totalPayment += static_cast<int>(note) / 100.0;
}

void VendingMachine::resetPayment() { totalPayment = 0.0; }

void VendingMachine::resetSelectedProduct() {
  delete selectedProduct;
  selectedProduct = nullptr;
}
