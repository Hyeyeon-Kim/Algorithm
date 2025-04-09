#include <iostream>
#include <queue>
using namespace std;

struct candy{
    pair<int,int> red;
    pair<int,int> blue;
    int cnt = 0;
};

int n, m;
char map[11][11];
bool visited[11][11][11][11];
pair<int,int> goal;
candy start;

int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

int dsd = 0;

pair<int,candy> afterMove(int idx, candy t){
    bool red_out = false;
    bool blue_out = false;
    candy value = t;

    while (1){
        int rx = t.red.first + dir[idx][0];
        int ry = t.red.second + dir[idx][1];
        
        int bx = t.blue.first + dir[idx][0];
        int by = t.blue.second + dir[idx][1];
        
        int finish = 0;

        // cout << rx << " " << ry << " " << bx << " " << by << endl;

        if (rx < 0 || ry < 0 || rx >= n || ry >= m || map[rx][ry] == '#' || (rx == t.blue.first && ry == t.blue.second))
            finish++;
        else
            t.red = {rx, ry};

        if (bx < 0 || by < 0 || bx >= n || by >= m || map[bx][by] == '#'|| (bx == t.red.first && by == t.red.second))
            finish++;
        else
            t.blue = {bx, by};

        value = t;

        if (finish == 2)
            break;

        if (map[bx][by] == 'O'){
            blue_out = true;
            break;
        }

        if (map[rx][ry] == 'O')
        {
            t.red = {n, m};
            red_out = true;
        }

        // if(dsd == 20)
        //     break;
        // dsd++;
    }

    if (blue_out)
        return {1, value};
    else if (red_out)
        return {2, value};
    else
        return {3, value};
}

int ans = -1;

void bfs(){
    queue <candy> q;

    q.push(start);
    visited[start.blue.first][start.blue.second][start.red.first][start.red.second] = 1;

    while (!q.empty()){
        candy now = q.front();
        q.pop();

        if (ans != -1)
            break; 
        
        if (now.cnt == 10)
            break;

        for (int i = 0; i < 4; i++){
            pair<int, candy> result = afterMove(i, now);
            result.second.cnt++;

            if (result.first == 2){
                ans = result.second.cnt; 
                break;
            }
            else if (result.first == 3){
                if (visited[result.second.blue.first][result.second.blue.second][result.second.red.first][result.second.red.second])
                    continue;
                q.push(result.second);
                visited[result.second.blue.first][result.second.blue.second][result.second.red.first][result.second.red.second] = 1;
            }
        }
    }
}

int main() {

    cin >> n >> m;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> map[i][j];
            
            if (map[i][j] == 'O')
                goal = {i, j};
            
            else if (map[i][j] == 'R'){
                start.red = {i, j};
                map[i][j] = '.';
            }

            else if (map[i][j] == 'B'){
                start.blue = {i, j};
                map[i][j] = '.';
            }
        }
    }

    bfs();
    cout << ans;

    return 0;
}