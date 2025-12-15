#include <string>
#include <vector>
// #include <algoruthm>
using namespace std;

int arr[3] = {0};
int ans = 0 ;
int n;

void dfs(int idx, int pre,int sum, vector<int> &num){
    if (idx >= 3){
        if (sum == 0)
            ans++;
        return ;
    }
    
    for (int i = pre + 1; i < n; i++){
        dfs (idx+1, i ,sum + num[i], num);
    }
}

int solution(vector<int> number) {
    n = number.size();
    dfs(0, -1, 0, number);
    // sort(number.begin(), number.end());
    // int sum = number;
        
    // int s = 0;
    // int e = ;
    
    return ans;
}