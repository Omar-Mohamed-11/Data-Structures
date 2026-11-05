#include <iostream>
#include <string>
using namespace std;
#define ll long long
#define nl "\n"

// ---------------Stack Implimentation--------------- //
// Stcak of characters
class Node{
public:
    char data;
    Node *next;
};
class Stack{
    Node *head;
    int length = 0;

public:
    Stack()
    {
        head = NULL;
    }

    bool empty()
    {
        return head == NULL;
    }

    void push(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        length++;
    }

    void pop()
    {
        if (empty())
            cout << "Stack Underflow!\n";
        else
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    int topEl()
    {
        if (empty())
        {
            cout << "Stack Underflow!\n";
            exit(1);
        }
        else
        {
            return head->data;
        }
    }

    int topAndPop()
    {
        if (empty())
        {
            cout << "Stack Underflow!\n";
            exit(1);
        }
        else
        {
            Node *temp = head;
            head = head->next;
            int temp2 = temp->data;
            delete temp;
            return temp2;
        }
    }

    // ---------searchStack--------//
    int searchStack(int value)
    {
        if (empty())
            return -1;
        else
        {
            int pos = -1;
            Node *temp = head;
            int i = 0;
            while (temp != NULL)
            {
                if (temp->data == value)
                {
                    pos = i;
                    break;
                }
                temp = temp->next;
                i++;
            }
            return pos;
        }
    }
    // ----------------- //

    void print()
    {
        if (empty())
            return;
        else
        {
            Node *temp = head;
            while (temp != NULL)
            {
                cout << temp->data << ' ';
                temp = temp->next;
            }
            cout << nl;
        }
    }

    int size()
    {
        return length;
    }

    ~Stack()
    {
        Node *temp = head;
        while (!empty())
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }
};
// Stack of integers
class node{
public:
    int data;
    node *next;
};
class stack{
    node *head;
    int length = 0;

public:
    stack()
    {
        head = NULL;
    }

    bool empty()
    {
        return head == NULL;
    }

    void push(int value)
    {
        node *newNode = new node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        length++;
    }

