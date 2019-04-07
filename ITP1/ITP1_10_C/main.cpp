#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int s[1000],n,total;
    double m,a;
   
    while (cin >> n && n) {
        total = 0;
        for (int i=0; i<n; i++ ){
            cin >> s[i];
            total+=s[i];
        }
        m = (double)total / n;

        double smTotal=0.0;
        for (int i=0; i<n; i++ ){
            smTotal += (s[i]-m)*(s[i]-m);
        }
        a = sqrt(smTotal/n);

        cout << fixed << a << endl;
    }

    return 0;
}
