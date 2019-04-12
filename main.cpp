//ALDS1_3_C Elementary data structures - Doubly Linked List
#include <iostream>
#include <string>
using namespace std;

class Array
{
private:
    static const int MAX = 11;

public:
    Array(){}

private:
    int A[MAX]={};
    int top=0;

private:
    bool isEmpty()
    {
        return top-1 == 0;
    }

    bool isFull()
    {
        return top >= MAX - 1;
    }

public:
    void insert(int ptr, int val)
    {
        if(isFull())
        {
            throw runtime_error("Array is full");
        }
        for (int i = top; i > ptr; i--)
        {
            A[i+1] = A[i];
        }
        top++;
        A[ptr] = val;
    }

    int picup(int ptr)
    {
        if (isEmpty())
        {
            throw runtime_error("Array is empty");
        }
        int result = A[ptr];
        for (int i = ptr; i < top; i++)
        {
            A[i] = A[i+1];
        }
        A[top]=0;
        top--;

        return result;
    }

    void dump()
    {
        for (int i=0; i<=top; i++ ) {
            cout << A[i] << " ";
        }
        cout << endl;
    }

};

int main()
{
    size_t num;
    //cin >> num;
    num = 2;
    Array a;
    string buf,s[10];
    for (size_t i = 0; i < num; i++)
    {
        int j = 0;
        while(getline(cin,buf,' '))
        {
            s[j]=buf;
            j++;
        }

        
    }
    

    return 0;
}