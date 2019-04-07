#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int a,b,ans;
    char op;
    while(1) {
        cin >> a >> op >> b;
        if (op == '?') break;
        else if(op == '+') ans=a+b;
        else if(op == '-') ans=a-b;
        else if(op == '*') ans=a*b;
        else if(op == '/') ans=a/b;
        cout << ans << endl;

    }
    return 0;
}
