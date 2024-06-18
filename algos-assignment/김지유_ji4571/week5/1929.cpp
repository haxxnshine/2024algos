#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int prime[1000005] = { 0, 1, 0, };

void isPrime() {
	for (int i = 2; i < m; i++) {
		if (prime[i] == 0) {
			for (int j = 2; i * j <= m; j++)prime[j * i] = 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	isPrime();

	for (int i = n; i <= m; i++)
		if(prime[i]==0) cout << i << "\n";

	return 0;
}
