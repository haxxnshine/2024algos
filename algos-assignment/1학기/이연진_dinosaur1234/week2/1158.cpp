#include <iostream>
#include <queue>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    queue<int> q;
    int N, K;

    cin >> N >> K;

    for (int i = 0;i < N;i++) {
        q.push(i+1);
    }  

    cout << "<";
    while (q.size() > 1) {
        int num;
        for (int j = 0; j < K-1;j++) {
            num = q.front();
            q.pop();
            q.push(num);
        }
        cout << q.front() << ", ";
        q.pop();
    }
    cout << q.front();
    cout << ">";
    return 0;
}
