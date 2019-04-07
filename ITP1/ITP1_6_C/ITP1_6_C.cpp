#include <iostream>
using namespace std;

int main()
{
	int num,people[4][3][10];
	cin >> num;
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 3;j++) {
			for (int k = 0;k < 10;k++) {
				people[i][j][k] = 0;
			}
		}
	}

	int b, f, r, v;
	v = 0;
	for (int i = 0; i < num; i++) {
		cin >> b >> f >> r >> v;
		b -= 1;f -= 1;r -= 1;
		people[b][f][r] += v;
	}

	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 3;j++) {
			for (int k = 0;k < 10;k++) {
				cout << " " << people[i][j][k];
			}
			cout <<endl;
		}
		if (i==3) break;
		for (int l = 0; l < 20; l++) {
			cout << "#";
		}
		cout << endl;
	}
}