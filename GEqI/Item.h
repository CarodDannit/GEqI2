#ifndef ITEM_H
#define ITEM_H

class Item {
private:
	int id;
	string name;

public:
	Item();
	~Item();
	int getNextID();
	void inputData();

	//get method
	int getID();
	void setID(int);
	string getName();
};


#endif
