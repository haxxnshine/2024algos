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
bool not_prime[MAX];
vector<int> primes;

void init() {
    not_prime[0] = not_prime[1] = true;
    for (ll i = 2; i < MAX; i++) {
        if (not_prime[i]) continue;
        primes.push_back (i);
        for (ll j = i * i; j < MAX; j += i)
            not_prime[j] = true;
    }
}

void up (int x) {
    for (auto& it : primes) {
        while (x > 1 && x % it == 0)
            cnt[it]++, x /= it;
        if (x == 1) return;
        if (it > sqrt(x)) {
            cnt[x]++;
            return;
        }
    }
}

void down (int x) {
    for (auto& it : primes) {
        while (x > 1 && x % it == 0)
            cnt[it]--, x /= it;
        if (x == 1) return;
        if(it > sqrt(x)) {
            cnt[x]--;
            return;
        }
    }
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    init();
    int N;
    cin >> N;
    int n;
    char op;
    cin >> n;
    bool flag = false;
    up (abs (n));
    if (n == 0) flag = true;
    for (int i = 1; i < N; i++) {
        cin >> op >> n;
        if (n == 0) flag = true;
        if (op == '*') up (abs(n));
        else down (abs(n));
    }
    bool ans = true;
    for (auto& it : primes) {
        if (cnt[it] < 0) ans = false;
    }
    if (ans || flag) cout << "mint chocolate\n";
    else cout << "toothpaste\n";
    return 0;
}
