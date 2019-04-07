#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int a,b;
    string s="";
    cin >> a >> b;
    if(a<b) s="a < b";
    if(a>b) s="a > b";
    if(a==b) s="a == b";
    cout << s << endl;
    return 0;
}