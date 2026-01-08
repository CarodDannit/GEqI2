#ifndef EQUIPMENT_H
#define EQUIPMENT_H
#include "Item.h"
#include "IListable.h"

class Equipment : public Item, public IListable {
private:
	string category;
	string status;
	string condition;
public:
	Equipment();
	~Equipment();

	void inputData();

	//get method

	string getCategory();
	string getStatus();
	string getCondition();

	static void printListLabel(); // The label when displaying an Equipment list
	void printListItem();
};

#endif

