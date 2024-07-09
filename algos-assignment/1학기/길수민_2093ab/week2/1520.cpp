#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<pi, int> pii;
typedef pair<pi, pi> pipi;

const int MAX = 1e6 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int N, M, arr[505][505], dp[505][505];

int dfs (int x, int y) {
    if (x == 0 && y == 0) return dp[x][y] = 1;
    if (dp[x][y] != -1) return dp[x][y];
    int ret = 0;
    for (int i = 0; i < 4; i++) {
        int px = x + dx[i];
        int py = y + dy[i];
        if (px < 0 || px >= N || py < 0 || py >= M) continue;
        if (arr[x][y] >= arr[px][py]) continue;
        ret += dfs (px, py);
    }
    return dp[x][y] = ret;
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) cin >> arr[i][j];
    }
    memset (dp, -1, sizeof (dp));
    cout << dfs (N - 1, M - 1) << "\n";
    return 0;
}
