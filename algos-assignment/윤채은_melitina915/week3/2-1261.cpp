#include <iostream>
#include <deque>
using namespace std;

int n, m;

// 즉, 현재 운영진이 (x, y)에 있을 때,
// 이동할 수 있는 방은 (x+1, y), (x, y+1), (x-1, y), (x, y-1) 이다.
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

int maze[101][101];	 //미로 정보
int visit[101][101]; //방문 확인 및 벽을 부신 횟수

// 알고스팟 운영진은 여러명이지만, 항상 모두 같은 방에 있어야 한다.
// 즉, 여러 명이 다른 방에 있을 수는 없다.
deque<pair<int, int>> dq;

void bfs() {
	visit[0][0] = 0;

	dq.push_back(make_pair(0, 0));
	
	while (!dq.empty()) {
		int x = dq.front().first;
		int y = dq.front().second;
	
		dq.pop_front();
		
		// 어떤 방에서 이동할 수 있는 방은 상하좌우로 인접한 빈 방이다.
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			// 단, 미로의 밖으로 이동 할 수는 없다.
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (visit[nx][ny] == -1) {
					//만약 벽이 없는 곳이면 벽을 부실 필요 없으므로
					//다음 좌표의 visit값은 현재 좌표의 visit값과 동일
					if (maze[nx][ny] == 0) {
						visit[nx][ny] = visit[x][y];
						dq.push_front(make_pair(nx, ny));
					}
					//만약 벽이 있는 곳이면 벽을 부셔야 하므로
					//다음 좌표의 visit값은 현재 좌표의 visit값 + 1
					// 벽을 부수면, 빈 방과 동일한 방으로 변한다.
					else {
						visit[nx][ny] = visit[x][y] + 1;
						dq.push_back(make_pair(nx, ny));
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	// 미로는 N*M 크기이며, 총 1*1크기의 방으로 이루어져 있다.
	// 미로는 빈 방 또는 벽으로 이루어져 있고,
	// 빈 방은 자유롭게 다닐 수 있지만, 벽은 부수지 않으면 이동할 수 없다.
	// 첫째 줄에 미로의 크기를 나타내는 가로 크기 M, 
	// 세로 크기 N (1 ≤ N, M ≤ 100)이 주어진다.
	cin >> m >> n;
	
	// 다음 N개의 줄에는 미로의 상태를 나타내는 숫자 0과 1이 주어진다.
	// 0은 빈 방을 의미하고, 1은 벽을 의미한다.
	// (1, 1)과 (N, M)은 항상 뚫려있다.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char temp;

			cin >> temp;
			
			maze[i][j] = temp - '0';
			visit[i][j] = -1;
		}
	}

	// 현재 (1, 1)에 있는 알고스팟 운영진이 (N, M)으로 이동하려면
	// 벽을 최소 몇 개 부수어야 하는지 구하는 프로그램을 작성하시오.
	bfs();

	// 첫째 줄에 알고스팟 운영진이 (N, M)으로 이동하기 위해
	// 벽을 최소 몇 개 부수어야 하는지 출력한다.
	cout << visit[n - 1][m - 1] << '\n';
	
	return 0;
}