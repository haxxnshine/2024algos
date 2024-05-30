#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<pi, int> pii;
typedef pair<pi, pi> pipi;

const int MAX = 90009;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int dp[303][303];

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int N, M, K;
    cin >> N >> M >> K;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
    int ans = 0;
    for (int i = 0; i < M; i++) {
        for (int k = 0; k < K; k++) {
            for (int j = 0; j < N; j++) {
                if (dp[i][k] == 0 && k) continue;
                dp[i + 1][(k + arr[j]) % K] = \
                    max (dp[i + 1][(k + arr[j]) % K], dp[i][k] + arr[j]);
            }
        }
    }
    for (int i = 1; i <= M; i++) ans = max (ans, dp[i][0]);
    cout << ans << "\n";
    return 0;
}
