#include <iostream>
#include <set>

using namespace std;

int main() {
	int k;
	cin >> k;
	char *c=new char[k];
	cin >> c;

	set <int> v1;
	set <int> v2;
	
	for (int i = 0; i < k; i++) {
		if (c[i] == 'R') v1.insert('R');
		if (c[i] == 'r') v2.insert('r');

		if (c[i] == 'O') v1.insert('O');
		if (c[i] == 'o') v2.insert('o');

		if (c[i] == 'Y') v1.insert('Y');
		if (c[i] == 'y') v2.insert('y');

		if (c[i] == 'G') v1.insert('G');
		if (c[i] == 'g') v2.insert('g');

		if (c[i] == 'B') v1.insert('B');
		if (c[i] == 'b') v2.insert('b');

		if (c[i] == 'I') v1.insert('I');
		if (c[i] == 'i') v2.insert('i');

		if (c[i] == 'V') v1.insert('V');
		if (c[i] == 'v') v2.insert('v');
		
	}

	if (v1.size() == 7 && v2.size() == 7) {
		cout << "YeS";
	}
	else if (v1.size() == 7) {
		cout << "YES";
	}
	else if (v2.size() == 7) {
		cout << "yes";
	}
	else cout << "NO!";
		
}
