#include <iostream>
using namespace std;
#define ll long long
#define nl "\n"

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};

class DoublyLinkedList
{
    Node *head;
    int length;

public:
    DoublyLinkedList()
    {
        head = NULL;
        length = 0;
    }

    bool isEmpty()
    {
        return (head == NULL);
    }

    void addToHead(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        newNode->prev = NULL;
        if (!isEmpty())
        {
            head->prev = newNode;
        }
        head = newNode;
        length++;
    }
    
    void addTotail(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;
        if (isEmpty())
        {
            newNode->prev = NULL;
            head = newNode;
        }
        else
        {
            Node *curr = head;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = newNode;
            newNode->prev = curr;
        }
        length++;
    }

    void deleteHead()
    {
        if (isEmpty())
        {
            return;
        }
        else if (head->next == NULL)
        {
            delete head;
            head = NULL;
            length--;
        }
        else
        {
            head = head->next;
            delete head->prev;
            head->prev = NULL;
            length--;
        }
    }

    void deleteTail()
    {
        if (isEmpty())
        {
            return;
        }
        else if (head->next == NULL)
        {
            delete head;
            head = NULL;
            length--;
        }
        else
        {
            Node *curr = head;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->prev->next = NULL;
            delete curr;
            length--;
        }
    }

    int findNode(int value)
    {
        int pos = -1;
        Node *curr = head;
        int cnt = 0;
        while (curr != NULL)
        {
            if (curr->data == value)
            {
                pos = cnt;
                break;
            }
            curr = curr->next;
            cnt++;
        }
        return pos;
    }

    void deleteNode(int value)
    {
        if (findNode(value) != -1)
        {
            Node *curr = head;
            while (curr->data != value && curr != NULL)
            {
                curr = curr->next;
            }
            if (curr == NULL)
                return;
            else if (curr->data == head->data)
                deleteHead();
            else if (curr->next == NULL)
                deleteTail();
            else
            {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                delete curr;
            }
        }
        else
            return;
    }

    void addAfter(int item, int value)
    {
        if (findNode(item) != -1)
        {
            if (isEmpty())
                return;
            else if (head->next == NULL)
                if (head->data == item)
                {
                    addTotail(value);
                }
                else
                    return;
            else
            {
                Node *newNode = new Node;
                newNode->data = value;
                Node *curr = head;
                while (curr->data != item && curr != NULL)
                {
                    curr = curr->next;
                }
                if (curr == NULL)
                    return;
                else if (curr->next == NULL)
                    addTotail(value);
                else
                {
                    newNode->next = curr->next;
                    newNode->prev = curr;
                    curr->next->prev = newNode;
                    curr->next = newNode;
                    length++;
                }
            }
        }
        else
            return;
    }

    void reverse()
    {
        if (isEmpty() || length == 1)
            return;
        else
        {
            Node *curr = head;
            Node *temp = NULL;
            while (curr != NULL)
            {
                temp = curr->prev;
                curr->prev = curr->next;
                curr->next = temp;
                curr = curr->prev;
            }
            if (temp != NULL)
                head = temp->prev;
        }
    }

    int size()
    {
        return length;
    }

    void printList()
    {
        Node *curr = head;
        while (curr != NULL)
        {
            cout << curr->data << ' ';
            curr = curr->next;
        }
        cout << nl;
    }
    
    void delAtPosition(int pos);
 
    ~DoublyLinkedList()
    {
        if (!isEmpty())
        {
            while (head->next != NULL)
            {
                head = head->next;
                delete head->prev;
                head->prev = NULL;
            }
            delete head;
            head = NULL;
        }
    }
};

void DoublyLinkedList ::delAtPosition(int pos)
{
    if (head == NULL)
    {
        cout << "List is Empty!\n";
        return;
    }
    else if (pos < 0)
    {
        cout << "Invalid Position!\n";
        return;
    }
    else if (pos == 0)
    {
        Node *curr = head;
        head = head->next;
        delete curr;
        if (head)
        {
            head->prev = NULL;
        }
    }
    else
    {
        Node *curr = head;
        int idx = 1;
        while (curr && idx < pos)
        {
            curr = curr->next;
            idx++;
        }
        if (!curr)
        {
            cout << "Invalid Position!\n";
            return;
        }
        else if (curr->next == NULL)
        {
            curr->prev->next = NULL;
            delete curr;
        }
        else
        {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete curr;
        }
    }
}

int main()
{
    DoublyLinkedList l;

    l.addAfter(10, 20);
    l.addTotail(10);
    cout << "List: ";
    l.printList();
    l.addTotail(20);
    l.addTotail(30);
    l.addTotail(40);

    l.addAfter(10, 15);

    cout << "List: ";
    l.printList();
    l.deleteNode(10);
    cout << "List: ";
    l.printList();
    l.deleteNode(30);
    cout << "List: ";
    l.printList();
    l.deleteNode(40);
    cout << "List: ";
    l.printList();
    l.deleteNode(20);
    cout << "List: ";
    l.printList();
    l.deleteNode(10);
    cout << "List: ";
    l.printList();

    cout << "List: ";
    l.printList();
    l.addAfter(10, 12);
    cout << "List: ";
    l.printList();
    l.addAfter(15, 20);
    cout << "List: ";
    l.printList();
    l.addAfter(30, 40);
    cout << "List: ";
    l.printList();
    l.reverse();
    cout << "List: ";
    l.printList();

    cout << l.size() << nl;

    return 0;
}