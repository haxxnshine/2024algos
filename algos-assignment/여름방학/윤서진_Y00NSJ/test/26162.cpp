#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<bool>v(118 + 1, true);
    for (int i = 2; i <= 118; i++) {
        if (v[i]) {
            for (int j = i * i; j <= 118; j += i) {
                v[j] = false;
            }
        }
    }

    int n, a;
    cin >> n;
    while (n--) {
        bool ans = false;
        cin >> a;
        for (int i = 2; i <=  a / 2; i++) {
            if (v[i] && v[a - i]) {
                ans = true;
                break;
            }
        }
        if (ans) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
}
