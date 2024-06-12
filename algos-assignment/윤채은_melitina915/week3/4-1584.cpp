#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <deque>
using namespace std;

// 세준이는 위, 아래, 오른쪽, 왼쪽으로만 이동할 수 있다. 
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

// 주어지는 구역은 모두 겹칠 수 있으며,
// 서로 다른 구역이 겹칠 때는, 더 심한 구역이 해당된다. 
// 예를 들어, 죽음+위험 = 죽음,
// 위험+안전 = 위험, 위험+위험 = 위험,
// 죽음+안전 = 죽음이다.
void zoneSetting(vector<vector<int>>& zone, int y1, int y2, int x1, int x2, int type) {
    for (int i = min(y1, y2); i <= max(y1, y2); i++) {
        for (int j = min(x1, x2); j <= max(x1, x2); j++) {
            zone[i][j] = type;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // 세준이는 위험한 지역에서 탈출하는 게임을 하고 있다.
    // 이 게임에는 세준이가 들어갈 수 없는 죽음의 구역이 있고, 
    // 들어가서 한 번 움직일 때 마다 생명이 1씩 소모되는 위험한 구역이 있다.
    // 그리고, 자유롭게 생명의 위협없이 움직일 수 있는 안전한 구역이 있다.
    // (안전한 구역은 죽음의 구역과 위험한 구역을 제외한 나머지 이다.)
    vector<vector<int>> zone(501, vector<int>(501, 0));
    vector<vector<bool>> visited(501, vector<bool>(501, false));

    int N;

    // 첫째 줄에 위험한 구역의 수 N이 주어진다. 
    cin >> N;

    // 다음 줄부터 N개의 줄에는 X1 Y1 X2 Y2와 같은 형식으로
    // 위험한 구역의 정보가 주어진다. 
    for (int i = 0; i < N; i++) {
        // (X1, Y1)은 위험한 구역의 한 모서리이고,
        // (X2, Y2)는 위험한 구역의 반대 모서리이다.
        int x1, y1, x2, y2;

        cin >> x2 >> y1 >> x1 >> y2;

        zoneSetting(zone, y1, y2, x1, x2, 1);
    }

    int M;

    // 그 다음 줄에는 죽음의 구역의 수 M이 주어진다.
    cin >> M;

    // 다음 줄부터 M개의 줄에는 죽음의 구역의 정보가
    // 위험한 구역의 정보와 같이 주어진다. 
    for (int i = 0; i < M; i++) {
        int x1, y1, x2, y2;

        cin >> x2 >> y1 >> x1 >> y2;

        zoneSetting(zone, y1, y2, x1, x2, 2);
    }

    deque<pair<pair<int, int>, int>> d;

    d.push_back({ { 0, 0 } , 0 });
    visited[0][0] = true;

    int goalLife = 0;
    bool goal = false;

    while (!d.empty()) {
        int bx = d.front().first.first;
        int by = d.front().first.second;
        int life = d.front().second;

        // 세준이는 (0, 0)에서 출발해서 (500, 500)으로 가야 한다.
        if (bx == 500 && by == 500) {
            goal = true;
            goalLife = life;

            break;
        }

        d.pop_front();

        for (int i = 0; i < 4; i++) {
            int nx = bx + dx[i];
            int ny = by + dy[i];

            // 현재 세준이는 (0, 0)에 있다. 그리고, 게임 판을 벗어날 수는 없다.
            if (0 <= nx && nx <= 500 && 0 <= ny && ny <= 500 && !visited[nx][ny]) {
                visited[nx][ny] = true;

                // 예를 들어, (500, 500)이 위험한 구역일 때는,
                // (500, 500)에 들어갈 때, 생명이 1 감소되지만,
                // (0, 0)이 위험한 구역이더라도 생명은 감소되지 않는다.
                if (zone[nx][ny] == 0) {
                    d.push_front({ { nx, ny }, life });
                }
                // 생명의 감소는 구역에 들어갈 때만, 영향을 미친다.
                else if (zone[nx][ny] == 1) {
                    d.push_back({ { nx, ny }, life + 1 });
                }
            }

        }
    }

    // 세준이가 (0, 0)에서 (500, 500)으로 갈 때 잃는
    // 생명의 최솟값을 구하는 프로그램을 작성하시오.
    // 첫째 줄에 정답을 출력한다.
    if (goal) {
        cout << goalLife << '\n';
    }
    // 만약 (500, 500)으로 갈 수 없을 때는 -1을 출력한다.
    else {
        cout << -1 << '\n';
    }

    return 0;
}