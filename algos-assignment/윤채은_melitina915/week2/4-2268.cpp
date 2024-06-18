// 세그먼트 트리

// 종류
// 1. 구간 합
// 2. 최대 구하기
// 3. 최소 구하기

// 구현 단계
// 1. 트리 초기화하기
// 2. 질의값 구하기 (구간 합 또는 최대, 최소)
// 3. 데이터 업데이트하기

// 1. 트리 초기화하기
// 트리 배열의 크기를 구하는 방법
// 2^k >= N을 만족하는 k의 최소값 구하기
// 트리 배열의 크기 : 2^k * 2 = 2^(k + 1)
// 리프 노드의 시작 위치 : 2^k
// 인덱스 N의 자식 노드 : 2N, 2N + 1

// 2. 질의값 구하기
// - 세그먼트 트리 index = 주어진 질의 index + 2^k - 1
// - 질의값 구하는 과정
// 1) start_index % 2 == 1일 때 해당 노드를 선택한다.
// 2) end_index % 2 == 0일 때 해당 노드를 선택한다.
// * 해당 노드를 선택했다는 것은
// 해당 노드의 부모가 나타내는 범위가
// 질의 범위를 넘어가기 때문에
// 해당 노드를 질의값에 영향을 미치는 독립 노드로 선택하고,
// 해당 노드의 부모 노드는 대상 범위에서 제외한다는 뜻이다.
// 3) start_index depth 변경 : start_index = (start_index + 1) / 2 연산 실행
// 4) end_index depth 변경 : end_index = (end_index - 1) / 2 연산은 실행한다.
// * 부모 노드를 대상 범위에서 제거하는 방법은
// 질의 범위에 해당하는 부모 노드로 이동하기 위해 인덱스 연산을
// index / 2가 아닌 (index + 1) / 2, (index - 1) / 2로 수행하는 것이다.
// 5) 1 ~ 4를 반복하다가 end_index < start_index가 되면 종료한다.
// - 질의에 해당하는 노드 선택 방법
// 1) 구간 합 : 선택된 노드를 모두 더한다.
// 2) 최대값 구하기 : 선택된 노드 중 MAX 값을 선택해 출력한다.
// 3) 최소값 구하기 : 선택된 노드 중 MIN 값을 선택해 출력한다.

// 3. 데이터 업데이트하기
// - 구간 합
// 원래 데이터와 변경 데이터의 차이만큼 부모 노드로 올라가면서 변경한다.
// - 최대값 찾기
// 변경 데이터와 자신과 같은 부모를 지니고 있는
// 다른 자식 노드와 비교해 더 큰 값으로 업데이트한다.
// 업데이트가 일어나지 않으면 종료한다.
// - 최소값 찾기
// 변경 데이터와 자신과 같은 부모를 지니고 있는
// 다른 자식 노드와 비교해 더 작은 값으로 업데이트한다.
// 업데이트가 일어나지 않으면 종료한다.



#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<long long> num, tree;

long long init(int node, int start, int end) {
	if (start == end) {
		return tree[node] = num[end];
	}

	int mid = (start + end) / 2;

	return tree[node] = init(2 * node, start, mid) + init(2 * node + 1, mid + 1, end);
}

// 함수 Sum(i, j)는 A[i] + A[i+1] + … + A[j]를 구하는 함수이다.
// (i > j일 경우에는 A[j] + A[j+1] + ... + A[i])
long long sum(int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
		return 0;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}

	int mid = (start + end) / 2;

	return sum(2 * node, start, mid, left, right) + sum(2 * node + 1, mid + 1, end, left, right);
}

// Modify(i, k)를 수행하면 A[i] = k가 되는 함수이다.
void update(int node, int start, int end, int idx, long long diff) {
	if (idx < start || idx > end) {
		return;
	}

	tree[node] += diff;

	if (start != end) {
		int mid = (start + end) / 2;

		update(2 * node, start, mid, idx, diff);
		update(2 * node + 1, mid + 1, end, idx, diff);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// 첫째 줄에는 N(1 ≤ N ≤ 1,000,000),
	// M(1 ≤ M ≤ 1,000,000)이 주어진다.
	cin >> n >> m;

	// 처음에는 A[1] = A[2] = … = A[N] = 0이다. 
	num.resize(n + 1, 0);
	tree.resize(4 * (n + 1));

	init(1, 1, n);

	// M은 수행한 명령의 개수이며
	// 다음 M개의 줄에는 수행한 순서대로 함수의 목록이 주어진다.
	while (m--) {
		int c, i, j;

		// 첫 번째 숫자는 어느 함수를 사용했는지를 나타내며,
		// 0일 경우에는 Sum 함수를, 1일 경우에는 Modify 함수를 나타낸다.
		// 다음 두 수는 각 함수의 인자 (i, j)나 (i, k)를 나타낸다.
		cin >> c >> i >> j;

		if (c == 0) {
			if (i > j) {
				swap(i, j);
			}

			// Sum 함수의 개수만큼 각 줄에 Sum 함수의 리턴값을 출력한다.
			cout << sum(1, 1, n, i, j) << '\n';
		}
		// Modify인 경우에 1 ≤ k ≤ 100,000 이다.
		else {
			update(1, 1, n, i, j - num[i]);
			num[i] = j;
		}
	}

	return 0;
}