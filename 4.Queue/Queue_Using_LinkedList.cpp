#include <iostream>
using namespace std;
#define ll long long
#define nl "\n"

class Node
{
public:
	int data;
	Node *next;
	Node()
	{
		data = 0;
		next = NULL;
	}
	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};

class Queue
{
	Node *head;
	Node *tail;

public:
	Queue()
	{
		head = tail = NULL;
	}

	bool isEmpty()
	{
		return (head == NULL && tail == NULL);
	}

	void enqueue(int value)
	{
		Node *newNode = new Node(value);
		if (isEmpty())
		{
			head = tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
	}

	int dequeue()
	{
		if (isEmpty())
			exit(1);
		else if (head == tail)
		{
			int tempVal = head->data;
			delete head;
			head = tail = NULL;
			return tempVal;
		}
		else
		{
			int tempVal = head->data;
			Node *temp = head;
			head = head->next;
			delete temp;
			return tempVal;
		}
	}

	int peek()
	{
		if (isEmpty)
			exit(1);
		else
			return head->data;
	}

	int countOcc(int item)
	{
		if (isEmpty())
			return 0;
		int cnt = 0;
		Node *curr = head;
		while (curr != NULL)
		{
			if (curr->data == item)
				cnt++;
			curr = curr->next;
		}
		return cnt;
	}

	bool found(int item)
	{
		if (isEmpty())
			return 0;
		Node *curr = head;
		while (curr != NULL)
		{
			if (curr->data == item)
				return 1;
			curr = curr->next;
		}
		return 0;
	}

	int position(int item)
	{
		if (!found(item))
			return -1;
		Node *curr = head;
		int pos = 0;
		while (curr != NULL)
		{
			if (curr->data == item)
				break;
			curr = curr->next;
			pos++;
		}
		return pos;
	}

	int size()
	{
		int cnt = 0;
		Node *curr = head;
		while (curr != NULL)
		{
			cnt++;
			curr = curr->next;
		}
		return cnt;
	}

	void display()
	{
		if (isEmpty())
			return;
		Node *curr = head;
		while (curr != NULL)
		{
			cout << curr->data << ' ';
			curr = curr->next;
		}
		cout << nl;
	}

	~Queue()
	{
		if (!isEmpty())
		{
			Node *temp = head;
			while (head != NULL)
			{
				delete temp;
				head = head->next;
				temp = head;
			}
			tail = NULL;
		}
	}
};

int main()
{
	Queue q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.dequeue();

	cout << "Queue: ";
	q.display();

	return 0;
}