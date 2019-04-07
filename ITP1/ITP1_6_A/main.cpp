#include <iostream>
using namespace std;

int main()
{
	int n, x, data[100];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		data[i] = x;
	}
	for (int i = n-1; i >= 0; i--) {
		cout << data[i];
		if (i > 0)
			cout << ' ';
	}
	cout << endl;
}