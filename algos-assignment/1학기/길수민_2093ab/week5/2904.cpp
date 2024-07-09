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
bool not_prime[MAX];
map<int, int> primes;
int sum[80000], cnt[80000][101];

void init () {
    int idx = 0;
    not_prime[0] = not_prime[1] = true;
    for (ll i = 2; i < MAX; i++) {
        if (not_prime[i]) continue;
        primes.insert ({i, idx});
        idx++;
        for (ll j = i * i; j < MAX; j += i)
            not_prime[j] = true;
    }
}

void up (int n, int idx) {
    ll tmp = n;
    for (ll i = 2; i * i <= n; i++) {
        while (tmp % i == 0) {
            tmp /= i;
            cnt[primes[i]][idx]++;
            sum[primes[i]]++;
        }
    }
    if (tmp != 1) cnt[primes[tmp]][idx]++, sum[primes[tmp]]++;
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    init();
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i], up (arr[i], i);
    pair<ll, int> ans = {1, 0};
    for (auto& it : primes) {
        int score = sum[it.Y] / N;
        for (int i = 0; i < score; i++) ans.X *= it.X;
        for (int i = 0; i < N; i++) {
            if (cnt[it.Y][i] < score)
                ans.Y += score - cnt[it.Y][i];
        }
    }
    cout << ans.X << " " << ans.Y << "\n";
    return 0;
}
