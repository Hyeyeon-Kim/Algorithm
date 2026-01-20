#include <vector>
#include <set>
#include <iostream>
#include <cstring>
using namespace std;

int visit[101][101] = {0};
int nX[4] = {1, 0, -1, 0};
int nY[4] = {0, 1, 0, -1};
int N, M;
vector<vector<int>> picture;
int cnt = 0;

void dfs(int x, int y, int type){
    
    for (int i = 0; i < 4; i++){
        int nx = x + nX[i];
        int ny = y + nY[i];
        
        if (nx < 0 || ny < 0 || nx >= M || ny >= N)
            continue;
        if (picture[nx][ny] != type || visit[nx][ny] != 0)
            continue;
        cnt++;
        visit[nx][ny] = 1;
        dfs(nx, ny, type);
    }    
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> p) {
    memset(visit, 0, sizeof(visit));
    vector<int> area;
    M = m;
    N = n;
    picture = p;
    
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (p[i][j] != 0 && visit[i][j] == 0){
                cout << i << " " << j << endl;
                cnt = 1;
                visit[i][j] = 1;
                dfs(i, j, p[i][j]);
                area.push_back(cnt);
            }
        }
    }
    
    int max_ = 0;
    
    for (auto a : area){
        if (max_ < a)
            max_ = a;
        // cout << a.first << " ";
    }

    return {(int)area.size(), max_};
}