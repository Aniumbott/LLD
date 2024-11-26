#include "Inventory.h"

void Inventory::addProduct(const Product &product, int quantity) {
  products[product.getName()] = quantity;
}

void Inventory::removeProduct(const Product &product) {
  products.erase(product.getName());
}

void Inventory::updateQuantity(const Product &product, int quantity) {
  products[product.getName()] = quantity;
}

int Inventory::getQuantity(const Product &product) const {
  auto it = products.find(product.getName());
  return it != products.end() ? it->second : 0;
}

bool Inventory::isAvailable(const Product &product) const {
  return getQuantity(product) > 0;
}
