#include "Coin.h"
#include "Note.h"
#include "Product.h"
#include "VendingMachine.h"
#include <iostream>

int main()
{
  VendingMachine &vendingMachine = VendingMachine::getInstance();

  Product coke("Coke", 280);
  Product pepsi("Pepsi", 180);
  Product water("Water", 20);

  vendingMachine.inventory.addProduct(coke, 5);
  vendingMachine.inventory.addProduct(pepsi, 3);
  vendingMachine.inventory.addProduct(water, 2);

  vendingMachine.selectProduct(coke);
  vendingMachine.insertNote(Note::TWO_HUNDRED_N);
  vendingMachine.insertNote(Note::ONE_HUNDRED_N);
  vendingMachine.insertNote(Note::FIFTY_N);
  vendingMachine.insertCoin(Coin::TWENTY_C);
  vendingMachine.insertCoin(Coin::TWENTY_C);

  vendingMachine.dispenseProduct();
  vendingMachine.returnChange();

  vendingMachine.selectProduct(pepsi);
  vendingMachine.insertNote(Note::ONE_HUNDRED_N);
  vendingMachine.dispenseProduct();
  vendingMachine.insertCoin(Coin::TEN_C);
  vendingMachine.insertCoin(Coin::TWENTY_C);
  vendingMachine.insertNote(Note::FIFTY_N);
  vendingMachine.dispenseProduct();
  vendingMachine.returnChange();

  return 0;
}
