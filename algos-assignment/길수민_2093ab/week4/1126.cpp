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
ll dp[500005];

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int N, h;
    cin >> N;
    vector<int> dp(500005, -1);
    vector<int> tmp(dp);
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        cin >> h;
        for (int j = 0; j < 500005; j++)
            tmp[j] = dp[j];
        for (int j = 0; j < 500005; j++) {
            if (dp[j] == -1) continue;
            int l = dp[j] - j;
            int r = dp[j];
            l += h;
            int diff = max (l, r) - min (l, r);
            tmp[diff] = max (tmp[diff], max (l, r));
            l -= h;
            r += h;
            diff = max (l, r) - min (l, r);
            tmp[diff] = max (tmp[diff], max (l, r));
        }
        tmp.swap (dp);
    }
    if (!dp[0]) cout << "-1\n";
    else cout << dp[0] << "\n";
    return 0;
}
