#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<int> arr(n, 0);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    cin >> n;
    arr = vector<int> (n, 0);
    
    long long total = 0;
    int maxTime = 0;
    
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        total += arr[i];
        maxTime = max(maxTime, arr[i]);
    }
    
    int requiredTime = max(maxTime, (int)((total + 1) / 2));
    
    if (requiredTime > 1440)
        cout << -1;
    else
        cout << requiredTime;
}   
