#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

// int dir[4][2] = {{0,1}, {-1,0}, {1,0}, {0,-1}};
int dir[4][2] = {
    { 1,  0}, // d: 아래
    { 0, -1}, // l: 왼쪽
    { 0,  1}, // r: 오른쪽
    {-1,  0}, // u: 위
};
string word = "dlru";
string ans;
bool can = false;
int n, m, r, c, x, k;

void dfs(int x, int y, int cnt, string s){
    if (can)
        return ;
    if (cnt > k)
        return ;
    
    if (x == r && y == c && k == cnt){
        ans = s;
        can = true;
        return;
    }
    
     for (int i = 0; i < 4; i++){
        int nx = dir[i][0] + x;
        int ny = dir[i][1] + y;
        
        int dist = abs(r-nx) + abs(ny-c);
        int left = k - cnt-1;
         
        if (nx <= 0 || ny <= 0 || nx > n || ny > m || dist > left || (left - dist) % 2 != 0)
            continue;

        dfs(nx, ny, cnt+1, s+word[i]);
    }
}

string solution(int N, int M, int sx, int sy, int R, int C, int K) {
    
    n = N;
    m = M;
    r = R;
    c = C;
    k = K;
    
    dfs(sx, sy, 0, "");
    if (!can){
        return "impossible";
    }

    return ans;
}