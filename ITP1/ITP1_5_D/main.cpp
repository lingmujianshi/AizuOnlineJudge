#include <iostream>
using namespace std;

void calla(int n){
  int i = 1;
 CHECK_NUM:
  int x = i;
  if ( x % 3 == 0 ){
    cout << " " << i;
    goto END_CHECK_NUM;
  }
 INCLUDE3:
  if ( x % 10 == 3 ){
    cout << " " << i;
    goto END_CHECK_NUM;
  }
  x /= 10;
  if ( x ) goto INCLUDE3;
 END_CHECK_NUM:
  if ( ++i <= n ) goto CHECK_NUM;

  cout << endl;
}

void call(int n){
    for (int i=1; i<=n; i++) {
        if (i%3==0)
            cout << " " << i;
        else {
            int x = i;
            while(x>0){
                if(x%10==3){
                    cout << " " << i;
                    break;
                }
                x /= 10;
            }
        }
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    /* code */
    int n;
    cin >> n;
    call(n);
    return 0;
}
