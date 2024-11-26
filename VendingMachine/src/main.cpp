#include "Coin.h"
#include "Note.h"
#include "Product.h"
#include "VendingMachine.h"
#include <iostream>

int main() {
  VendingMachine &vendingMachine = VendingMachine::getInstance();

  Product coke("Coke", 1.5);
  Product pepsi("Pepsi", 1.5);
  Product water("Water", 1.0);

  vendingMachine.inventory.addProduct(coke, 5);
  vendingMachine.inventory.addProduct(pepsi, 3);
  vendingMachine.inventory.addProduct(water, 2);

  vendingMachine.selectProduct(coke);
  vendingMachine.insertCoin(Coin::QUARTER);
  vendingMachine.insertCoin(Coin::QUARTER);
  vendingMachine.insertCoin(Coin::QUARTER);
  vendingMachine.insertCoin(Coin::QUARTER);
  vendingMachine.insertNote(Note::FIVE);

  vendingMachine.dispenseProduct();
  vendingMachine.returnChange();

  vendingMachine.selectProduct(pepsi);
  vendingMachine.insertCoin(Coin::QUARTER);
  vendingMachine.dispenseProduct();
  vendingMachine.insertCoin(Coin::QUARTER);
  vendingMachine.insertCoin(Coin::QUARTER);
  vendingMachine.insertCoin(Coin::QUARTER);
  vendingMachine.insertCoin(Coin::QUARTER);
  vendingMachine.dispenseProduct();
  vendingMachine.returnChange();

  return 0;
}
