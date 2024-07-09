#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<pi, int> pii;
typedef pair<pi, pi> pipi;

const int MAX = 1e7 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
bool not_prime[MAX];
vector<ll> primes;

void init () {
    not_prime[0] = not_prime[1] = true;
    for (ll i = 2; i < MAX; i++) {
        if (not_prime[i]) continue;
        primes.push_back (i);
        for (ll j = i * i; j < MAX; j += i)
            not_prime[j] = true;
    }
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    init();
    ll A, B;
    cin >> A >> B;
    ll ans = 0;
    for (auto& it : primes) {
        for (ll i = it * it; i <= B; i *= it) {
            if (i >= A) ans++;
            if (i > B / it) break;
        }
    }
    cout << ans << "\n";
    return 0;
}
