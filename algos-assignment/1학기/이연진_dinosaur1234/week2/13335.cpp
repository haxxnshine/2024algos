#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, w, L;
    cin >> n >> w >> L;

    queue<int> t, b;
    int weight = 0;
    int time = 0;

    for (int i = 0; i < n; i++) {
        int truck;
        cin >> truck;
        t.push(truck);
    }
    for (int i = 0; i < n; i++) {
        while (true) {
            if (t.empty() && b.empty()) {
                break;
            }

            if (b.size() == w) {
                weight -= b.front();
                b.pop();
            }

            if (!t.empty() && weight + t.front() <= L) break;
            b.push(0);
            time++;
        }
        weight += t.front();
        b.push(t.front());
        t.pop();
        time++;
    }
    cout << time+w << "\n";
    return 0;
}
