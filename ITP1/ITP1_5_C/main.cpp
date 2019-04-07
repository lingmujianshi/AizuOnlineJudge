#include <iostream>
using namespace std;

char reverce(char chr) {
	char res;
	if(chr=='.') res='#';
	else res='.';
	return res;
}

int main() {
	int h,w;
	
	while(1) {
		cin >> h >> w;
		char c,ic='#';
		if (h==0 && w==0) break;
		for (int j=0;j<h;j++){
			ic = reverce(ic);
			c = ic;
			for (int i=0;i<w;i++){
				c = reverce(c); 
				cout << c;
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}