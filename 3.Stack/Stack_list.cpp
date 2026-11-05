#include<iostream>
using namespace std;
#define ll long long
#define nl "\n"
#define Error INT_MIN

class Node{
public:
    int data;
    Node*next;
};

class Stack {
	Node*head;
    int length=0;
public:
	Stack(){
        head=NULL;
    }

    bool empty(){
        return head==NULL;
    }

    void push(int value){
        Node*newNode=new Node;
        newNode->data=value;
        newNode->next=head;
        head=newNode;
        length++;
    }

    void pop(){
        if(empty())
            cout<<"Stack Underflow!\n";
        else{
            Node*temp=head;
            head=head->next;
            delete temp;
        }
    }

    int topEl(){
        if(empty()){
            cout<<"Stack Underflow!\n";
            exit(1);
        }
        else{
            return head->data;
        }
    }

    int topAndPop(){
        if(empty()){
            cout<<"Stack Underflow!\n";
            exit(1);
        }
        else{
            Node*temp=head;
            head=head->next;
            int temp2=temp->data;
            delete temp;
            return temp2;
        }
    }

    int searchStack(int value){
        if(empty()) return -1;
        else{
            int pos=-1;
            Node*temp=head;
            int i=0;
            while(temp!=NULL){
                if(temp->data==value){
                    pos=i;
                    break;
                }
                temp=temp->next;
                i++;
            }
            return pos;
        }
    }

    void print(){
        if(empty()) return;
        else{
            Node*temp=head;
            while(temp!=NULL){
                cout<<temp->data<<' ';
                temp=temp->next;
            }
            cout<<nl;
        }
    }

    int size(){
        return length;
    }

    ~Stack(){
        Node*temp=head;
        while(!empty()){
            head=head->next;
            delete temp;
            temp=head;
        }
    }

};

int main()
{
	Stack st;
	
    if(st.empty())
        cout<<"Stack is empty\n";
    else
        cout<<"Stack size is: "<<st.size()<<nl;
        
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    cout<<"Stack: "; st.print();
    cout<<"TOP: "<<st.topEl();
    cout<<"\nPosition: "<<st.searchStack(30);

    cout<<"\nStack: ";
    while(!st.empty()){
        cout<<st.topEl()<<' ';
        st.pop();
    }
    cout<<nl<<st.topEl();
    

	return 0;
}