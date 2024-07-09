#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;

// 주난이의 파동은 상하좌우 4방향으로
// 친구들을 쓰러뜨릴(?) 때 까지 계속해서 퍼져나간다.
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
// (1 ≤ N, M ≤ 300)
bool vis[301][301];
char table[301][301];
int N, M;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int x1, y1, x2, y2;

	// 첫째 줄에 주난이가 위치한 교실의 크기 N, M이 주어진다.
	cin >> N >> M;

	// 둘째 줄에 주난이의 위치 x1, y1과 범인의 위치 x2, y2가 주어진다. 
	// (1 ≤ x1, x2 ≤ N, 1 ≤ y1, y2 ≤ M)
	cin >> y1 >> x1 >> y2 >> x2;

	y1--;
	x1--;
	y2--;
	x2--;
	
	// 이후 N×M 크기의 교실 정보가 주어진다.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> table[i][j];
		}
	}

	queue<pair<int, int>> Q[2];
	
	Q[0].push({ x1,y1 });

	int day = 0;
	
	// 주난이가 범인을 잡기 위해 최소 몇 번의 점프를 해야 하는지 출력한다.
	while (true) {
		while (!Q[day % 2].empty()) {
			auto q = Q[day % 2].front();

			Q[day % 2].pop();

			for (int i = 0; i < 4; i++) {
				int nx = dx[i] + q.X;
				int ny = dy[i] + q.Y;
				
				if (nx < 0 || ny < 0 || nx >= M || ny >= N) {
					continue;
				}
				if (vis[ny][nx] == true) {
					continue;
				}

				vis[ny][nx] = true;

				// 0은 빈 공간, 1은 친구, *는 주난, #는 범인을 뜻한다.
				switch (table[ny][nx])
				{
					case '0':
						Q[day % 2].push({ nx,ny });
						break;
					// 다르게 표현해서, 한 번의 점프는 한 겹의 친구들을 쓰러뜨린다.
					case '1':
						Q[(day + 1) % 2].push({ nx,ny });
						table[ny][nx] = '0';
						break;
					case '#':
						cout << day + 1 << "\n";
						return 0;
				}
			}
		}

		// 주난이에게 최소 점프 횟수를 알려줘서 교실을 지키자.
		day++;
	}

	return 0;
}