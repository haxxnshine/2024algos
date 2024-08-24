#include <iostream>
#include <vector>
using namespace std;

int isPrime(int num) {

	vector<bool> v(num + 1, true);
	vector<int> prime;
	int count = 0;

	//에라토스테네스의 체
	for (int i = 2; i * i <= num; i++) {
		if (v[i]) {
			for (int k = i * i; k <= num; k += i) {
				v[k] = false;
			}

		}
	}

	for (int i = 2; i < v.size(); i++) {
		if (v[i]) {
			prime.push_back(i);
			count++;
			//cout << i << " ";
		}
	}
	int sum = 0;

	bool k = 0;
	for (int i = 0; i < count  && k == 0; i++) {
		for (int j = 0; j < count && k == 0; j++) {
			sum = prime[i] + prime[j];
			if (sum == num) {
				cout << "Yes " <<  "\n";
				k = 1;
				return 0;
			}
		}
	}
	if (k == 0) {
		cout << "No" << "\n";
		return 0;
	}
}


int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {

		int num;
		cin >> num;

		isPrime(num);
	}

}
