#ifndef LIST_H
#define LIST_H
class Equipment;
class Consumable;

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
	//ammar (search) : binary, sentinel
	//binary sentinel
	bool SearchItem(int, int&);
	void printList();
	void printSingle();
	//void printEquipment();
	//void printSingleEquipment(int targetID);//idk how,but it works. might not even working. put your trust in lord
	//void printConsumable();
	//void printSingleConsumable(int targetID);//same thing.but it does not work
	void printMaintenance();
	int NumberOfItem();
	//function sorting based on id (ascending or decending) : amira
	void sortID(bool asc); //loollolololololol
	//lololololol
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



//belum siap
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

	//create sentinel node - put it at the last of the list that contain the target link and data
	Node* sentinel = new Node();
	sentinel->data.setID(targetID); 
	sentinel->link = nullptr;

	// Attach sentinel to end of list
	pCurr = pHead;
	Node* pLast = nullptr;
	while (pCurr != nullptr) {
		pLast = pCurr;
		pCurr = pCurr->link;
	}
	if (pLast) pLast->link = sentinel;
	else pHead = sentinel;

	// Search with sentinel
	pCurr = pHead;
	loc = 0;
	while (pCurr->data.getID() != targetID) {
		pCurr = pCurr->link;
		loc++;
	}

	// Remove sentinel
	if (pLast) pLast->link = nullptr;
	else pHead = nullptr;

	bool found = (loc < numItem);
	delete sentinel;

	return found;
}

template <class T>
void List<T>::printList() { // unified method to display a list
	pCurr = pHead;
	pCurr->data.printListLabel();
	while (pCurr != 0) {
		pCurr->data.printListItem();
		pCurr = pCurr->link;
	}
	cout << endl;
}

template <class T>
void List<T>::printSingle() {
	// ?? idk
	// try looking for ur item first, then printListItem() it. Go marr
	//pCurr = pHead;
	pCurr->data.printListLabel();
	pCurr->data.printListItem();
	//pCurr = pCurr->link;

	cout << endl;
}

//template <class T>
//void List<T>::printEquipment() {
//	pCurr = pHead;
//	cout << "\033[31m+---------------------------------------------------------------------------+\033[0m\n";
//	cout << "\033[31m| "
//		<< left << setw(6) << "ID" << "| "
//		<< setw(15) << "NAME" << "| "
//		<< setw(15) << "CATEGORY" << "| "
//		<< setw(15) << "STATUS" << "| "
//		<< setw(15) << "CONDITION"
//		<< "|\033[0m\n";
//	cout << "\033[31m+---------------------------------------------------------------------------+\033[0m\n";
//	while (pCurr != 0) {
//		cout << "| "
//			<< left << setw(6) << pCurr->data.getID() << "| "
//			<< setw(15) << pCurr->data.getName() << "| "
//			<< setw(15) << pCurr->data.getCategory() << "| "
//			<< setw(15) << pCurr->data.getStatus() << "| "
//			<< setw(15) << pCurr->data.getCondition()
//			<< "|\n";
//		pCurr = pCurr->link;
//	}
//	cout << endl;
//}


//template <class T>
//void List<T>::printConsumable() {
//	pCurr = pHead;
//	cout << "\033[31m+----------------------------------------------------------+\033[0m\n";
//	cout << "\033[31m| "
//		<< left << setw(6) << "ID" << "| "
//		<< setw(15) << "NAME" << "| "
//		<< setw(15) << "QUANTITY" << "| "
//		<< setw(15) << "UNIT PRICE RM"
//		<< "|\033[0m\n";
//	cout << "\033[31m+----------------------------------------------------------+\033[0m\n";
//	while (pCurr != 0) {
//		cout << "| "
//			<< left << setw(6) << pCurr->data.getID() << "| "
//			<< setw(15) << pCurr->data.getName() << "| "
//			<< setw(15) << pCurr->data.getQuantity() << "| "
//			<< setw(15) << pCurr->data.getUnitPrice()
//			<< "|\n";
//		pCurr = pCurr->link;
//	}
//	cout << endl;
//}

//template <class T>
//void List<T>::printSingleConsumable(int targetID) {
//	pCurr = pHead;
//	cout << "\033[31m+----------------------------------------------------------+\033[0m\n";
//	cout << "\033[31m| "
//		<< left << setw(6) << "ID" << "| "
//		<< setw(15) << "NAME" << "| "
//		<< setw(15) << "QUANTITY" << "| "
//		<< setw(15) << "UNIT PRICE RM"
//		<< "|\033[0m\n";
//	cout << "\033[31m+----------------------------------------------------------+\033[0m\n";
//		cout << "| "
//			<< left << setw(6) << pCurr->data.getID() << "| "
//			<< setw(15) << pCurr->data.getName() << "| "
//			<< setw(15) << pCurr->data.getQuantity() << "| "
//			<< setw(15) << pCurr->data.getUnitPrice()
//			<< "|\n";
//		pCurr = pCurr->link;
//	
//	cout << endl;
//}

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
			<< setw(15) << pCurr->data.getStatus()
			<< "|\n";
		pCurr = pCurr->link;
	} 
	cout << endl;
}


template <class T>
int List<T>::NumberOfItem() {
	return numItem;
}

template <class T>
void List<T>::sortID(bool asc) {
	if (pHead == nullptr || pHead->link == nullptr) {
		return; 
	} // if the list is empty/only 1 item,no need to sort

	for (Node* pStart = pHead; pStart != nullptr; pStart = pStart->link) {
		Node* pSelect = pStart;

		for (Node* pNext = pStart->link; pNext != nullptr; pNext = pNext->link) { //compare ID to find the best candidate
			if (asc) {
				// ascending order
				if (pNext->data.getID() < pSelect->data.getID()) {
					pSelect = pNext;
				} //if ascending,look for smaller ID
			}
			else {
				// descending order
				if (pNext->data.getID() > pSelect->data.getID()) {
					pSelect = pNext;
				} //if descending,look for a bigger ID
			}
		}

		
		if (pSelect != pStart) {
			T temp = pStart->data;
			pStart->data = pSelect->data;
			pSelect->data = temp;
		} //if it found better node,swap the data
	}

	cout << "List sorted by ID " << (asc ? "(Ascending)" : "(Descending)") << endl;
} //pstart moves to the next node,until the list is fully sorted

	


