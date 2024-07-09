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
int parent[1001];
bool select_edge[10001];

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

    int N, M, K;
    cin >> N >> M >> K;
    vector<pii> edges;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back ({i + 1, {u, v}});
    }
    while (K--) {
        memset (parent, -1, sizeof (parent));
        bool selected = false;
        int cnt = 0, cost = 0;
        for (int i = 0; i < M; i++) {
            if (select_edge[i]) continue;
            if (unionParent (edges[i].Y.X, edges[i].Y.Y)) {
                if (!selected) selected = select_edge[i] = true;
                cnt++;
                cost += edges[i].X;
            }
        }
        if (cnt != N - 1) cout << "0 ";
        else cout << cost << " ";
    }
    cout << "\n";
    return 0;
}
