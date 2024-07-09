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

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int N;
    cin >> N;
    vector<ll> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
    vector<ll> diff;
    diff.push_back (0);
    diff.push_back (2 * arr[0]);
    for (int i = 1; i < N; i++)
        diff.push_back (2 * (arr[i] - arr[i - 1]) + diff[i - 1]);
    ll minVal = -1e18, maxVal = 1e18;
    for (int i = 1; i <= N; i++) {
        if (i & 1) {
            maxVal = min (maxVal, diff[i] - diff[i - 1]);
        } else {
            minVal = max (minVal, diff[i - 1] - diff[i]);
        }
    }
    if (minVal & 1) minVal++;
    if (maxVal & 1) maxVal--;
    minVal /= 2;
    maxVal /= 2;
    if (maxVal < minVal) cout << "0\n";
    else cout << maxVal - minVal + 1 << "\n";
    return 0;
}
