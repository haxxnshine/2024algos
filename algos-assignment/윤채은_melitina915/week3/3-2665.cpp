#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;
int map[52][52]; // 빈 방, 막힌 방
int visit[52][52]; // 뚫고 온 개수 저장
int dx[] = { 0, 0, -1, 1 }; // 상하좌우
int dy[] = { 1, -1, 0, 0 }; // 상하좌우

void bfs() {
    queue<pair<int, int>> q;

    q.push(make_pair(0, 0));

    // 시작 점은 0으로 세팅
    visit[0][0] = 0; 

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            // 다음 x 좌표
            int nx = x + dx[i];
            // 다음 y 좌표
            int ny = y + dy[i]; 

            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                // 갈 수 있는 방
                if (map[ny][nx] == 1) { 
                    //뚫고 온 방의 개수 비교
                    if (visit[ny][nx] > visit[y][x]) {
                        visit[ny][nx] = visit[y][x];

                        // 다음 방으로 이동
                        q.push(make_pair(nx, ny)); 
                    }
                }
                // 비어 있는 방
                else { 
                    //뚫고 온 방의 개수 비교
                    if (visit[ny][nx] > visit[y][x] + 1) {
                        visit[ny][nx] = visit[y][x] + 1;

                        // 다음 방으로 이동
                        q.push(make_pair(nx, ny)); 
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // n×n 바둑판 모양으로 총 n^2개의 방이 있다.
    // 일부분은 검은 방이고 나머지는 모두 흰 방이다.
    // 검은 방은 사면이 벽으로 싸여 있어 들어갈 수 없다.
    // 서로 붙어 있는 두 개의 흰 방 사이에는 문이 있어서 지나다닐 수 있다.
    // 윗줄 맨 왼쪽 방은 시작방으로서 항상 흰 방이고,
    // 아랫줄 맨 오른쪽 방은 끝방으로서 역시 흰 방이다.
    // 첫 줄에는 한 줄에 들어가는 방의 수 n(1 ≤ n ≤ 50)이 주어지고,
    cin >> n;
    
    char a;

    // 다음 n개의 줄의 각 줄마다 0과 1이 이루어진 길이가 n인 수열이 주어진다.
    // 0은 검은 방, 1은 흰 방을 나타낸다.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a;

            map[i][j] = a - '0'; // 입력을 int로 바꾸어줌
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visit[i][j] = 987654321; // 최대 값
        }
    }

    // 시작방에서 출발하여 길을 찾아서 끝방으로 가는 것이 목적인데,
    // 아래 그림의 경우에는 시작방에서 끝 방으로 갈 수가 없다.
    // 부득이 검은 방 몇 개를 흰 방으로 바꾸어야 하는데
    // 되도록 적은 수의 방의 색을 바꾸고 싶다.
    // 검은 방에서 흰 방으로 바꾸어야 할 최소의 수를 구하는 프로그램을 작성하시오.
    // 단, 검은 방을 하나도 흰방으로 바꾸지 않아도 되는 경우는 0이 답이다.
    bfs();

    // 첫 줄에 흰 방으로 바꾸어야 할 최소의 검은 방의 수를 출력한다.
    cout << visit[n - 1][n - 1] << endl;

    return 0;
}