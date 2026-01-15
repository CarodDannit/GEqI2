#ifndef EQUIPMENT_H
#define EQUIPMENT_H
#include "Item.h"

class Equipment : public Item {
private:
	string category;
	string status;
	string condition;
public:
	Equipment();
	~Equipment();

	bool inputData();
	int getNextID();

	//get method

	string getCategory();
	string getStatus();
	string getCondition();

	void printListLabel(); // The label when displaying an Equipment list
	void printListItem();
};

#endif

