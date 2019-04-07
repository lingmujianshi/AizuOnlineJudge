#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int x,h,m1,m,s;
    cin >> x;
    h = x / 3600;
    m1 = x % 3600;
    m = m1 / 60;
    s = m1 % 60;
    cout << h << ":" << m << ":" << s << endl;
    return 0;
}