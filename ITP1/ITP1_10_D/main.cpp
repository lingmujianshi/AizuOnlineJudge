#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    double a[100], b[100];
    cin >> n;
    
    for (int i = 0; i < n; i++)
        cin >> a[i];    

    for (int i = 0; i < n; i++)
        cin >> b[i];    

    cout << fixed;

    // p1
    double p1 = 0;
    for (int i = 0; i < n; i++)
        p1 += abs(a[i] - b[i]);
    
    cout << p1 << endl;

    // p2
    double p2 = 0;
    for (int i = 0; i < n; i++)
        p2 += pow( abs(a[i] - b[i]),2.0);
    cout << sqrt(p2) << endl;

    // p3
    double p3 = 0;
    for (int i = 0; i < n; i++)
        p3 += pow( abs(a[i] - b[i]),3.0);
    cout << pow (p3,1/3.0) << endl;

    //  infinite
    double pmax = 0;
    double calc;
    for (int i = 0; i < n; i++)
    {
        calc = abs(a[i]-b[i]); 
        if (pmax < calc) {
            pmax = calc;
        }
    }
    cout << pmax << endl;

    return 0;
}
