#ifndef ITEM_H
#define ITEM_H

class Item {
private:
	int id;
	string name;

public:
	Item();
	~Item();
	virtual int getNextID() = 0;
	void inputData(int);
	virtual void printListLabel() = 0;
	virtual void printListItem() = 0;

	//get method
	int getID();
	void setID(int);
	string getName();
	virtual int getQuantity() { return 0; }
	virtual double getUnitPrice() { return 0.0; }
	virtual string getCategory() { return "N/A"; }
	virtual string getStatus() { return "N/A"; }
	virtual string getCondition() { return "N/A"; }
};


#endif
