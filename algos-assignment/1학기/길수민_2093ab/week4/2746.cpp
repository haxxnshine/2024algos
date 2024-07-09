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
    ll sum = 0, ans = 0;
    for (int i = 0; i < N; i++) cin >> arr[i], sum += arr[i];
    sort (arr.begin(), arr.end());
    // case 1 : 3rd number
    sum -= arr[N - 1] + arr[N - 2];
    if (sum == 2 * arr[N - 3]) ans++;
    sum += arr[N - 1] + arr[N - 2];
    // case 2 : 2nd number
    sum -= arr[N - 1];
    ll target = sum - 2 * arr[N - 2];
    auto it1 = lower_bound(arr.begin(), arr.end() - 2, target);
    auto it2 = upper_bound(arr.begin(), arr.end() - 2, target);
    ans += distance (it1, it2);
    sum += arr[N - 1];
    // case 3 : 1st number
    ll tmp = 0;
    for (int i = 0; i < N - 1; i++) {
        target = sum - 2 * arr[N - 1] - arr[i];
        it1 = lower_bound(arr.begin(), arr.end() - 1, target);
        it2 = upper_bound(arr.begin(), arr.end() - 1, target);
        tmp += distance (it1, it2);
        if (it1 <= arr.begin() + i && arr.begin() + i < it2) tmp--;
    }
    ans += tmp / 2;
    cout << ans << "\n";
    return 0;
}
