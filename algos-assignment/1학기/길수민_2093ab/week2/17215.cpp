#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<pi, int> pii;
typedef pair<pi, pi> pipi;

const int MAX = 1e6 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
string str;

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    cin >> str;
    int frame = 1, cur = 0;
    int score = 0;
    while (frame <= 10) {
        if (str[cur] == 'S') {
            score += 10;
            int tmp = 0;
            if (str[cur + 1] == 'S') {
                score += 10;
                tmp = 10;
            } else if (str[cur + 1] != '-') tmp = str[cur + 1] - '0', score += tmp;
            if (str[cur + 2] == 'S')
                score += 10;
            else if (str[cur + 2] == 'P') score += 10 - tmp;
            else if (str[cur + 2] != '-') score += str[cur + 2] - '0';
            cur++;
        } else {
            int tmp = 0;
            if (str[cur] != '-') tmp = str[cur] - '0', score += tmp;
            if (str[cur + 1] == 'P') {
                score += 10 - tmp;
                if (str[cur + 2] == 'S') score += 10;
                else if (str[cur + 2] != '-') score += str[cur + 2] - '0';
            } else if (str[cur + 1] != '-') score += str[cur + 1] - '0';
            cur += 2;
        }
        frame++;
    }
    cout << score << "\n";
    return 0;
}
