#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<pi, pi> pipi;

const int MAX = 1e6 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool avail (pii a, pii b) {
    if (a.Y.X == b.Y.X) return false;
    if (a.Y.X == b.Y.Y) return false;
    if (a.Y.Y == b.Y.X) return false;
    if (a.Y.Y == b.Y.Y) return false;
    return true;
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int N;
    cin >> N;
    vector<int> h(N);
    vector<pii> snowman;
    for (int i = 0; i < N; i++) cin >> h[i];
    sort (h.begin(), h.end());

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            snowman.push_back ({h[i] + h[j], {j, i}});
        }
    }
    sort (snowman.begin(), snowman.end());
    int ptr1 = 0, ptr2 = 1;
    ll ans = snowman[snowman.size() - 1].X - snowman[0].X;
    for (ptr1 = 0; ptr1 < snowman.size(); ptr1++) {
        ptr2 = ptr1;
        while (ptr2 < snowman.size() && \
                !avail (snowman[ptr1], snowman[ptr2])) ptr2++;
        if (ptr2 < snowman.size()) {
            ans = min (ans, (ll)snowman[ptr2].X - snowman[ptr1].X);
        }
    }
    cout << ans << "\n";
    return 0;
}
