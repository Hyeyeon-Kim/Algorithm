#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int input[5][5]= {0};
int next_x[4] = {0, 1, -1, 0};
int next_y[4] = {1, 0, 0, -1};
set<int> ans;

void dfs(int cnt, int x, int y, int num){
    if (cnt == 6){
    // printf("%d, %d, %d, %d\n", cnt, x, y, num);
        ans.insert(num);
        return ;
    }
    for (int i = 0; i < 4; i++){
        int nx = next_x[i] + x;
        int ny = next_y[i] + y;

        if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5)
            continue;
        dfs(cnt+1, nx, ny, num*10 + input[ny][nx]);
    }
}

int main() {
    
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            cin >> input[i][j];
        }
    }

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            dfs(1, j, i, input[i][j]);
        }
    }

    cout << ans.size();
}   
