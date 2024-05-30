#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<pi, int> pii;
typedef pair<pi, pi> pipi;

const int MAX = 1e5 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int cnt[MAX];

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i], cnt[arr[i]]++;
    bool ans = false;
    for (int i = MAX - 1; i > 0; i--) {
        if (cnt[i] & 1) {
            ans = true;
            break;
        }
    }
    if (ans) cout << "koosaga\n";
    else cout << "cubelover\n";
    return 0;
}
