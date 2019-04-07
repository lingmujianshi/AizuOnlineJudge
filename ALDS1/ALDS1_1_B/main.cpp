#include <iostream>
using namespace std;
  
int gcd(int a,int b)
{
    int r;
    r = a % b;
    if (r == 0)
        return b;
    else
        return gcd(b,r);
}
  
int main()
{
    int x, y;
    cin >> x >> y;
    cout << gcd(x, y) << endl;
    return 0;
}