    void pop()
    {
        if (empty())
            cout << "Stack Underflow!\n";
        else
        {
            node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    int topEl()
    {
        if (empty())
        {
            cout << "Stack Underflow!\n";
            exit(1);
        }
        else
        {
            return head->data;
        }
    }

    int topAndPop()
    {
        if (empty())
        {
            cout << "Stack Underflow!\n";
            exit(1);
        }
        else
        {
            node *temp = head;
            head = head->next;
            int temp2 = temp->data;
            delete temp;
            return temp2;
        }
    }

    // ---------searchStack--------//
    int searchStack(int value)
    {
        if (empty())
            return -1;
        else
        {
            int pos = -1;
            node *temp = head;
            int i = 0;
            while (temp != NULL)
            {
                if (temp->data == value)
                {
                    pos = i;
                    break;
                }
                temp = temp->next;
                i++;
            }
            return pos;
        }
    }
    // ----------------- //

    void print()
    {
        if (empty())
            return;
        else
        {
            node *temp = head;
            while (temp != NULL)
            {
                cout << temp->data << ' ';
                temp = temp->next;
            }
            cout << nl;
        }
    }

    int size()
    {
        return length;
    }

    ~stack()
    {
        node *temp = head;
        while (!empty())
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }
};

// --------------------Functions-------------------- //

void reverseSentence(string &s){
    Stack st;
    for (auto &c : s)
    {
        st.push(c);
    }
    s = "";
    while (!st.empty())
    {
        s += st.topEl();
        st.pop();
    }
}

bool checkBalance(string s){
    Stack st;
    for (char c : s)
    {
        if (c == '(' || c == '[' || c == '{')
            st.push(c);
        else
        {
            if (st.empty())
                return 0;
            else if ((c == ')' && st.topEl() != '(') ||
                     (c == ']' && st.topEl() != '[') ||
                     (c == '}' && st.topEl() != '{'))
                return 0;
            else
                st.pop();
        }
    }
    return st.empty();
}
// OR //
/*
    bool checkBalance(string s){
        stack st;
        for (auto &c : s) {
            if (st.empty())
                st.push(c);
            else if ((c == ')' && st.top() == '(') ||
                    (c == '}' && st.top() == '{') ||
                    (c == ']' && st.top() == '['))
                st.pop();
            else if(st.top()==']' || st.top()=='}' || st.top()==')')
                return 0;
            else
                st.push(c);
        }
        return st.empty();
    }
*/
// // //

bool isPalindrome(string s){
    Stack st;
    for (auto &c : s)
    {
        st.push(c);
    }
    for (auto &c : s)
    {
        if (c != st.topEl())
            return 0;
        st.pop();
    }
    return 1;
}

string decToBin(int num){
    Stack st;
    string s = "";
    while (num)
    {
        st.push((num % 2) + '0');
        num /= 2;
    }
    while (!st.empty())
    {
        s += st.topEl();
        st.pop();
    }
    return s;
}

int Priority(char op)
{
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/' || op == '%')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

string infix_to_postfix(string infix)
{
    Stack st;
    string postfix = "";
    for (int i = 0; i < infix.size(); i++)
    {
        if (isspace(infix[i]))
            continue;
        else if (isdigit(infix[i]))
        {
            while (i < infix.size() && isdigit(infix[i]))
                postfix += infix[i], i++;
            postfix += ' ';
            i--;
        }
        else if (infix[i] == '(')
        {
            st.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (!st.empty() && st.topEl() != '(')
            {
                postfix += st.topEl();
                postfix += ' ';
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && Priority(infix[i]) <= Priority(st.topEl()))
            {
                postfix += st.topEl();
                postfix += ' ';
                st.pop();
            }
            st.push(infix[i]);
        }
    }
    while (!st.empty())
    {
        postfix += st.topEl();
        postfix += ' ';
        st.pop();
    }
    return postfix;
}

int evaluate_postfix(string postfix){
    stack st;
    for (int i = 0; i < postfix.size(); i++)
    {
        if (isspace(postfix[i]))
            continue;
        else if (isdigit(postfix[i]))
        {
            int num = 0;
            while (i < postfix.size() && isdigit(postfix[i]))
            {
                num *= 10;
                num += (postfix[i] - '0');
                i++;
            }
            st.push(num);
            i--;
        }
        else
        {
            int second = st.topAndPop();
            int first = st.topAndPop();

            switch (postfix[i])
            {
            case '+':
                st.push(first + second);
                break;
            case '-':
                st.push(first - second);
                break;
            case '/':
                st.push(first / second);
                break;
            case '*':
                st.push(first * second);
                break;
            }
        }
    }
    return st.topEl();
}

// -------------------------------------------------- //

int main()
{
    string s1, s2, s3, s4;
    int num;

    cout << "Enter Your Sentence: ";
    getline(cin, s1);
    reverseSentence(s1);
    cout << "Revesed Sentence: " << s1 << nl;

    cout << "Enter Your String: ";
    cin >> s2;
    if (checkBalance(s2))
        cout << "Balanced" << nl;
    else
        cout << "Not Balanced!" << nl;

    cout << "Enter Your String: ";
    cin >> s3;
    if (isPalindrome(s3))
        cout << "Palindrome" << nl;
    else
        cout << "Not Palindrome!" << nl;

    cout << "Enter The Number In Decimal: ";
    cin >> num;
    cout << "Number In Binary: " << decToBin(num) << nl;
    cin.ignore();

    cout << "Enter Infix: ";
    getline(cin, s4);
    cout << "Postfix: " << infix_to_postfix(s4) << nl;
    cout << "Value: " << evaluate_postfix(infix_to_postfix(s4)) << nl;

    return 0;
}