#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n,m,in1;
    cin >> n >> m;

    int** A = new int *[n];
    for (int i=0; i<n; i++) {
        A[i] = new int[m];
        for (int j=0; j<m; j++) {
            cin >> in1;
            A[i][j] = in1;
        }
    }

    int* b = new int[m];
    for (int j=0; j<m; j++) {
        cin >> in1;
        b[j] = in1;
    }

    int c,c1,c2;
    for (int i=0; i<n; i++) {
        c = 0;
        for (int j=0; j<m; j++) {
            c +=  A[i][j] * b[j];
        }
        cout << c << endl;
    }
    delete[] A;
    delete[] b;
    A=0;
    b=0;
}
