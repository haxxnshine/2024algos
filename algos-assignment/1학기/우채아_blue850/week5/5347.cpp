#include <iostream>
using namespace std;

long long t, a, b;

int gcd(int x, int y)
{
    if (x % y == 0) return y;
    else return gcd(y, x % y);
}

int main() {
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        cout << (a / gcd(a, b)) * (b / gcd(a,b)) * gcd(a,b) << '\n';
    }
    return 0;
}
