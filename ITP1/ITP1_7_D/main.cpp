#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, m, l, d;
    cin >> n >> m >> l;
    int** A = new int*[n];
    for(int i = 0; i < n; i++){
        A[i] = new int[m];
        for(int j = 0; j < m; j++){
            cin >> d;
            A[i][j] = d;
        }        
    }
    
    int** B = new int*[m];
    for(int i = 0; i < m; i++){
        B[i] = new int[l];
        for(int j = 0; j < l; j++){
            cin >> d;
            B[i][j] = d;
        }        
    }

    long ans;
    for(int i = 0; i < n; i++)    {
        for(int j = 0; j < l; j++) {
            ans=0;
            for(int k = 0; k < m; k++){
                long a = A[i][k];
                long b = B[k][j];
                ans += a*b; 
            }
            cout << ans;
            if (j < l-1) cout << " ";
        }
        cout << endl;
    }

    delete[] A;
    delete[] B;
    A = 0;
    B = 0;

    return 0;
}
