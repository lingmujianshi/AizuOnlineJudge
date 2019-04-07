//ALDS1_3_A Stack - Elementary data structures - Stack
#include <iostream>
#include <string>
using namespace std;

class Stack
{
private:
    static const int MAX = 101;

public:
    Stack()
    {
        inisialize();
    }

private:
    int S[MAX];
    int top;

private:
    void inisialize()
    {
        top = 0;
    }

    bool isEmpty()
    {
        return top==0;
    }

    bool isFull()
    {
        return top >= MAX - 1;
    }

public:
    void push(int x)
    {
        if(isFull())
        {
            //error
            throw runtime_error("Stack is full");
        }
        top++;
        S[top] = x;
    }

    int pop()
    {
        if (isEmpty())
        {
            //error
            throw runtime_error("Stack is empty");
        }
        top--;

        return S[top+1];
    }

    int getTop()
    {
        return top;
    }

    void print()
    {
        cout << "top: " << top << " stack[ ";

        for (int i=0; i<=top; i++ ) {
            cout << S[i] << " ";
        }
        cout << "]" << endl;
    }
};



int main()
{
    Stack stack;
    string str;
    int ans = 0,a,b;

    while(cin >> str)
    {
        if (str == "+") {
            b = stack.pop();
            a = stack.pop();
            stack.push(a+b);
        } else if (str == "-") {
            b = stack.pop();
            a = stack.pop();
            stack.push(a-b);
        } else if (str == "*") {
            b = stack.pop();
            a = stack.pop();
            stack.push(a*b);
        } else {
            stack.push(stoi(str));
        }
    }
    cout << stack.pop() << endl;

    return 0;
}

void test(Stack s)
{
    try {
        s.push(100);
        s.push(101);
        s.push(102);
        s.push(103);
        s.push(104);
        s.print();
        s.push(105);
        s.push(106);
        s.print();
        cout << s.pop() << endl;
        cout << s.pop() << endl;
        s.print();
    }
    catch(out_of_range& e) {
        //cerr << "err" << e.what() << endl;
    }
}