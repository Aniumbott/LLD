#include "ReadyState.h"
#include "VendingMachine.h"
#include <iostream>

void ReadyState::selectProduct(VendingMachine *vendingMachine,
                               const Product &product)
{
  std::cout << "Product already selected. Please make payment." << std::endl;
}

void ReadyState::insertCoin(VendingMachine *vendingMachine, Coin coin)
{
  vendingMachine->addCoin(coin);
  std::cout << "Coin inserted." << std::endl;
  checkPaymentStatus(vendingMachine);
}

void ReadyState::insertNote(VendingMachine *vendingMachine, Note note)
{
  vendingMachine->addNote(note);
  std::cout << "Note inserted." << std::endl;
  checkPaymentStatus(vendingMachine);
}

void ReadyState::dispenseProduct(VendingMachine *vendingMachine)
{
  std::cout << "Please make payment first." << std::endl;
}

void ReadyState::returnChange(VendingMachine *vendingMachine)
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
  vendingMachine->setState(&vendingMachine->idleState);
}

void ReadyState::checkPaymentStatus(VendingMachine *vendingMachine)
{
  if (vendingMachine->totalPayment >=
      vendingMachine->selectedProduct->getPrice())
  {
    vendingMachine->setState(&vendingMachine->dispenseState);
  }
}
