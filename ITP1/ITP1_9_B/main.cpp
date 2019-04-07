#include <iostream>
using namespace std;

int main()
{
    string cards;
    int n,h;
    while(1){
        cin >> cards;
        if (cards[0]=='-') break;
        cin >> n;
        size_t l = cards.size();
        for (int i=0; i<n; i++){
            cin >> h; 
            string cc = cards + cards;
            cards = cc.substr(h,l);
        }
        cout << cards << endl;
    }
    return 0;
}
