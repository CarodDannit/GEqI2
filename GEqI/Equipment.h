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

	void inputData();

	//get method

	string getCategory();
	string getStatus();
	string getCondition();
};

#endif

