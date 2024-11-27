
#include "ReturnChangeState.h"
#include "VendingMachine.h"
#include <iostream>

void ReturnChangeState::selectProduct(VendingMachine *vendingMachine,
                                      const Product &product)
{
  std::cout << "Please collect the change first." << std::endl;
}

void ReturnChangeState::insertCoin(VendingMachine *vendingMachine, Coin coin)
{
  std::cout << "Please collect the change first." << std::endl;
}

void ReturnChangeState::insertNote(VendingMachine *vendingMachine, Note note)
{
  std::cout << "Please collect the change first." << std::endl;
}

void ReturnChangeState::dispenseProduct(VendingMachine *vendingMachine)
{
  std::cout << "Product already dispensed. Please collect the change."
            << std::endl;
}

void ReturnChangeState::returnChange(VendingMachine *vendingMachine)
{
  double change = vendingMachine->totalPayment -
                  vendingMachine->selectedProduct->getPrice();
  if (change > 0)
  {
    std::cout << "Change returned: " << change << "Rs." << std::endl;
    vendingMachine->resetPayment();
  }
  else
  {
    std::cout << "No change to return." << std::endl;
  }
  vendingMachine->resetSelectedProduct();
  vendingMachine->setState(&vendingMachine->idleState);
}
