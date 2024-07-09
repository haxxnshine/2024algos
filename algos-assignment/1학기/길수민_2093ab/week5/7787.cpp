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
int dp[55], visited[55];

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int r, g;
    cin >> r >> g;
    int grundy_r, grundy_g;
    grundy_r = grundy_g = 0;
    while (r > 0) {
        grundy_r++;
        if (r & 1) break;
        r /= 2;
    }
    while (g > 0) {
        grundy_g++;
        if (g & 1) break;
        g /= 2;
    }
    if (grundy_r ^ grundy_g) cout << "A player wins\n";
    else cout << "B player wins\n";
    return 0;
}
