#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int dist[1010];
int route[1010];

vector<int> ans;
//무한값
const int inf = 987654321;

int main() {
	// 버스 비용은 0보다 크거나 같고, 100,000보다 작은 정수이다.
	int n, m, a, b, c, st, ed;

	// 첫째 줄에 도시의 개수 n(1≤n≤1,000)이 주어지고
	// 둘째 줄에는 버스의 개수 m(1≤m≤100,000)이 주어진다.
	cin >> n >> m;

	for (int i = 0; i < n + 2; i++) {
		dist[i] = inf;
	}

	vector<pair<int, int>> path[1000];

	// 그리고 셋째 줄부터 m+2줄까지 다음과 같은 버스의 정보가 주어진다. 
	for (int i = 0; i < m; i++) {
		// 먼저 처음에는 그 버스의 출발 도시의 번호가 주어진다.
		// 그리고 그 다음에는 도착지의 도시 번호가 주어지고
		// 또 그 버스 비용이 주어진다.
		cin >> a >> b >> c;

		path[a].push_back({ b,c });
	}

	// 그리고 m+3째 줄에는 우리가 구하고자 하는 구간 출발점의
	// 도시번호와 도착점의 도시번호가 주어진다.
	cin >> st >> ed;

	priority_queue<pair<int, int>> pq;//비용, 도착지

	pq.push({ 0,st });//st >st 비용은 0

	dist[st] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int now = pq.top().second;

		pq.pop();

		if (now == ed) {
			break;
		}

		//만약 새로 찾은 경로가 기존경로보다 값이 높다면 스킵.
		//if (dist[now] <= cost)continue;
		//최단거리 갱신.
		//dist[now] = cost;

		for (auto e : path[now]) {
			int nxt = e.first;
			int nxt_cost = e.second;

			if (dist[nxt] > dist[now] + nxt_cost) {//해당위치 위치로 최단경로 갱신 가능할 시, pq에 넣어 탐색한다. 
				dist[nxt] = dist[now] + nxt_cost;

				route[nxt] = now;//nxt로 가는 최단경로는 직전에 now를 거친다. ***
				
				pq.push({ -dist[nxt],nxt });
			}
		}

	}

	// 첫째 줄에 출발 도시에서 도착 도시까지 가는데 드는 최소 비용을 출력한다.
	cout << dist[ed] << endl;

	int idx = ed;//***

	while (idx != st) {//***
		ans.push_back(idx);//***

		idx = route[idx];//***
	}

	ans.push_back(idx);//출발경로도 추가.

	// 둘째 줄에는 그러한 최소 비용을 갖는 경로에 포함되어있는
	// 도시의 개수를 출력한다.
	// 출발 도시와 도착 도시도 포함한다.
	cout << ans.size() << endl;

	// 셋째 줄에는 최소 비용을 갖는 경로를 방문하는 도시 순서대로 출력한다.
	for (int i = ans.size() - 1; i >= 0; i--) {//도착지>출발지 경로를 저장했으므로 
		cout << ans[i] << " ";         //거꾸로 출력해 출발> 도착지의 경로를 출력한다.
	}

	cout << endl;
}