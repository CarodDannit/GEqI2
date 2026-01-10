#ifndef CONSUMABLE_H
#define CONSUMABLE_H
#include "Item.h"
#include "IListable.h"

class Consumable : public Item, public IListable {
private:
	int quantity;
	double unitPrice;

public:
	Consumable();
	~Consumable();

	int getNextID();
	void inputData();

	int getQuantity();
	double getUnitPrice();

	static void printListLabel(); // The label when displaying a Consumable list
	void printListItem();
};

#endif
//hi hello

