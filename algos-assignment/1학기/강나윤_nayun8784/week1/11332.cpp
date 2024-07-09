#include <iostream>
#include <string>
#include <cmath>
#define MAX 100000000

using namespace std;
typedef long long li;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	li c, n, t, l;
	li fact = 1;
	string s;

	cin >> c;
	while (c--) {
		cin >> s >> n >> t >> l;
		l *= MAX;
		l /= t; //오버플로우 발생 예방용

		if (s == "O(N)" && n > l) {
			cout << "TLE!\n";
		}
		else if (s == "O(N^2)" && n * n > l) {
			cout << "TLE!\n";
		}
		else if (s == "O(N^3)" && n * n * n > l) {
			cout << "TLE!\n";
		}
		else if (s == "O(2^N)" && pow(2, n) > l) {
			cout << "TLE!\n";
		}
		else if (s == "O(N!)") {
			if (n >= 13) {
				cout << "TLE!\n";
			}
			else {
				for (li i = 1; i <= n; i++) {
					fact *= i;
				}
				if (fact > l) {
					cout << "TLE!\n";
				}
				else {
					cout << "May Pass.\n";
				}
			}
			fact = 1;
		}
		else {
			cout << "May Pass.\n";
		}
	}
	return 0;
}
