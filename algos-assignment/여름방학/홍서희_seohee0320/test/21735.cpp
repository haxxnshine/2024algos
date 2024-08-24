#include <iostream>
using namespace std;;

int n, m, arr[101];

int noon(int loc, int count, int size) {
	if (count > m) return 0;
	if (count == m) return size;
	int res = 0;
	res = max(noon(loc + 1, count + 1, size + arr[loc + 1]), noon(loc + 2, count + 1, size / 2 + arr[loc + 2]));
	return res;
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	cout << noon(0, 0, 1);
	
}
