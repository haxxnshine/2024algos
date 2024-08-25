#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> numbers;
vector<int> copyNumbers;
void input(int testCase);
void sortAndCompress();
void print();

int main() {
    int testCase;
    cin >> testCase;

    input(testCase);
    sortAndCompress();
    print();
}

void input(int testCase) {
    int number;

    for (int i = 0; i < testCase; i++) {
        cin >> number;
        numbers.push_back(number);
        copyNumbers.push_back(number);
    }
}

void sortAndCompress() {
    sort(copyNumbers.begin(), copyNumbers.end());
    copyNumbers.erase(unique(copyNumbers.begin(), copyNumbers.end()), copyNumbers.end());
}

void print() {
    for (int i = 0; i < numbers.size(); i++) {
        auto it = lower_bound(copyNumbers.begin(), copyNumbers.end(), numbers[i]);
        cout << it - copyNumbers.begin() << " ";
    }
}
