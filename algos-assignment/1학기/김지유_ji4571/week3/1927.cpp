#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    priority_queue<int, vector<int>, greater<int>> a;
    int n, m;
    cin >> n;
    while(n--){
        cin >> m;
      
        if (m==0){
            if(a.empty()){
                cout << 0 <<"\n";
            }
            else{
                cout << a.top() <<"\n";
                a.pop();
            }
        }
        else{
            a.push(m);
        }
        
        
    }
    return 0;
}
