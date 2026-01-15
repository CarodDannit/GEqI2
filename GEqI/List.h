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
	void DeleteFront();
	bool SearchItem(int, int&, int);
	void printList();
	void printSingle();
	int NumberOfItem();
	void sortID(bool asc); 
};

#endif

//constructor - called when create new objects
template <class T>
List<T>::List() {
	numItem = 0;
	pHead = nullptr;
	pCurr = nullptr;
}

//destructor - destroy every object when exit the program
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

//function to add item(Equipment/ Consumable) and Maintenance in a List
template <class T>
void List<T>::AddToFront() {
	T item;
	item.inputData();  // Ask the user to input data for the item
	Node* pNew = new Node(); // Create a new node
	pNew->data = item; // store the item data inside the new node
	pNew->link = pHead; //Link the new node to the current head of the list
	pHead = pNew; //make pHead point to the new node
	numItem++; //increase the total number of items in the list
}


//delete the last equipment added in Equipment list
template <class T>
void List<T>::DeleteFront() {
	if (pHead != nullptr) {
		Node* pTemp = pHead; // create a temporary node
		pHead = pHead->link; //moves pHead forward in the list
		delete pTemp; //delete the data and the link that pTemp reference to
		numItem--; // decrease the total number of items in the list
		cout << "First Item Deleted" << endl;
	}
	else { //if PHead is null, means there is no item
		cout << "\033[31mThere are no equipment left to be deleted\033[0m\n";
	}

}




template <class T>
bool List<T>::SearchItem(int targetID, int& loc, int method) {
	if (method == 1) {
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

		bool found = (loc < numItem);

		// Remove sentinel
		if (pLast) pLast->link = nullptr;
		delete sentinel;

		return found;
	}
	else if (method == 2) {
		sortID(true);//force sort asc
		if (numItem == 0) {
			return false;
		}

		int left = 0;
		int right = numItem - 1;

		//staruto
		while (left <= right) {
			int mid = left + (right - left) / 2;
			Node* pMid = pHead;
			for (int i = 0; i < mid; i++) {
				pMid = pMid->link;
			}
			if (pMid->data.getID() == targetID) {
				loc = mid;//found
				pCurr = pMid;
				return true;
			}
			if (pMid->data.getID() < targetID) {//great ignore left
				left = mid + 1;
			}
			else//small,ignore rige
				right = mid - 1;
		}
		return false;
	}

	return false;
}

template <class T>
void List<T>::printList() { // unified method to display a list (print Equipment, Consumable, Maintenance)
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



template <class T>
int List<T>::NumberOfItem() {// get the total number of Item in a list
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

	


