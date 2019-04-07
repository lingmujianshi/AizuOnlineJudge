#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main(int argc, char const *argv[])
{
    double r,pi;
    cin >> r;
    pi = M_PI;
    cout << fixed << setprecision(6) << (pi * r * r) << " " << (2 * pi * r) << endl;
    return 0;
}
