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
int parent[100001], N, M;

int find (int node) {
    if (parent[node] == -1) return node;
    return parent[node] = find (parent[node]);
}

bool unionParent (int node1, int node2) {
    node1 = find (node1);
    node2 = find (node2);
    if (node1 == node2) return false;
    if (node1 > node2) parent[node1] = node2;
    else parent[node2] = node1;
    return true;
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    memset (parent, -1, sizeof (parent));
    cin >> N >> M;
    int ans = N - 1, cnt = 0;
    while (M--) {
        int u, v;
        cin >> u >> v;
        if (unionParent (u, v)) ans--;
        else cnt++;
    }
    ans += cnt;
    cout << ans << "\n";
    return 0;
}
