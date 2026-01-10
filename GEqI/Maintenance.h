#ifndef MAINTENANCE_H
#define MAINTENANCE_H
#include "Equipment.h"
#include "IListable.h"
template<class T>
class List;

class Maintenance : public IListable {
private:
	static List<Equipment>* equipmentList;
	int id;
	Equipment equip;
	string issue;
	double cost;
	string date;
	string status;

public:
	Maintenance();
	~Maintenance();
	static void setEquipments(List<Equipment>&);

	void inputData();
	int getNextID();

	int getID();
	void setID(int);
	int getEquipID();
	string getIssue();
	double getCost();
	string getDate();
	string getStatus();

	static void printListLabel(); // The label when displaying a Maintenance list
	void printListItem();
};

#endif