#include <iostream>
#include <queue>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    deque<int> d;
    int N, M;
    int idx,index;

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        d.push_back(i);
    }

    int t = 0;
    while (M) {
        cin >> index;
        for (int i = 0;i < d.size(); i++) {
            if (d[i] == index) {
                idx = i;
                break;
            }
        }
        if (idx > d.size() / 2) { 
            while (d.front() != index) {
                d.push_front(d.back());
                d.pop_back();
                t++;
            }
        }
        else { 
            while (d.front() != index) {
                d.push_back(d.front());
                d.pop_front();
                t++;
            }
        }
        d.pop_front();
        M--;
    }
    cout << t << "\n";
    return 0;
}
