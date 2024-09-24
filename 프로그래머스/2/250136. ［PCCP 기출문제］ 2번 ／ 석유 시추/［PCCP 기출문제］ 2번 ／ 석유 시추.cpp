#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

//250,000 = 10^5
int visit[501][501] = {0};
vector<vector<int>> cpy;
int next_x[4] = {0, 1, 0, -1};
int next_y[4] = {1, 0, -1, 0};
int n, m;
int cnt = 0;

void dfs (int y, int x, int oil){
    visit[y][x] = oil;
    cnt++;
    
    for (int i = 0;i < 4; i++){
        int nx = next_x[i] + x;
        int ny = next_y[i] + y;
        
        if (nx < 0 || ny < 0 || nx >= m || ny >= n)
            continue;
        if (cpy[ny][nx] == 1 && visit[ny][nx] == 0)
            dfs(ny, nx, oil);
    }
}

void print(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << visit[i][j];
        }
        cout << endl;
    }
}

int solution(vector<vector<int>> land) {
    n = land.size();
    m = land[0].size();
    cpy = land;
    
    int oil = 1;
    int max_ = 0;
    int dp[250000] = {0};
    
    for (int i = 0; i < m; i++){      
        for (int j = 0; j < n; j++){
            if (land[j][i] == 1 && visit[j][i] == 0){
                dfs(j, i, oil);
                dp[oil] = cnt;
                oil++;
                cnt = 0;
            }
        }
    }
    
    for (int i = 0; i < m; i++){
        map<int, int> m;
        
        for (int j = 0; j < n; j++){
            if (land[j][i] == 1){
                
                int num = visit[j][i];
                // cout << dp[num] << " ";
                m.insert({num, dp[num]});
            }
        }
        
        int count = 0;
        for (auto a: m)
            count += a.second;
        
       max_ = max(max_, count);
    }
    
    return max_;
}