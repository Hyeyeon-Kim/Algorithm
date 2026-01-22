#include<vector>
#include<iostream>
#include<queue>
#include<array>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int n = maps.size(), m = maps[0].size();
    int nX[4] = {0, 1, 0, -1};
    int nY[4] = {1, 0, -1, 0};
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<array<int, 2>> q;
    
    q.push({0, 0});
    dist[0][0] = 1;
    
    while (!q.empty()){
        auto [x, y] = q.front(); q.pop();
        
        if (x == m -1 && y == n - 1)
            return dist[y][x];
    
        for (int i = 0; i < 4; i++){
            int nx = nX[i] + x;
            int ny = nY[i] + y;
            
            if (nx < 0 || ny < 0|| nx >= m || ny >= n || dist[ny][nx]!= -1|| maps[ny][nx] == 0)
                continue;
            
            dist[ny][nx] = dist[y][x] + 1;
            q.push({nx, ny});
        }
    }
    
    return -1;
}