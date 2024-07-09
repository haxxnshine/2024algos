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
bool dp[50005];

void solve() {
    int n;
    cin >> n;
    memset (dp, false, sizeof (dp));
    dp[0] = true;
    int sum = 0;
    int maxVal = 0;
    for (int i = 0; i < n; i++) {
        int coin, cnt;
        cin >> coin >> cnt;
        sum += coin * cnt;
        for (int k = 0; k < cnt; k++) {
            maxVal += coin;
            for (int j = min(maxVal, 50000); j - coin >= coin * k; j--)
                dp[j] |= dp[j - coin];
        }
    }
    cout << (sum % 2 == 0 && dp[sum / 2]) << "\n";
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int tc = 3;
    while (tc--) solve();
    return 0;
}
