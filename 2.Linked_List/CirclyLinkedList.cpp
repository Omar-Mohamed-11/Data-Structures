#include <iostream>
using namespace std;

void MoRa()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
    // #endif
}

#define ll long long
#define nl "\n"
#define fixed(n) fixed << setprecision(n)

class Node {
public:
    int data;
    Node* next;
};

class CirclyLinkedList {
    Node* head;
    int length;
public:
    CirclyLinkedList() {
        head = NULL;
        length = 0;
    }

    bool isEmpty() {
        return(head == NULL);
    }

    void addToHead(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        if (isEmpty()) {
            head = newNode;
            newNode->next = head;
        }
        else {
            Node* curr = head;
            while (curr->next != head) {
                curr = curr->next;
            }
            curr->next = newNode;
            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    void addToTail(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        if (isEmpty()) {
            head = newNode;
            newNode->next = head;
        }
        else {
            Node* curr = head;
            while (curr->next != head) {
                curr = curr->next;
            }
            curr->next = newNode;
            newNode->next = head;
        }
        length++;
    }

    void deleteHead() {
        Node* curr = head;
        if (isEmpty()) return;
        else if (head->next == head) {
            delete head;
            head = NULL;
            length--;
        }
        else {
            while (curr->next != head) {
                curr = curr->next;
            }
            head = head->next;
            delete curr->next;
            curr->next = head;
            length--;
        }
    }

    void deleteTail() {
        if (isEmpty()) return;
        else if (head->next == head) {
            delete head;
            head = NULL;
            length--;
        }
        else {
            Node* curr = head;
            while (curr->next->next != head) {
                curr = curr->next;
            }
            delete curr->next;
            curr->next = head;
            length--;
        }
    }

    //--------------------------//
    int countList() {
        return length;
    }

    int findNode(int value){
        if(isEmpty()) return -1;
        else{
            int pos=-1;
            Node*curr=head;
            int idx=0;
            while(curr->next!=head){
                if(curr->data==value) 
                    return idx;
                curr=curr->next;
                idx++;
            }
            if(curr->data==value)pos=idx;
            return pos;
        }
    }

    void deleteNode(int value){
        if(findNode(value)!=-1){
            if(head->data==value)
                deleteHead();
            else{
                Node*prev=head;
                Node*curr=head->next;
                while(curr->data!=value){
                    curr=curr->next;
                    prev=prev->next;
                }
                if(curr==head)
                    deleteTail();
                else{
                    prev->next=curr->next;
                    delete curr;
                }
            }
        }
        else return;
    }

    void insertAfter(int data, int value){
        if(findNode(data)==-1) return;
        else{
            if(head->next==head)
                addToTail(value);
            else{
                Node*newNode = new Node;
                newNode->data = value;
                Node*curr = head;
                while(curr->data!=data){
                    curr=curr->next;
                }
                newNode->next=curr->next;
                curr->next=newNode;
            }
        }
    }

    //--------------------------//
    

    void printList() {
        if (isEmpty())return;
        Node* curr = head;
        while (curr->next != head) {
            cout << curr->data << ' ';
            curr = curr->next;
        }
        cout << curr->data << nl;
    }
    
    ~CirclyLinkedList() {
        if (!isEmpty()) {
            Node* curr = head->next;
            while (curr != head) {
                head->next = curr->next;
                delete curr;
                curr = head->next;
            }
            delete head;
            head = NULL;
            length = 0;
        }
    }
};

int main()
{
    MoRa();

    CirclyLinkedList l;

    l.addToTail(10);
    l.addToTail(20);
    l.addToTail(30);
    l.addToTail(40);
    l.addToTail(50);
    l.addToTail(60);
    cout << "List: ";l.printList();
    l.deleteNode(10);
    cout << "List: ";l.printList();
    l.deleteNode(60);
    cout << "List: ";l.printList();
    l.deleteNode(30);
    cout << "List: ";l.printList();
    l.deleteNode(100);
    cout << "List: ";l.printList();
    l.insertAfter(20,30);
    cout << "List: ";l.printList();
    l.insertAfter(50,60);
    cout << "List: ";l.printList();
    l.deleteTail();
    l.deleteTail();
    l.deleteTail();
    l.deleteTail();
    l.insertAfter(20,30);
    cout << "List: ";l.printList();
    l.deleteTail();
    l.deleteTail();
    cout << "List: ";l.printList();
    l.insertAfter(10,20);


    return 0;
}


/*
    void addToTail(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        if (isEmpty()) {
            head = newNode;
            newNode->next = head;
        }
        else {
            Node* curr = head;
            while (curr->next != head) {
                curr = curr->next;
            }
            curr->next = newNode;
            newNode->next = head;
        }
        length++;
    }

    void addToTail(int value){
        Node*newNode=new Node;
        newNode->data=value;
        if(isEmpty()){
            newNode->next=head;
            head=newNode;
        }
        else{
            Node*curr=head;
            while(curr->next!=head){
                curr=curr->next;
            }
            curr->next=newNode;
            newNode->next=head;
        }
        lenght++;
    }
    
    void deleteHead(){
        if(isEmpty()) return;
        else if(head->next==head){
            delete head;
            head=NULL;
            length--;
        }
        else{
            Node*curr=head;
            while(curr->next!=head){
                curr=curr->next;
            }
            head=head->next;
            delete curr->next;
            curr->next=head;
            lentgh--;
        }
    }

    void deleteTail(){
        if(isEmpty()) return;
        else if(head->next=head){
            delete head;
            head=NULL;
            length--;
        }
        else{
            Node*curr=head;
            while(curr->next->next!=head){
                curr=curr->next;
            }
            delete curr->next;
            curr->next=head;
            length--;
        }
    }
    
    int size(){return length;}


*/