#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n,x;
    long max,min,sum;
    cin >> n;
    x=0;
    sum=0;
    max=-1000000;
    min=1000000;
    for (int i=0;i<n;i++){
        cin >> x;
        sum += x;
        if (max < x) max = x;
        if (min > x) min = x;
    }
    cout << min << " " << max << " " << sum << endl;
    return 0;
}
