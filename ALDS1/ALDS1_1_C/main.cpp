#include <iostream>
using namespace std;
 
bool isPrime(int const num)
{
    if (num <= 3)
        return num > 1;
    else if (num % 2 == 0 || num % 3 == 0)
        return false;
    else
    {
        for (int i = 5; i * i <= num; i += 6)
        {
            if (num % i == 0 || num % (i+2) == 0)
                return false;
        }
    }
    return true;
}

int main()
{
    int n,a,c=0;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a;
        if(isPrime(a))
            c++;
    }
    cout << c << endl;
}