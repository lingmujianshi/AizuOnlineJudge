#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

int main()
{
    long r;
    size_t n;
    long maxv=numeric_limits<long>::lowest();
    cin >> n >> r;
    long minv=r;
    for(size_t j = 1; j <=200000; j++)
    {
        cin >> r;
        maxv = max(maxv, r-minv);
        minv = min(minv, r);
        if(j>=n-1) break;
    }
    cout << maxv << endl;
}