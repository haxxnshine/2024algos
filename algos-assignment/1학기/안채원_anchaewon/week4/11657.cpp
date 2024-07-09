#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

const long long INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long dist[501];
    vector<tuple<int, int, int>> bus;
    fill(dist, dist + 501, INF);
    dist[1] = 0;
    
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        bus.push_back(make_tuple(a, b, c));
    }
    
    for (int i = 0; i < n - 1; i++) {
        for (const auto& edge : bus) {
            int from, to, weight;
            tie(from, to, weight) = edge;
            if (dist[from] != INF) {
                dist[to] = min(dist[to], dist[from] + weight);
            }
        }
    }
    
    for (const auto& edge : bus) {
        int from, to, weight;
        tie(from, to, weight) = edge;
        if (dist[from] != INF && dist[to] > dist[from] + weight) {
            cout << "-1";
            return 0;
        }
    }
    
    for (int i = 2; i <= n; i++) {
        if (dist[i] == INF) {
            cout << "-1\n";
        } else {
            cout << dist[i] << '\n';
        }
    }

    return 0;
}
