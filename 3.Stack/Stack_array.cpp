#include<iostream>
using namespace std;
#define ll long long
#define nl "\n"
#define Max_Size 100
#define Error INT_MIN

class Stack {
	int top;
	int arr[Max_Size];
public:
	Stack(){
        top=-1;
    }
    
    bool empty(){
        return top==-1;
    }

    void push(int value){
        if(top==Max_Size-1){
            cout<<"Stack Overflow!\n";
            return;
        }
        else
            arr[++top]=value;
    }

    void pop(){
        if(empty()){
            cout<<"Stack Underflow!\n";
            return;
        }
        else
            top--;
    }

    int topEl(){
        if(empty()){
            cout<<"Stack Underflow!\n";
            exit(1);
        }
        else
            return arr[top];
    }

    int searchStack(int value){
        int pos=-1;
        for(int i=0;i<=top;i++){
            if(arr[i]==value){
                pos=i;
                break;
            }
        }
        return pos;
    }

    int size(){
        return top+1;
    }

    void print(){
        if(empty()) return;
        for(int i=top; i>=0 ; i--){
            cout<<arr[i]<<' ';
        }
        cout<<nl;
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

	return 0;
}