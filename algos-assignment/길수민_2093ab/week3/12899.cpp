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

class SegTree {
public:
    int tree[2000002 << 2];
    
    void update (int node, int l, int r, int idx, int diff) {
        if (idx < l || idx > r) return;
        tree[node] += diff;
        if (l == r) return;
        int mid = (l + r) >> 1;
        if (idx <= mid) update (node * 2, l, mid, idx, diff);
        else update (node * 2 + 1, mid + 1, r, idx, diff);
    }
    
    int query (int node, int l, int r, int k) {
        if (l == r) return l;
        int mid = (l + r) >> 1;
        if (tree[node * 2] >= k)
            return query (node * 2, l, mid, k);
        return query (node * 2 + 1, mid + 1, r, k - tree[node * 2]);
    }
};

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    SegTree *tree;
    tree = new SegTree();
    int N;
    cin >> N;
    while (N--) {
        int q, x;
        cin >> q >> x;
        if (q == 1) {
            tree->update (1, 1, 2000000, x, 1);
        } else {
            x = tree-> query (1, 1, 2000000, x);
            cout << x << "\n";
            tree->update (1, 1, 2000000, x, -1);
        }
    }
    delete tree;
    return 0;
}
