#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str, B, result;
    
    cin >> str;
    cin >> B;
    for (int i = 0; i < str.length();i++) {
        result.push_back(str[i]);

        if (str[i] == B.back() && str.size() >= B.size() && !result.empty()) { //최근에 넣은 문자열과 폭탄의 마지막 문자열이 같은 경우 -> 확인 필요
            string c;
            for (int j = 0; j < B.length(); j++) {
                if (result.empty()) break;
                c.push_back(result[result.length()-1]);
                result.pop_back();
            }
            reverse(c.begin(), c.end());
            if (B.compare(c) != 0) {
                for (int k = 0; k < c.length(); k++) {
                    result.push_back(c[k]);
                }
            }
        }
    }


    if (result.empty()) cout << "FRULA" << "\n";
    else cout << result << "\n";

    return 0;
}
