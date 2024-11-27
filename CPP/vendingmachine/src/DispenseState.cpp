
#include "DispenseState.h"
#include "VendingMachine.h"
#include <iostream>

void DispenseState::selectProduct(VendingMachine *vendingMachine,
                                  const Product &product) {
  std::cout << "Product already selected. Please collect the dispensed product."
            << std::endl;
}

void DispenseState::insertCoin(VendingMachine *vendingMachine, Coin coin) {
  std::cout << "Payment already made. Please collect the dispensed product."
            << std::endl;
}

void DispenseState::insertNote(VendingMachine *vendingMachine, Note note) {
  std::cout << "Payment already made. Please collect the dispensed product."
            << std::endl;
}

void DispenseState::dispenseProduct(VendingMachine *vendingMachine) {
  vendingMachine->setState(&vendingMachine->readyState);
  std::cout << "Product dispensed: "
            << vendingMachine->selectedProduct->getName() << std::endl;
  vendingMachine->inventory.updateQuantity(
      *vendingMachine->selectedProduct,
      vendingMachine->inventory.getQuantity(*vendingMachine->selectedProduct) -
          1);
  vendingMachine->setState(&vendingMachine->returnChangeState);
}

void DispenseState::returnChange(VendingMachine *vendingMachine) {
  std::cout << "Please collect the dispensed product first." << std::endl;
}
