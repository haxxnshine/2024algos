#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, B;

	cin >> A >> B;

	vector<bool> v(B + 1, true);
	vector<int> prime;

	v[1] = false;
	for (int i = 2; i <= B; i++) { //에라토스테네스의 체
		if (v[i]) {
			prime.push_back(i);
			for (int j = 2 * i; j <= B; j += i) {
				v[j] = false;
			}
		}
	}

	int f_count = 0;
	for (int k = A; k <= B; ++k) {
		int k2 = k;
		int count = 0;
		for (int j = 0; j < prime.size() && prime[j] <= k2; ++j) {
			while (k2 % prime[j] == 0) {
				k2 /= prime[j];
				count++;
			}
		}
		if (count > 0 && binary_search(prime.begin(), prime.end(), count)) {
			f_count++;
		}
	}

	
	cout << f_count << "\n";
	return 0;
}
