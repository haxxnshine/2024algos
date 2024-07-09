#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
const int MAX_V = 101;
int n, m, a, b, c, cycle = 0;
vector<pair<int, int>> adj[MAX_V];
vector<int> rev[MAX_V];
int dist[MAX_V], pre[MAX_V], vis[MAX_V];

void bellman_ford(int st) {
    fill(dist, dist + MAX_V, INT_MAX);
    fill(pre, pre + MAX_V, 0);

    dist[st] = 0;

    for (int iter = 1; iter <= n; iter++) {
        //모든 간선 확인작업을 n번 반복
        for (int cur = 1; cur <= n; cur++) {
            if (dist[cur] == INT_MAX) {
                //아직 이어지지 않은 정점은 패스
                continue;
            }

            for (auto& u : adj[cur]) {
                int next = u.first, cost = u.second;

                // 최적의 경로가 여러 개 존재할 때는 아무거나 출력해도 된다.
                if (dist[next] > dist[cur] + cost) {
                    dist[next] = dist[cur] + cost;
                    //경로저장
                    pre[next] = cur;

                    if (iter == n && vis[next]) {
                        //사이클이 있고 n번 노드까지 가는 길이 있으면 -1출력
                        cycle = 1;
                    }
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 첫째 줄에 골목길들이 교차하는 지점의 개수 n (2 ≤ n ≤ 100)과
    // 골목길의 개수 m (1 ≤ m ≤ 20,000) 이 차례로 주어진다. 
    cin >> n >> m;

    // 이어지는 m개의 행에
    // 각각의 골목길을 나타내는 세 정수 u, v, w가 차례로 주어진다. 
    for (int i = 0; i < m; i++) {
        // w (0 ≤ |w| ≤ 1,000)는
        // 이 길을 지날 때 갈취당하거나 획득하게 되는 금품의 양이다. 
        // 음수는 갈취, 양수는 획득을 뜻한다.
        cin >> a >> b >> c;

        // 이는 u번 교차점에서 v번 교차점으로 이동할 수 있는
        // 골목길이 나있다는 의미이다. 
        // 즉, 주어지는 골목길들은 기본적으로 모두 일방통행로이다.
        adj[a].push_back({ b, -c });
        //경로를 거꾸로 저장
        rev[b].push_back(a); 
    }

    //n에서 부터 출발해서 경로를 거스르며 vis체크
    // -> i번 노드에서 n번노드까지 갈 수 있다면 vis[i]=1
    queue<int> q;
    // 골목길의 교차점 번호는 1이상 n이하의 정수이다. 
    q.push(n);
    // 민승이네 집은 1번 교차점에 있고,
    // 이곳 코레스코 콘도는 n번 교차점에 있다.
    vis[n] = 1;

    while (!q.empty()) {
        int cur = q.front();

        q.pop();

        for (int i = 0; i < rev[cur].size(); i++) {
            int next = rev[cur][i];

            if (!vis[next]) {
                vis[next] = 1;
                q.push(next);
            }
        }
    }

    // 골목길의 연결 상태와, 각 골목길을 지날 때
    // 갈취당하거나 획득하게 되는 금품의 양이 주어졌을 때,
    // 민승이가 최대한 유리한 경로를 따라 집에서 코레스코 콘도까지 가기 위해서는
    // 어떻게 해야 하는지 출력하는 프로그램을 작성하시오.
    // 보유 중인 금품의 양이 음수가 될 수 있다.
    // 최대한 유리한 경로 또는 최적의 경로는
    // 민승이네 집에서 출발하여 코레스코 콘도에 도착하는 경로 중
    // 금품의 양이 최대가 되는 경로이다.
    bellman_ford(1);

    // 그런데, 경우에 따라서는
    // 최적의 경로라는 것이 존재하지 않는 상황이 발생한다. 
    // 그러한 경우에는 -1을 출력하도록 한다.
    if (cycle) {
        cout << -1;
}
    // 최적의 경로를 구할 수 있다면
    // 민승이네 집부터 코레스코 콘도까지 가는 동안
    // 거치게 되는 교차점들의 번호를 공백 하나를 사이에 두고
    // 차례로 출력하면 된다.
    else {
        vector<int> ans;
        int idx = n;
        
        while (idx >= 1) {
            ans.push_back(idx);
            idx = pre[idx];
        }
        
        reverse(ans.begin(), ans.end());
        
        for (auto& k : ans) {
            cout << k << " ";
        }
    }

    return 0;
}