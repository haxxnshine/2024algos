#include <iostream>
#include <string.h>
using namespace std;

typedef long double ld;
// 2 <= N <= 1000
// 1 <= K <= 1000
ld N, K;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 절대/상대 오차는 10^(-6)까지 허용한다.
	cout << fixed;
	cout.precision(12);

	// 합주단원의 수 N, 곰곰이 연주할 수 있는 음의 개수 K가 차례로 주어진다.
	cin >> N >> K;

	// 식사가 일어나는 횟수의 기댓값을 출력한다.
	// 식사 횟수의 기대값
	// = 곰곰쌍의 개수(N * (N - 1)/2) * 곰곰쌍 둘이 식사할 확률(1 / K)
	cout << N * (N - 1) / 2 * (1 / K);

	return 0;
}