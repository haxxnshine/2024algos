#include <iostream>
#define ll long long
#define ld long double
using namespace std;

// 1 <= N <= 100000
int N;
// 0 <= pi <= 1
ld parr[100010];
ld ans = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // 전구 스트립에는 전구 N개가 일(一)자로 설치되어 있다.
    //전구들은 전원을 넣었을 때 켜질 확률이 제각각이다.
    // N은 전구의 개수이다
    cin >> N;

    // pi는 i번째 전구에 불이 들어올 확률이며,
    // 정확히 소수점 아래 두 자리까지 주어진다
    for (int i = 0; i < N; i++) {
        cin >> parr[i];

        ans += parr[i];
    }

    // 전구 스트립에 불이 들어오는 전구 개수의 기댓값을 구하여라.
    for (int i = 1; i < N; i++) { //사이의 전구가 켜질 확률
        ans += (parr[i - 1] * (1 - parr[i]) + (1 - parr[i - 1]) * parr[i]);
    }

    // 출력한 값과 정답과의 절대 오차 또는 상대 오차가
    // 10^(-6) 이하여야 한다.
    cout << fixed;
    cout.precision(6);

    // 불이 들어온 전구의 개수의 기대값을 출력한다.
    cout << ans;

    return 0;
}