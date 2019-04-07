#include <iostream>
#include <array>
#include <vector>
using namespace std;

struct Dice
{
    array<int, 6> roll;
    
    void toNorth()
    {
        array<int, 6> t = roll;
        roll[4] = t[0];
        roll[0] = t[1];
        roll[5] = t[4];
        roll[1] = t[5];
    }

    void toCW()
    {
        array<int, 6> t = roll;
        roll[3] = t[1];
        roll[1] = t[2];
        roll[4] = t[3];
        roll[2] = t[4];
    }

    int isSame(Dice &d2)
    {
        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++){
                for (int k=0; k<4; k++){
                    if (roll[0] == d2.roll[0] &&
                        roll[1] == d2.roll[1] &&
                        roll[2] == d2.roll[2] &&
                        roll[3] == d2.roll[3] &&
                        roll[4] == d2.roll[4] &&
                        roll[5] == d2.roll[5]){
                            return true;
                        }
                    toCW();
                }
                toNorth();
            }
            toCW();
        }
        return false;
    }
};

int main()
{
    int count;
    vector<Dice> dices;
    cin >> count;

    for (int i=0; i<count; i++) {
        Dice d;
        for (int j=0; j<6; j++) {
            cin >> d.roll[j];
        }
        dices.push_back(d);
    }
    
    bool judge = true;
    for (int i=0; i<count; i++) {
        for (int j=i+1; j<count; j++) {
            if(dices[i].isSame(dices[j])) {
                judge = false;
            }
        }
    }

    cout << (judge ? "Yes" : "No") << endl;
 }

