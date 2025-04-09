#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct coor{
	int x;
	int y;
};

struct state{
	coor now;
	int cnt = 0;
	int dir;

	bool operator<(const state s) const{
		return this->cnt > s.cnt; 
	}
};

int n;
char board[50][50];
int dist[50][50][4];
coor start = {-1, -1};
int dir[4][2] = {{0, 1}, {1, 0}, {0,-1}, {-1,0}};
int ans = -1;

coor move_light(int x, int y, int idx){
	while (1){
		int nx = x + dir[idx][0];
		int ny = y + dir[idx][1];
		
		if (nx < 0 || ny < 0 || nx >= n || ny >= n)
			break;
			
		x = nx;
		y = ny;

		if (board[nx][ny] == '#' || board[nx][ny] == '*' || board[nx][ny] == '!')
			break;
	}
	return {x, y};
}

void bfs(){
	priority_queue <state> q;
	
	for (int i =0; i < 4; i++){
		q.push({start, 0, i});
		dist[start.x][start.y][i] = 0;
	}
	
	while (!q.empty()){
		coor pos = q.top().now;
		int cnt = q.top().cnt;
		int idx = q.top().dir;
		q.pop();
		
		if (cnt > dist[pos.x][pos.y][idx])
            continue;

		coor next = move_light(pos.x, pos.y, idx);
		
		if (board[next.x][next.y] == '*')
		continue;
		
		if (board[next.x][next.y] == '#' && (next.x != start.x || next.y != start.y)){
			ans = cnt;
			break;
		}
		
		if (cnt < dist[next.x][next.y][idx]) {
            dist[next.x][next.y][idx] = cnt;
            q.push({next, cnt, idx});
        }
		
		int ndir = (idx + 1) % 4;
        if (cnt + 1 < dist[next.x][next.y][ndir]) {
            dist[next.x][next.y][ndir] = cnt + 1;
            q.push({next, cnt + 1, ndir});
        }

        ndir = (idx + 3) % 4;
        if (cnt + 1 < dist[next.x][next.y][ndir]) {
            dist[next.x][next.y][ndir] = cnt + 1;
            q.push({next, cnt + 1, ndir});
        }
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i =0; i < n; i++)
	{
		for (int j =0; j < n; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == '#' && start.x == -1){
				start.x = i;
				start.y = j;
			}
		}
	}

	for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
         for (int d = 0; d < 4; d++)
            dist[i][j][d] = 1e9;

	bfs();
  	cout << ans << "\n";

	return 0;
}