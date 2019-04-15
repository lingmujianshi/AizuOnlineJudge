//ALDS1_3_C Elementary data structures - Doubly Linked List
#include<cstdio>
#include <iostream>
#include <string>
using namespace std;

class Array
{
private:
    static const unsigned int MAX = 2000000001;
    int* A;
    unsigned int top;

public:
    Array()
    {
        top = 0ul;
        A = new int[MAX]; 
    }
    ~Array()
    {
        A = nullptr;
        delete[] A; 
    }

private:
    bool isEmpty()
    {
        return top-1 < 0;
    }

    bool isFull()
    {
        return top >= MAX - 1;
    }

public:
    void insert(unsigned int ptr, int val)
    {
        if(isFull())
        {
            throw runtime_error("Array is full");
        }
        for (unsigned int i = top; i >= ptr; i--)
        {
            A[i+1] = A[i];
            if(i==0) break;
        }
        top++;
        A[ptr] = val;
    }

    int picup(unsigned int ptr)
    {
        if (isEmpty())
        {
            throw runtime_error("Array is empty");
        }
        int result = A[ptr];
        for (unsigned int i = ptr; i < top; i++)
        {
            A[i] = A[i+1];
        }
        A[top]=0;
        top--;

        return result;
    }

    void del(unsigned int key)
    {
        for (unsigned int i = 0; i < top; i++)
        {
            if (A[i]==key)
            {
                picup(i);
                break;
            }
        }
    }

    unsigned int getLast()
    {
        return top;
    }

    void dump()
    {
        for (unsigned int i=0; i<top; i++ ) {
            cout << A[i];
            if(i<top-1) cout << " ";
        }
        cout << endl;
    }

};

int main()
{
    unsigned int num;
    scanf("%d",&num);
    Array a;
    string buf,s[10];
    string syntax;
    unsigned int op;
    for (unsigned int i = 0; i < num; i++)
    {
        cin >> syntax;
        if (syntax == "insert")
        {
            scanf("%d",&op);
            a.insert(0,op);
        }
        else if (syntax == "delete")
        {
            scanf("%d",&op);
            a.del(op);
        }
        else if (syntax == "deleteFirst")
        {
            a.picup(0);
        }
        else if (syntax == "deleteLast")
        {
            a.picup(a.getLast());
        }
        else
        {
            cout << "none" << endl;
        }     
    }
    a.dump();
    return 0;
}