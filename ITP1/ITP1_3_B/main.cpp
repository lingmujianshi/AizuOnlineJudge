#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int data[10000],c;
    c=0;
    while(1) {
        cin >> data[c];
        if (data[c]==0) break;
        c++;
    }
    for (int i=0;i<c;i++) {
        cout << "Case " << i+1 << ": " << data[i] << endl;
    }
    return 0;
}
