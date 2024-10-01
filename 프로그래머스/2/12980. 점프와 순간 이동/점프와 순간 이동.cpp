#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// bool check(int n){
//     if (n == 1)
//         return true;
//     if (n % 2 == 1)
//         return false;
//    return check(n/2);
// }

int dfs(int n, int cnt){
    if (n == 1)
        return cnt;
    if (n % 2 == 1)
        return dfs(n/2, cnt + 1);
    else
        return dfs(n/2, cnt);
}

int solution(int n)
{
    return dfs(n, 1);
}