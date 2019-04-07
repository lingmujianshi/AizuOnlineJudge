#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int r,c,d;
    cin >> r >> c;

    int** a = new int *[r];
    for (int i=0; i<r; i++){
        a[i] = new int [c];
        for (int j=0; j<c; j++){
            cin >> d;
            a[i][j]=d;
        }
    }

    int rTotal;
    int * cTotal = new int [c];

    for (int i=0; i<c; i++){
        cTotal[i]=0;
    }

    for (int i=0; i<r; i++){
        rTotal=0;
        for (int j=0; j<c; j++){
            cout << a[i][j] << " ";
            rTotal +=  a[i][j];
            cTotal[j] += a[i][j];
        }
        cout << rTotal << endl;
    }

    int total=0;
    for (int i=0; i<c; i++){
        cout << cTotal[i] << " ";
        total += cTotal[i];
    }
    cout << total << endl;
    delete[] a;
    delete[] cTotal;
    a=0;
    cTotal=0;
    return 0;
}
