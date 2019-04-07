//ALDS1_2_D Sort I - Shell Sort
#include <iostream>
using namespace std;

void trace(int c[], size_t n)
{
    for(int i=0; i<n; i++ ) {
        cout << c[i];
        if(i<n-1) cout << " ";
    }
    cout << endl;
}

void traceV(int c[], size_t n)
{
    for(int i=0; i<n; i++ ) {
        cout << c[i] << endl;
    }
}

int insertionSort(int A[], int n, int gap)
{
    int j,key,cnt=0;

    for (int i = gap; i < n; i++)
    {
        key = A[i];
        j = i - gap;        
        while (j >= 0 && A[j] > key)
        {
            A[j+gap] = A[j];
            j= j - gap;
            cnt++;
        }
        A[j+gap] = key;
    }  
    return cnt;
}

void shellSort(int A[], int n)
{
    int cnt=0;
    int G[20];
    int d = 2;
    int count = 0;
    int nS=0;
    int nIns;
    int gap;

    if (n<=d) {
        nIns = insertionSort(A,n,d-1);
            G[nS++] = d-1;
            count += nIns;
    } else {
        for (gap = n/d; gap>0; gap /= d) {
            nIns = insertionSort(A,n,gap);
            G[nS++] = gap;
            count += nIns;
        }
    }
    cout << nS << endl;
    trace(G,nS);
    cout << count << endl;
    traceV(A,n);
}

int main()
{
    size_t length;
    cin >> length;
    int a[1000000];
    
    for(size_t i=0; i<length; i++) {
        cin >> a[i];
    }
    shellSort(a,length);

}
