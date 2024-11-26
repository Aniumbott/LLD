#include "IdleState.h"
#include "VendingMachine.h"
#include <iostream>

void IdleState::selectProduct(VendingMachine *vendingMachine,
                              const Product &product) {
  if (vendingMachine->inventory.isAvailable(product)) {
    vendingMachine->selectedProduct = new Product(product);
    vendingMachine->setState(&vendingMachine->readyState);
    std::cout << "Product selected: " << product.getName() << std::endl;
  } else {
    std::cout << "Product not available: " << product.getName() << std::endl;
  }
}

void IdleState::insertCoin(VendingMachine *vendingMachine, Coin coin) {
  std::cout << "Please select a product first." << std::endl;
}

void IdleState::insertNote(VendingMachine *vendingMachine, Note note) {
  std::cout << "Please select a product first." << std::endl;
}

void IdleState::dispenseProduct(VendingMachine *vendingMachine) {
  std::cout << "Please select a product and make payment." << std::endl;
}

void IdleState::returnChange(VendingMachine *vendingMachine) {
  std::cout << "No change to return." << std::endl;
}
