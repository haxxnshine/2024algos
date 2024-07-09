#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<pair<int, int>, int>> v;
int dist[501];

void bellmanFord(int n) {
    for (int i = 0; i < n; i++) {
        for (int pos = 0; pos < v.size(); pos++) {
            int from = v[pos].first.first;
            int to = v[pos].first.second;
            int cost = v[pos].second;

            if (dist[from] + cost < dist[to]) {
                dist[to] = dist[from] + cost;
            }
        }
    }

    // TC개의 줄에 걸쳐서 만약에 시간이 줄어들면서
    // 출발 위치로 돌아오는 것이 가능하면 YES, 불가능하면 NO를 출력한다.
    for (int pos = 0; pos < v.size(); pos++) {
        int from = v[pos].first.first;
        int to = v[pos].first.second;
        int cost = v[pos].second;

        if (dist[from] + cost < dist[to]) {
            cout << "YES\n";

            return;
        }
    }

    cout << "NO\n";
}


int main() {

    // 첫 번째 줄에는 테스트케이스의 개수 TC(1 ≤ TC ≤ 5)가 주어진다. 
    int tc;

    cin >> tc;

    while (tc--) {
        v.clear();

        // 그리고 두 번째 줄부터 TC개의 테스트케이스가 차례로 주어지는데
        // 각 테스트케이스의 첫 번째 줄에는 지점의 수 N(1 ≤ N ≤ 500),
        // 도로의 개수 M(1 ≤ M ≤ 2500),
        // 웜홀의 개수 W(1 ≤ W ≤ 200)이 주어진다.
        // 월드나라에는 N개의 지점이 있고
        // N개의 지점 사이에는 M개의 도로와 W개의 웜홀이 있다.
        // (단 도로는 방향이 없으며 웜홀은 방향이 있다.) 
        int n, m, w;
        
        cin >> n >> m >> w;

        for (int i = 1; i <= n; i++) {
            dist[i] = 987654321;
        }

        // 그리고 두 번째 줄부터 M+1번째 줄에 도로의 정보가 주어지는데
        // 각 도로의 정보는 S, E, T 세 정수로 주어진다.
        for (int i = 0; i < m; i++) {
            // S와 E는 연결된 지점의 번호,
            // T는 이 도로를 통해 이동하는데 걸리는 시간을 의미한다.
            // 두 지점을 연결하는 도로가 한 개보다 많을 수도 있다.
            // 지점의 번호는 1부터 N까지 자연수로 중복 없이 매겨져 있다.
            int from, to, cost;
            
            cin >> from >> to >> cost;

            v.push_back({ {from,to},cost });
            v.push_back({ {to,from},cost });
        }

        // 그리고 M+2번째 줄부터 M+W+1번째 줄까지
        // 웜홀의 정보가 S, E, T 세 정수로 주어지는데
        // S는 시작 지점, E는 도착 지점, T는 줄어드는 시간을 의미한다.
        for (int i = 0; i < w; i++) {
            // T는 10,000보다 작거나 같은 자연수 또는 0이다.
            int from, to, cost;
            
            cin >> from >> to >> cost;

            // 웜홀은 시작 위치에서 도착 위치로 가는 하나의 경로인데,
            // 특이하게도 도착을 하게 되면
            // 시작을 하였을 때보다 시간이 뒤로 가게 된다.
            // 웜홀 내에서는 시계가 거꾸로 간다고 생각하여도 좋다.
            v.push_back({ {from,to}, -cost });
        }

        // 한 지점에서 출발을 하여서 시간여행을 하기 시작하여
        // 다시 출발을 하였던 위치로 돌아왔을 때,
        // 출발을 하였을 때보다 시간이 되돌아가 있는 경우가
        // 있는지 없는지 궁금해졌다.
        bellmanFord(n);
    }

    return 0;
}