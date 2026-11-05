#include<iostream>
using namespace std;
#define ll long long
#define nl "\n"

class Node{
public:
    int data;
    Node *next;
};

class Queue {
	Node *head, *tail;
public:
	Queue(){
        head = tail = NULL;
    }

    bool isEmpty(){
        return (head==NULL && tail==NULL);
    }
    void enqueue(int value){
        Node*newNode = new Node;
        newNode->data=value;
        newNode->next=NULL;
        if(isEmpty()){
            head=tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    int dequeue(){
        if(isEmpty()){
            cout << "Queue is empty!\n";
            exit(1);
        }
        else if(head == tail){
            int temp = head->data;
            delete head;
            head=tail=NULL;
            return temp;
        }
        else{
            Node*temp=head;
            int tempVal=temp->data;
            head=head->next;
            delete temp;
            return tempVal;
        }
    }
    int peek(){
        if(isEmpty()){
            cout << "Queue is empty!\n";
            exit(1);
        }
        else 
            return head->data; 
    }
    void printQueue(){
        if(isEmpty()) return;
        else{
            Node*curr=head;
            while(curr!=NULL){
                cout << curr->data << ' ';
                curr = curr->next;
            }
            cout << nl;
        }
    }

    ~Queue(){
        Node*curr=head;
        while(curr!=NULL){
            head = head->next;
            delete curr;
            curr = head;
        }
        tail=NULL;
    }
};

int main()
{
	Queue q;
    
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();
    q.enqueue(40);
    q.printQueue();

	return 0;
}