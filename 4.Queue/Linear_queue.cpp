#include<iostream>
using namespace std;
#define ll long long
#define nl "\n"
#define Max_Size 100


class Queue {
    int arr[Max_Size];
	int front,rear;
public:
	Queue(){
        front = rear = -1;
    }
    
    bool isEmpty(){
        return (front==-1 && rear==-1);
    }
    bool isFull(){
        return rear == Max_Size-1;
    }
    void enqueue(int value){
        if(isFull()){
            cout<<"Queue Overflow!\n";
            return;
        }
        else if(isEmpty()){
            front++;
        }
        arr[++rear]=value;
    }
    int dequeue(){
        if(isEmpty()){
            cout<<"Queue Underflow!\n";
            exit(1);
        }
        else if(front==rear){
            int temp=arr[front];
            front = rear =-1;
            return temp;
        }
        else{
            return arr[front++];
        }
    }
    int peek(){
        if(isEmpty()){
            cout<<"Queue Underflow!\n";
            exit(1);
        }
        else{
            return arr[front];
        }
    }
    void printQueue(){
        if(isEmpty())
            return;
        else{
            for(int i=front;i<=rear;i++){
                cout<<arr[i]<<' ';
            }
            cout<<nl;
        }
    }
};

int main()
{
	Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.printQueue();

	return 0;
}