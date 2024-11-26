#ifndef INVENTORY_H
#define INVENTORY_H

#include <unordered_map>
#include "Product.h"

class Inventory {
public:
    void addProduct(const Product& product, int quantity);
    void removeProduct(const Product& product);
    void updateQuantity(const Product& product, int quantity);
    int getQuantity(const Product& product) const;
    bool isAvailable(const Product& product) const;

private:
    std::unordered_map<std::string, int> products;
};

#endif // INVENTORY_H
