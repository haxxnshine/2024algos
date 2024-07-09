// 너비 우선 탐색 (BFS, Breadth-First Search)
// - 그래프를 완전 탐색하는 방법 중 하나
// - 시작 노드에서 출발해 시작 노드를 기준으로
// 가까운 노드를 먼저 방문하면서 탐색하는 알고리즘
// - 기능 : 그래프 완전 탐색
// - 특징 : FIFO 탐색, Queue 자료구조 이용
// - 시간 복잡도 (노드 수 : V, 에지 수 : E) : O(V + E)
// - 너비 우선 탐색은 선입선출 방식으로 탐색하므로 큐를 이용해 구현합니다.
// - 또한 너비 우선 탐색은 탐색 시작 노드와 가까운 노드를 우선하여 탐색하므로
// 목표 노드에 도착하는 경로가 여러 개일 때 최단 경로를 보장합니다.

// 너비 우선 탐색의 핵심 이론
// BFS의 원리를 3단계로 나눠 자세히 알아본다
// 1. BFS를 시작할 노드를 정한 후 사용할 자료구조 초기화
// - BFS도 DFS와 마찬가지로 방문했던 노드는 다시 방문하지 않으므로
// 방문한 노드를 체크하기 위한 배열이 필요합니다.
// - 그래프를 인접 리스트로 표현하는 것 역시 DFS와 동일합니다.
// - 하나 차이점이 있다면 탐색을 위해 스택이 아닌 큐를 사용합니다.
// - BFS를 위한 자료구조 초기화
// 1) 원본 그래프
// 2) 인접 리스트
// 3) 방문 배열
// 4) 큐 자료구조에 시작점을 더하기
// 2. 큐에서 노드를 꺼낸 후 꺼낸 노드의 인접 노드를 다시 큐에 삽입하기
// - 큐에서 노드를 꺼내면서 인접 노드를 큐에 삽입합니다.
// - 이때 방문 배열을 체크하여 이미 방문한 노드는 큐에 삽입하지 않습니다.
// - 또한 큐에서 꺼낸 노드는 탐색 순서에 기록합니다.
// - BFS 실행 과정 1
// 1) 큐에서 노드를 꺼내면서 탐색 순서에 꺼낸 노드를 기록
// 2) 인접 리스트
// 3) 대상 노드의 인접 노드를 큐에 삽입
// 4) 노드를 삽입하며 방문 배열 체크
// 3. 큐 자료구조에 값이 없을 때까지 반복하기
// - 큐에 노드가 없을 때까지 앞선 과정을 반복합니다.
// - 선입선출 방식으로 탐색하므로 탐색 순서가 DFS와 다름을 확인해 보세요.



#include <iostream>
#include <queue>
using namespace std;

// N과 K는 정수이다.
int n, k;
int visited[200000] = { 0 };
queue<pair<int, int>> q;

int bfs() {
	while (!q.empty()) {
		int value = q.front().first;
		int cnt = q.front().second;

		q.pop();

		if (value == k) {
			return cnt;
		}

		int teleport = 2;

		// 수빈이는 걷거나 순간이동을 할 수 있다.
		// 순간이동을 하는 경우에는 0초 후에 2 * X의 위치로 이동하게 된다.
		while (value * teleport < 200000 && visited[value * teleport] == 0) {
			q.push(make_pair(value * teleport, cnt));
			visited[value * teleport] = 1;
			teleport *= 2;
		}

		// 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다.
		if (visited[value - 1] == 0 && value - 1 >= 0) {
			q.push(make_pair(value - 1, cnt + 1));
			visited[value - 1] = 1;
		}

		if (visited[value + 1] == 0 && value < 100000) {
			q.push(make_pair(value + 1, cnt + 1));
			visited[value + 1] = 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	// 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고,
	// 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 
	// 첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다.
	cin >> n >> k;

	q.push(make_pair(n, 0));
	visited[n] = 1;

	// 수빈이와 동생의 위치가 주어졌을 때,
	// 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.
	int res = (n == k) ? 0 : bfs();

	// 수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.
	cout << res;

	return 0;
}