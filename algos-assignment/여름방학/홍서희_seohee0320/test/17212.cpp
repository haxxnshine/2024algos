#include <iostream>
using namespace std;;

int DP[100001];


int main() {

	DP[0] = 0;
	DP[1] = 1;
	DP[2] = 1;
	DP[3] = 2;
	DP[4] = 2;
	DP[5] = 1;
	DP[6] = 2;
	DP[7] = 1;

	int num;
	cin >> num;
	for(int i=8;i<=num;i++){
		DP[i] = min(DP[i - 1] + 1, DP[i - 2] + 1);
		DP[i] = min(DP[i - 5] + 1, DP[i]);
		DP[i] = min(DP[i], DP[i - 7] + 1);
	}
	cout << DP[num];

}
