#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int c;
    int i = 0;
    while(cin >> c && c) {
        cout << "Case " << i++ << ": " << c << endl;
    }
    return 0;
}
