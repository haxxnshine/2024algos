#include <bits/stdc++.h>
using namespace std;

int rainbow[7][2];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int size;
    cin >> size;
    char c;
    bool small = true, big = true, both = false;

    for (int i = 0; i < size; i++) {
        cin >> c;
        switch (c)
        {
            case 'R': case 'r':
                c == 'R'? rainbow[0][0]++ : rainbow[0][1]++;
                break;
            case 'O': case 'o':
                c == 'O'? rainbow[1][0]++ : rainbow[1][1]++;
                break;
            case 'Y': case 'y':
                c == 'Y'? rainbow[2][0]++ : rainbow[2][1]++;
                break;
            case 'G': case 'g':
                c == 'G'? rainbow[3][0]++ : rainbow[3][1]++;
                break;
            case 'B': case 'b':
                c == 'B'? rainbow[4][0]++ : rainbow[4][1]++;
                break;
            case 'I': case 'i':
                c == 'I'? rainbow[5][0]++ : rainbow[5][1]++;
                break;
            case 'V': case 'v':
                c == 'V'? rainbow[6][0]++ : rainbow[6][1]++;
                break;
        }
    }
    for (int i = 0; i < 7; i++) {
        if (rainbow[i][0] < 1) big = false;
        if (rainbow[i][1] < 1) small = false;
    }
    if (big && small) cout << "YeS";
    else if (big) cout << "YES";
    else if (small) cout <<"yes";
    else cout << "NO!";
}
