//ALDS1_3_B Queue - Elementary data structures - Stack
#include <iostream>
#include <string>
using namespace std;

class Queue
{
  private:
    static const int MAX = 100005;

  public:
    Queue()
    {
        inisialize();
    }

private:
    int Q[MAX]{};
public:
    int head, tail;

  private:
    void inisialize()
    {
        head = tail = 0;
    }

    bool isFull()
    {
        return head == (tail+1) % MAX;
    }

  public:
    bool isEmpty()
    {
        return head == tail;
    }

    void enqueue(int x)
    {
        if (isFull())
        {
            //error
            throw runtime_error("Overflow");
        }
        Q[tail] = x;
        if ((tail + 1) == MAX)
        {
            tail = 0;
        }
        else
        {
            tail++;
        }
    }

    int dequeue()
    {
        if (isEmpty())
        {
            //error
            throw runtime_error("Underflow");
        }
        int x = Q[head];
        Q[head]=0;
        if ((head + 1) == MAX)
        {
            head = 0;
        }
        else
        {
            head++;
        }
        return x;
    }

    int num()
    {
        int res;
        if (tail >= head) {
            res = tail - head;
        } else {
            res = tail + MAX - head +1;
        }
        return res;
    }

    void print()
    {
        cout << "頭" << head << " 尾" << tail << " 空" << (int)isEmpty() << " 満" << (int)isFull()<<" 数"<< num() << " Q[";

        for (int i = 0; i < MAX; i++)
        {
            cout << Q[i] << " ";
        }
        cout << "]" << endl;
    }
};

int main()
{
    string s[100005];
    int t[100005];
    int num,time;
    Queue q;

    cin >> num >> time;

    for(int i = 0; i < num; i++)
    {
        cin >> s[i] >> t[i];
        q.enqueue(i);
    }

    int id;
    int totalTime = 0;
    while(!q.isEmpty())
    {
        id =q.dequeue();
        if(t[id]<=time) {
            cout << s[id]  << " " << totalTime + t[id] << endl;
            totalTime = totalTime + t[id];
        }
        else
        {
            t[id] -= time;
            q.enqueue(id);
            totalTime += time;
        }

    }
    return 0;
}
