#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long sum (int n){
    if (n < 10)
        return n;
    
    return n % 10 + sum(n * 0.1);
}

int main(){
    int n;

    cin >> n;
    
    int i = 0;
    for (i = 1 ;i <= n;i ++){
        int num = sum(i); 
            
        if (num + i == n){
            cout << i;
            break;
        }
    }

    if (i == n+1)
        cout << 0;
    
}




