//ALDS1_2_C Sort I - Stable Sort
#include <iostream>
using namespace std;

struct Card
{
    char mark;
    int number;
};

void swap(Card& n1, Card& n2)
{
    Card temp;
    temp = n1;
    n1 = n2;
    n2 = temp;
}

void trace(Card c[], int n)
{
    for(int i=0; i<n; i++ ) {
        cout << c[i].mark << c[i].number;
        if(i<n-1) cout << " ";
    }
    cout << endl;
}


void bubbleSort(Card a[],int l)
{
    for(int i = 0; i < l-1; i++) {
        for(int j = (l-1); j >= (i+1); j--) {
            if (a[j].number < a[j-1].number) {
                swap(a[j],a[j-1]);
            }
        }        
    }
}

void sectionSort(Card a[],int l)
{
    int mini;
    for(int i = 0; i < l; i++) {
        mini = i;
        for(int j = i; j < l; j++) {
            if (a[j].number < a[mini].number) {
                mini = j;
            }
        }
        if (a[i].number != a[mini].number) {
            swap(a[i],a[mini]);
        }    
    }
}
bool isStable(Card b[], Card s[], int l)
{
    for(int i = 0; i < l; i++)
    {
        if(b[i].mark != s[i].mark || b[i].number != s[i].number ) {
            return false;
        }
    }
    return true;
}

int main()
{
    int l;
    cin >> l;

    Card c[36],b[36],s[36];

    for(int i=0; i<l; i++) {
        cin >> c[i].mark >> c[i].number;
        b[i].mark = s[i].mark = c[i].mark;
        b[i].number = s[i].number = c[i].number;
    }
    bubbleSort(b,l);
    trace(b,l);
    cout << "Stable" << endl;
    sectionSort(s,l);
    trace(s,l);
    isStable(b,s,l) ? (cout << "Stable" << endl) : cout << "Not stable" << endl;
}
