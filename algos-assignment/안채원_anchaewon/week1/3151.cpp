#include <iostream>
#include <algorithm>
using namespace std; 

int A[10001];

int main(){    
    ios::sync_with_stdio(0);    
    cin.tie(0);    
    
    int N; cin >> N;    
    for (int i = 0; i < N; i++) cin >> A[i];     
    sort(A, A + N);        
    long long ans = 0;    
    for(int i = 0; i < N - 2; i++){        
        for(int j = i + 1; j < N - 1; j++){         
            int sum = A[i] + A[j];           
            int st = lower_bound(A + (j + 1), A + N, sum * -1) - A;            
            int ed = upper_bound(A + (j + 1), A + N, sum * -1) - A;            
            ans += ed - st;       
        }   
    } 
    cout << ans;
    return 0;
}
