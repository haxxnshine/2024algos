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

void track (int x, vector<int>& path, vector<int>& ans, vector<int>& arr1) {
    ans.push_back (arr1[x]);

    if (path[x] == -1) return;
    track (path[x], path, ans, arr1);
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int N;
    cin >> N;
    vector<int> arr1(N), arr2(N);
    for (int i = 0; i < N; i++) cin >> arr1[i];
    for (int i = 0; i < N; i++) cin >> arr2[i];
    vector<int> lis(N), dp(N, 1), path(N, -1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr1[i] == arr2[j]) {
                lis[i] = j;
                break;
            }
        }
    }
    int ans = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (lis[i] > lis[j] && dp[i] <= dp[j]) {
                dp[i] = dp[j] + 1;
                path[i] = j;
            }
        }
        ans = max (ans, dp[i]);
    }
    vector<int> arr;
    for (int i = N - 1; i >= 0; i--) {
        if (dp[i] == ans) {
            track (i, path, arr, arr1);
            break;
        }
    }
    sort (arr.begin(), arr.end());
    cout << ans << "\n";
    for (auto& it : arr) cout << it << " ";
    cout << "\n";
    return 0;
}

