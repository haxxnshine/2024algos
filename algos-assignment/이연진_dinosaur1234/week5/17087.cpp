#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, S, A;
	cin >> N >> S;
	vector<int> v(N);

	for (int i = 0; i < N; i++) {
		cin >> A;
		v[i] = abs(A-S); //S와 A의 거리 측정
	}
	int result = v[0];
	for (int j = 1; j < N; j++) {
		result = gcd(result,v[j]);
	}
	cout << result << "\n";
	return 0;
}
