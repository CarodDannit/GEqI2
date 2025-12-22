#ifndef CONSUMABLE_H
#define CONSUMABLE_H
#include "Item.h"

class Consumable : public Item {
private:
	int quantity;
	double unitPrice;

public:
	Consumable();
	~Consumable();

	void inputData();

	int getQuantity();
	double getUnitPrice();
};

#endif
//hi hello

