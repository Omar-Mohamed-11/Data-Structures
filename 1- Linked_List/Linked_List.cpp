#include<iostream>
#include<string>
using namespace std;
#define ll long long
#define nl "\n"

/*
Functions:
	-addToHead(value)
	-addToTail(value)
    -addBefore(item, newValue)
    -insertAtMid() -> addAfter(item, value)
	-deleteHead()
	-deleteTail()
    -deleteAt(pos)
    -deleteAfter(value)
    -deleteValue(value)
    -update(pos, newValue)
	-printList()
	-gitMax()
	-gitMin()
	-findNode(Value)
	-size()
	-isEmpty()
Others:
	-default Constructor
	-destructor(){}
*/

class Node {
public:
	int data;
	Node * next;
};

class LinkedList{
private:
	Node * head;
	int length;

public:
	//Default constructor
	LinkedList() {
		head = NULL;
		length = 0;
	}

	//Function to cheack that the list is empty 
	bool isEmpty() {
		return (head == NULL);
	}

//================================================================//

	//-- Add Functions --//
	void addToHead(int value) {
		Node* newNode = new Node;
		newNode->data = value;
		if (isEmpty()) {
			newNode->next = NULL;
			head = newNode;
		}
		else {
			newNode->next = head;
			head = newNode;
		}
		length++;
	}

	void addToTail(int value) {
		Node* newNode = new Node;
		newNode->data = value;
		if (isEmpty()) {
			newNode->next = NULL;
			head = newNode;
		}
		else {
			Node* curr = head;
			while (curr->next != NULL) {
				curr = curr->next;
			}
			newNode->next = NULL;
			curr->next = newNode;
		}
		length++;
	}

	void addBefore(int item, int value) {
		if (isEmpty() || head->data==item) {
			addToHead(value);
			length++;
		}
		else if (findNode(item) != -1) {
			Node* newNode = new Node;
			newNode->data = value;
			Node* curr = head;
			while (curr->next->data != item) {
				curr = curr->next;
			}
			newNode->next = curr->next;
			curr->next = newNode;
			length++;
		}
		else
			cout << "Error, item not found!\n";
		
	}

	void addAfter(int item, int value) {
		if (isEmpty() || findNode(item)==length-1) {
			addToTail(value);
			length++;
		}
		else if (findNode(item) != -1) {
			Node* newNode = new Node;
			newNode->data = value;
			Node* curr = head;
			while (curr->data != item) {
				curr = curr->next;
			}
			newNode->next = curr->next;
			curr->next = newNode;
			length++;
		}
		else
			cout << "Error, item not found!\n";
	}

	//-- Delete Functions --//
	void deleteHead() {
		if (isEmpty()) {
			return;
		}
		else if (length == 1) {
			delete head;
			head = NULL;
			length--;
		}
		else {
			Node* curr = head;
			head = head->next;
			delete curr;
			length--;
		}
	}

	void deleteTail() {
		if (isEmpty()) {
			return;
		}
		else if (length == 1) {
			delete head;
			head = NULL;
			length--;
		}
		else {
			Node* curr = head;
			while (curr->next->next != NULL) {
				curr = curr->next;
			}
			delete curr->next;
			curr->next = NULL;
			length--;
		}
	}

	void deleteValue(int value) {
		if (isEmpty()) return;
		else if (head->data == value) {
			deleteHead();
		}
		else if (findNode(value) != -1) {
			Node* prev = head;
			Node* delPtr;
			while (prev->next->data != value) {
				prev = prev->next;
			}
			delPtr = prev->next;
			prev->next = delPtr->next;
			delete delPtr;
			length--;
		}
		else
			cout << "Error, value not found!\n";
	}

	void deleteAfter(int value) {
		if (isEmpty() || length==1 || findNode(value)==length-1) {
			return;
		}
		else if (findNode(value) == length - 2) {
			deleteTail();
		}
		else if (findNode(value) != -1) {
			Node* curr = head;
			Node* after;
			while (curr->data != value) {
				curr = curr->next;
			}
			after = curr->next;
			curr->next = after->next;
			delete after;
			length--;
		}
		else
			cout << "Error, value not found!\n";
	}

