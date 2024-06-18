#include <iostream>

using namespace std;

int N;

int len(int n) {
    int h = 0;
    while (n > 0) {
        h++;
        n /= 10;
    }

    return h;
}

int findGcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }

    return findGcd(b, a % b);
}

void solution() {
    int j = N;
    int b = N;

    // 각 입력에 대해 해빈이가 주문해야할 치킨박스의 수를 출력한다.
    for (int i = 1; i < N; i++) {
        int tj = j * (N - i) + N * b;
        int tb = b * (N - i);

        int gcd = findGcd(tj, tb);

        j = tj / gcd;
        b = tb / gcd;
    }

    // 만약 답이 정수라면 그대로 출력한다. 
    if (j % b == 0) {
        cout << j / b << endl;
    }
    // 답이 정수가 아니라면
    else {
        int d = j / b;
        j %= b;

        for (int i = 0; i < len(d); i++) {
            cout << " ";
        }
        // 정수부분을 출력하고,
        cout << " " << j << endl;
        // 공백하나를 출력한 다음,
        cout << d << " ";
        
        // 적절히 정수를 뺀 나머지 값을 기약분수를 출력한다. 
        for (int i = 0; i < len(b); i++) {
            cout << "-";
        }
        
        // 불필요한 공백은 출력하지 않는다.
        cout << endl;

        for (int i = 0; i < len(d); i++) {
            cout << " ";
        }
        cout << " " << b << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 신기한 마이마이의 치킨박스 하나를 사면
    // 1부터 N까지의 숫자 중 하나가 적힌 쿠폰 한 개를 준다.
    while (1) {
        // 쿠폰에 적힐 숫자의 범위(1 ≤ N ≤ 22)가 여러 줄에 걸쳐서 주어진다.
        cin >> N;

        if (cin.eof()) {
            break;
        }

        // 1부터 N까지의 쿠폰들을 모두 모아야
        // 골드치즈치킨 하나를 주문할 수 있다고 할 때,
        // 해빈이는 신기한 마이마이의 치킨박스를
        // 평균적으로 얼마나 많이 주문해야 하는가?
        solution();
    }

    return 0;
}