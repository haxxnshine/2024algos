#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// (1 ≤ N, Q ≤ 100,000)
int n, q;
// 입력되는 모든 수는 -2^31보다 크거나 같고, 2^31-1보다 작거나 같은 정수이다.
vector<long long> num, tree;

long long init(int node, int start, int end) {
    if (start == end) {
        return tree[node] = num[end];
    }

    int mid = (start + end) / 2;

    return tree[node] = init(2 * node, start, mid) + init(2 * node + 1, mid + 1, end);
}

void update(int node, int start, int end, int idx, long long diff) {
    if (idx < start || idx > end) {
        return;
    }

    tree[node] += diff;

    if (start != end) {
        int mid = (start + end) / 2;

        update(2 * node, start, mid, idx, diff);
        update(2 * node + 1, mid + 1, end, idx, diff);
    }
}

long long sum(int node, int start, int end, int left, int right) {
    if (start > right || end < left) {
        return 0;
    }

    if (left <= start && end <= right) {
        return tree[node];
    }

    int mid = (start + end) / 2;

    return sum(2 * node, start, mid, left, right) + sum(2 * node + 1, mid + 1, end, left, right);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // 첫째 줄에 수의 개수 N과 턴의 개수 Q가 주어진다.
    cin >> n >> q;

    num.resize(n + 1);
    tree.resize(4 * (n + 1));

    // 둘째 줄에는 처음 배열에 들어가 있는 정수 N개가 주어진다.
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }

    init(1, 1, n);

    for (int i = 0; i < q; i++) {
        int x, y, a;
        long long b;

        // 세 번째 줄에서 Q+2번째 줄까지는 x y a b의 형식으로 x~y까지의 합을 구하여라,
        cin >> x >> y >> a >> b;

        // x~y는 당연히 x번째 부터 y번째가 맞다. 하지만, 이 문제에서는 x > y인 경우 y번째 부터 x번째이다.
        if (x > y) {
            swap(x, y);
        }

        // 한 턴마다 구한 합을 한 줄마다 한 개씩 출력한다.
        cout << sum(1, 1, n, x, y) << '\n';

        update(1, 1, n, a, b - num[a]);

        // a번째 수를 b로 바꾸어라 라는 뜻의 데이터가 주어진다.
        num[a] = b;
    }

    return 0;
}
