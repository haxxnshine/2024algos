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
int visited[2222222];

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int N;
    cin >> N;
    vector<pi> points;
    int top = 0;
    for (int i = 0; i < N; i++) {
        int x, r;
        cin >> x >> r;
        points.push_back ({x - r, i + 1});
        points.push_back ({x + r, -(1 + i)});
        if (visited[x - r + 1010101] || visited[x + r + 1010101]) top = -1;
        visited[x - r + 1010101] = visited[x + r + 1010101] = true;
    }
    if (top != 0) {
        cout << "NO\n";
        return 0;
    }
    sort (points.begin(), points.end());
    stack<int> s;
    for (auto& it : points) {
        if (it.Y < 0) {
            top--;
            if (top < 0 || s.top() != it.Y) break;
            s.pop();
        }
        else {
            top++;
            s.push (-it.Y);
        }
    }
    if (top != 0) cout << "NO\n";
    else cout << "YES\n";

    return 0;
}
