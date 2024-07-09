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
string str;

int solve (int l, int r) {
    if (l > r) return 0;
    if (l == r && str[r] == ')') return 0;
    if (l == r) return 1;
    stack<int> s;
    vector<pi> path;
    for (int i = l; i <= r; i++) {
        if (str[i] == '(') s.push (i), path.push_back ({i - 1, -1});
        if (str[i] == ')') {
            s.pop();
            if (s.empty()) path.back().Y = i;
            else path.pop_back();
        }
    }
    if (path.size() == 1 && path[0].X == l && path[0].Y == r)
        return (str[l] - '0') * solve (l + 2, r - 1);
    int ret = 0;
    int i = l, idx = 0;
    while (i <= r) {
        if (idx < path.size() && path[idx].X == i) {
            ret += solve (i, path[idx].Y);
            i = path[idx].Y + 1;
            idx++;
        } else ret++, i++;
    }
    return ret;
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    cin >> str;
    cout << solve (0, str.length() - 1) << "\n";
    return 0;
}
