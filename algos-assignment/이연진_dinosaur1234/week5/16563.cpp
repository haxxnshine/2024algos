#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<bool> v(5000001, true);
	vector<int> prime;

	v[0] = v[1] = false;
	for (int i = 2; i * i <= 5000000; i++) { //에라토스테네스의 체
		if (v[i]) {
			prime.push_back(i);
			for (int j = i * i; j <= 5000000; j += i) {
				v[j] = false;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < prime.size() && prime[j] * prime[j] <= k; ++j) { 
			while (k % prime[j] == 0) {
				cout << prime[j] << " ";
				k /= prime[j];
			}
			
		}
		if (k > 1) {
			cout << k << " ";
		}
		cout << "\n";
	}

	return 0;
}
