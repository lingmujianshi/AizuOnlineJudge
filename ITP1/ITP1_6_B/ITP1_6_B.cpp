#include <iostream>
using namespace std;

int main()
{
	int n, number,k,num;
	char kind;
	bool cards[4][13];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			cards[i][j] = false;
		}
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> kind >> number;
		if (kind == 'S') k = 0;
		else if (kind == 'H') k = 1;
		else if (kind == 'C') k = 2;
		else if (kind == 'D') k = 3;
		num = number - 1;
		cards[k][num] = true;
	}
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			if (cards[i][j] == false) {
				if (i == 0) cout << "S " << (j + 1) << endl;
				else if (i == 1) cout << "H " << (j + 1) << endl;
				else if (i == 2) cout << "C " << (j + 1) << endl;
				else cout << "D " << (j + 1) << endl;
			}
		}
	}
}