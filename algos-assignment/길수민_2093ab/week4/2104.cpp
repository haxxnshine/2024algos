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

class SegTree {
public:
    ll arr[MAX], prefix_sum[MAX], tree[MAX << 4], N;

    SegTree() {
        cin >> N;
        for (int i = 1; i <= N; i++)
            cin >> arr[i], prefix_sum[i] = prefix_sum[i - 1] + arr[i];
        init (1, 1, N);
        arr[0] = 1000001;
    }

    void init (int node, int l, int r) {
        if (l == r) {
            tree[node] = l;
            return;
        }
        int mid = (l + r) >> 1;
        init (node * 2, l, mid);
        init (node * 2 + 1, mid + 1, r);
        if (arr[tree[node * 2]] <= arr[tree[node * 2 + 1]])
            tree[node] = tree[node * 2];
        else tree[node] = tree[node * 2 + 1];
    }

    int query (int node, int l, int r, int s, int e) {
        if (l > e || r < s) return 0;
        if (s <= l && r <= e) return tree[node];
        int mid = (l + r) >> 1;
        int l_ret = query (node * 2, l, mid, s, e);
        int r_ret = query (node * 2 + 1, mid + 1, r, s, e);
        if (arr[l_ret] <= arr[r_ret]) return l_ret;
        return r_ret;
    }

    ll getSum (int l, int r) {
        return prefix_sum[r] - prefix_sum[l - 1];
    }

    ll query (int l, int r) {
        if (l > r) return 0;
        if (l == r) return arr[l] * arr[l];
        int idx = query (1, 1, N, l, r);
        ll ans = getSum (l, r) * arr[idx];
        ans = max (ans, query (l, idx - 1));
        ans = max (ans, query (idx + 1, r));
        return ans;
    }
};

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    SegTree *tree;
    tree = new SegTree();
    cout << tree->query (1, tree->N) << "\n";
    delete tree;
    return 0;
}
