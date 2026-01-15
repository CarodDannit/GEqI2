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

	int getNextID();
	bool inputData();

	int getQuantity();
	double getUnitPrice();

	void printListLabel(); // The label when displaying a Consumable list
	void printListItem();
};

#endif