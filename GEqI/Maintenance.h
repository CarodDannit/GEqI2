#ifndef MAINTENANCE_H
#define MAINTENANCE
#include "Equipment.h"
#include "IListable.h"

class Maintenance : public IListable {
private:
	int id;
	Equipment equip;
	string issue;
	double cost;
	string date;
	string status;

public:
	Maintenance();
	~Maintenance();

	void inputData(List<Equipment>);
	int getNextID();

	int getID();
	int getEquipID();
	string getIssue();
	double getCost();
	string getDate();
	string getStatus();

	static void printListLabel(); // The label when displaying a Maintenance list
	void printListItem();
};

#endif