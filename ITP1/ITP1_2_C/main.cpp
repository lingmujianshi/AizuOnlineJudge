#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int a,b,c,x;
    cin >> a >> b >> c;
    if (a > b) {
        x = a;
        a = b;
        b = x;
    }
    if (a > c) {
        x = a;
        a = c;
        c = x;
    }
    if (b > c) {
        x = b;
        b = c;
        c = x;
    }
    cout << a << " " << b << " " << c << endl;
    return 0;
}
