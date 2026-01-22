#include<vector>
#include<iostream>
#include<queue>
#include<array>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps[0].size();
    int nX[4] = {0, 1, 0, -1};
    int nY[4] = {1, 0, -1, 0};
    vector<vector<bool>> visit(n, vector<bool>(m));
    queue<array<int, 3>> q;
    
    q.push({0, 0, 1});
    visit[0][0] = true;
    int ans = -1;
    
    while (!q.empty()){
        int x = q.front()[0];
        int y = q.front()[1];
        int cnt = q.front()[2];
        
        q.pop();
        
        if (x == m -1 && y == n - 1){
            ans = cnt;
            break;
        }
        
        for (int i = 0; i < 4; i++){
            int nx = nX[i] + x;
            int ny = nY[i] + y;
            
            if (nx < 0 || ny < 0|| nx >= m || ny >= n || visit[ny][nx] || maps[ny][nx] != 1)
                continue;
            
            visit[ny][nx] = true;
            q.push({nx, ny, cnt + 1});
        }
    }
    
    return ans;
}