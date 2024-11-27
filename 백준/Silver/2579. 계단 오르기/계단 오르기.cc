#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> arr;
vector<int> dp;

int stair(int idx)
{
    if (idx < 0)
        return 0;
    
    if (dp[idx] != 0)
        return dp[idx];

    dp[idx] = max(arr[idx]+arr[idx-1]+stair(idx-3), arr[idx]+stair(idx-2)); 
    return dp[idx];
}

int main()
{
    cin >> n;

    arr.resize(n);
    dp.resize(n);
    
    for(int i =0 ; i < n ;i++)
        cin >> arr[i];

    dp[0] = arr[0];
    cout << stair(n-1) << endl;
}