	void deleteAt(int pos) {
		if (pos < 0 || pos >= length) {
			cout << "Error, invalid position!\n";
		}
		else if (pos == 0) {
			deleteHead();
		}
		else if (pos == length - 1) {
			deleteTail();
		}
		else {
			Node* curr;
			Node* prev = head;
			int idx = 0;
			while (idx < pos-1) {
				prev = prev->next;
				idx++;
			}
			curr = prev->next;
			prev->next = curr->next;
			delete curr;
			length--;
		}
	}


	void update(int pos, int value) {
		if (pos < 0 || pos >= length) {
			cout << "Error, invalid position!\n";
		}
		else {
			int idx = 0;
			Node* curr = head;
			while (idx != pos) {
				curr = curr->next;
				idx++;
			}
			curr->data = value;
		}
	}

//=======================================================================//

	//Return the position of this node else return -1
	int findNode(int value) {
		int pos = 0;
		Node* curr = head;
		while (curr != NULL) {
			if (curr->data == value) {
				return pos;
			}
			else pos++;
			curr = curr->next;
		}
		return -1;
	}

	//Return list size
	int size() {
		return length;
	}

	int getMin() {
		Node* curr = head;
		int mn = curr->data;
		while (curr != NULL) {
			if (curr->data < mn)
				mn = curr->data;
			curr = curr->next;
		}
		return mn;
	}

	int getMax() {
		Node* curr = head;
		int mx = curr->data;
		while (curr != NULL) {
			if (curr->data > mx)
				mx = curr->data;
			curr = curr->next;
		}
		return mx;
	}

	//Count occurence of an item
	int countOcc(int item) {
		if(isEmpty()) return 0;
		else{
			Node * curr = head;
			int count = 0;
			while(curr != NULL) {
				if(curr->data == item) {
					count++;
				}
				curr = curr->next;
			}
			return count;
		}
	}

	void printList() {
		Node* curr = head;
		while (curr != NULL) {
			cout << curr->data << ' ';
			curr = curr->next;
		}
		cout << nl;
	}

	//Destructor to destroy all nodes
	~LinkedList(){
		Node* curr = head;
		while (curr != NULL) {
			head = head->next;
			delete curr;
			curr = head;
		}
		curr = nullptr;
		head = nullptr;
	}
};

int main()
{
	LinkedList l;
	
	if (l.isEmpty()) {
		cout << "List is empty\n";
	}
	else {
		cout << "List is not empty\n";
	}

	l.addToTail(50);
	l.addToTail(60);
	cout << "List: ";l.printList();

	l.addToHead(20);
	l.addToHead(10);
	cout << "List: ";l.printList();

	l.addAfter(20, 30);
	l.addBefore(20, 15);
	cout << "List: ";l.printList();

	l.deleteTail();
	l.deleteAt(1);
	cout << "List: ";l.printList();
	l.deleteHead();
	l.deleteAfter(30);
	cout << "List: ";l.printList();
	l.addToTail(80);
	l.addToTail(90);
	cout << "List: ";l.printList();
	l.deleteValue(80);
	cout << "List: ";l.printList();

	cout << "Max: " << l.getMax() << nl;
	cout << "Min: " << l.getMin() << nl;
	cout << "Size: " << l.size() << nl;
	
	l.addAfter(30, 40);
	l.addBefore(40, 5);
	cout << "List: ";l.printList();
	cout << 5 << " is found in position: " << l.findNode(5) << nl;
	
	if (l.findNode(100) != -1)
		cout << "Founded\n";
	else
		cout << "Not founded\n";

	l.update(2, 35);
	cout << "List: ";l.printList();

	l.addToTail(40);
	l.addToTail(30);
	l.addToTail(40);
	l.addToTail(50);
	cout << "List: ";l.printList();
	cout<<"The count of 40 is: "<<l.countOcc(40)<<nl;

	l.addToHead(10);
	l.printList();
	l.deleteHead();
	l.printList();
	

	return 0;
}