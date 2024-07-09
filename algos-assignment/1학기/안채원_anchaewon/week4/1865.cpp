#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dist[501];
vector<pair<pair<int, int>, int>> edges;

void bellmanFord(int numNodes) {
    for (int i = 1; i <= numNodes; i++) dist[i] = INT_MAX;
    dist[1] = 0;

    for (int i = 1; i < numNodes; i++) {
        for (const auto& edge : edges) {
            int from = edge.first.first;
            int to = edge.first.second;
            int weight = edge.second;

            if (dist[from] != INT_MAX && dist[from] + weight < dist[to]) {
                dist[to] = dist[from] + weight;
            }
        }
    }

    for (const auto& edge : edges) {
        int from = edge.first.first;
        int to = edge.first.second;
        int weight = edge.second;
        
        if (dist[from] != INT_MAX && dist[from] + weight < dist[to]) {
            cout << "YES" <<"\n";
            return;
        }
    }

    cout << "NO" << "\n";
}

int main() {
    int test;
    cin >> test;

    while (test--) {
        edges.clear();
        int numNodes, numEdges, numWormholes;
        cin >> numNodes >> numEdges >> numWormholes;

        for (int i = 0; i < numEdges; i++) {
            int from, to, cost;
            cin >> from >> to >> cost;
            edges.push_back({ {from, to}, cost });
            edges.push_back({ {to, from}, cost });
        }

        for (int i = 0; i < numWormholes; i++) {
            int from, to, cost;
            cin >> from >> to >> cost;
            edges.push_back({ {from, to}, -cost });
        }

        bellmanFord(numNodes);
    }

    return 0;
}
