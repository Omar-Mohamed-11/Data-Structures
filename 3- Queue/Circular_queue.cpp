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
        return (front == (rear+1) % Max_Size);
    }
    void enqueue(int value){
        if(isFull()){
            cout<<"Queue Overflow!\n";
            return;
        }
        else if(isEmpty()){
            front++;
        }
        rear = (rear + 1) % Max_Size;
        arr[rear]=value;
    }
    int dequeue(){
        if(isEmpty()){
            cout<<"Queue Underflow!\n";
            exit(1);
        }
        else if(front == rear){
            int temp = arr[front];
            front = rear =-1;
            return temp;
        }
        else{
            int temp = arr[front];
            front = (front + 1) % Max_Size;
            return temp;
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
            for(int i=front; i!=rear; i=(i+1)%Max_Size){
                cout<<arr[i]<<' ';
            }
            cout << arr[rear] << nl;
        }
    }
    int length(){
        if(isEmpty()) return 0;

        int len=1;
        for(int i=front; i!=rear; i=(i+1)%Max_Size){
            len++;
        }
        return len;
    }
    void enqueueN(int enArr[], int n){
        for(int i=0;i<n;i++){
            enqueue(enArr[i]);
        }
    }
    int *dequeueN(int n){
        int len = length();
        if(isEmpty()){
            cout<<"The Queue Is Empty!\n";
            return nullptr;
        }
        else if(n>len){
            cout<<"Invalid Size!\n";
            return nullptr;
        }
        else{
            int *res=new int[n];
            for(int i=0;i<n;i++){
                res[i]=dequeue();
            }
            return res;
        }
    }
    int searchQueue(int item){
        if(isEmpty())return -1;
        int pos=-1; int cnt=0;
        for(int i=front; i!=rear; i=(i+1)%Max_Size){
            if(arr[i]==item){
                pos=cnt;
                return pos;
            }
            cnt++;
        }
        if(arr[rear]==item) pos=cnt;
        return pos;
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
    cout<<"Queue: "; q.printQueue();
    
    cout<<"Queue Length = "<<q.length()<<nl;

    int enArr[4]={60,70,80,90};
    q.enqueueN(enArr,4);
    
    int *arr = q.dequeueN(3);
    cout<<"DequeueN Array: ";
    for(int i=0;i<3;i++)
        cout<<arr[i]<<' ';
    cout<<nl;

    cout<<"Queue: "; q.printQueue();

    cout<<"Position of 60 is: "<<q.searchQueue(60)<<nl;

	return 0;
}