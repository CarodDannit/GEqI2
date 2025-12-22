#ifndef LIST_H
#define LIST_H
class Equipment;

template <class T>
class List {
private:
	class Node {
	public:
		T data;
		Node* link;

		Node() : data(), link(nullptr) {}
	};

	Node* pHead;
	Node* pCurr;
	int numItem;

public:
	List();
	~List();
	void AddToFront();
	void AddMaintenance(List<Equipment>& equipmentList);
	void DeleteFront();
	bool SearchItem(int, int&);
	void printEquipment();
	void printConsumable();
	void printMaintenance();
	int NumberOfItem();
};

#endif

template <class T>
List<T>::List() {
	numItem = 0;
	pHead = nullptr;
	pCurr = nullptr;
}

template <class T>
List<T>::~List() {
	pCurr = pHead;
	while (pCurr != nullptr) {
		Node* pTemp = pCurr->link;
		delete pCurr;
		pCurr = pTemp;
	}
	pHead = nullptr;
	pCurr = nullptr;
	numItem = 0;
}

template <class T>
void List<T>::AddToFront() {
	T item;
	item.inputData();
	Node* pNew = new Node();
	pNew->data = item;
	pNew->link = pHead;
	pHead = pNew;
	numItem++;
}

template <class T>
void List<T>::AddMaintenance(List<Equipment>& equipmentList) {
	T item;
	item.inputData(equipmentList);
	Node* pNew = new Node();
	pNew->data = item;
	pNew->link = pHead;
	pHead = pNew;
	numItem++;
}




template <class T>
void List<T>::DeleteFront() {
	if (pHead != nullptr) {
		Node* pTemp = pHead;
		pHead = pHead->link;
		delete pTemp;
		numItem--;
		cout << "First Item Deleted" << endl;
	}
	else {
		cout << "\033[31mThere are no equipment left to be deleted\033[0m\n";
	}

}

template <class T>
bool List<T>::SearchItem(int targetID, int& loc) {
	if (numItem == 0) {
		cout << "There is no item in the list" << endl;
		return false;
	}
	else {
		pCurr = pHead;
		loc = 0;
		while (pCurr != nullptr) {
			if (pCurr->data.getID() == targetID) {
				return true;
			}
			pCurr = pCurr->link;
			loc++;
		}
		return false;
	}
}

template <class T>
void List<T>::printEquipment() {
	pCurr = pHead;
	cout << "\033[31m+---------------------------------------------------------------------------+\033[0m\n";
	cout << "\033[31m| "
		<< left << setw(6) << "ID" << "| "
		<< setw(15) << "NAME" << "| "
		<< setw(15) << "CATEGORY" << "| "
		<< setw(15) << "STATUS" << "| "
		<< setw(15) << "CONDITION"
		<< "|\033[0m\n";
	cout << "\033[31m+---------------------------------------------------------------------------+\033[0m\n";
	while (pCurr != 0) {
		cout << "| "
			<< left << setw(6) << pCurr->data.getID() << "| "
			<< setw(15) << pCurr->data.getName() << "| "
			<< setw(15) << pCurr->data.getCategory() << "| "
			<< setw(15) << pCurr->data.getStatus() << "| "
			<< setw(15) << pCurr->data.getCondition()
			<< "|\n";
		pCurr = pCurr->link;
	}
	cout << endl;
}

template <class T>
void List<T>::printConsumable() {
	pCurr = pHead;
	cout << "\033[31m+----------------------------------------------------------+\033[0m\n";
	cout << "\033[31m| "
		<< left << setw(6) << "ID" << "| "
		<< setw(15) << "NAME" << "| "
		<< setw(15) << "QUANTITY" << "| "
		<< setw(15) << "UNIT PRICE RM"
		<< "|\033[0m\n";
	cout << "\033[31m+----------------------------------------------------------+\033[0m\n";
	while (pCurr != 0) {
		cout << "| "
			<< left << setw(6) << pCurr->data.getID() << "| "
			<< setw(15) << pCurr->data.getName() << "| "
			<< setw(15) << pCurr->data.getQuantity() << "| "
			<< setw(15) << pCurr->data.getUnitPrice()
			<< "|\n";
		pCurr = pCurr->link;
	}
	cout << endl;
}

template <class T>
void List<T>::printMaintenance() {
	pCurr = pHead;
	cout << "\033[31m+----------------------------------------------------------------------------------------+\033[0m\n";
	cout << "\033[31m| "
		<< left << setw(6) << "ID" << "| "
		<< setw(6) << "EQ ID" << "| "
		<< setw(20) << "ISSUE" << "| "
		<< setw(15) << "COST" << "| "
		<< setw(15) << "DATE" << "| "
		<< setw(15) << "STATUS"
		<< "|\033[0m\n";
	cout << "\033[31m+----------------------------------------------------------------------------------------+\033[0m\n";
	while (pCurr != 0) {
		cout << "| "
			<< left << setw(6) << pCurr->data.getID() << "| "
			<< setw(6) << pCurr->data.getEquipID() << "| "
			<< setw(20) << pCurr->data.getIssue() << "| "
			<< setw(15) << pCurr->data.getCost() << "| "
			<< setw(15) << pCurr->data.getDate() << "| "
			<< setw(15) << pCurr->data.getStatus() << "| "
			<< "|\n";
		pCurr = pCurr->link;
	} 
	cout << endl;
}


template <class T>
int List<T>::NumberOfItem() {
	return numItem;
}
	


