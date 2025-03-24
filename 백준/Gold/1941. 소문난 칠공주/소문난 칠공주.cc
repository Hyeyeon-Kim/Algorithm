#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

char map[5][5];
int next_x[] = {0, 1, 0, -1};
int next_y[] = {1, 0, -1, 0};
int visited[25] = {0};
int combi[7];
int ans = 0;

bool bfs(){
	queue<pair<int, int> > q;
	int check[5][5] = {0};
	check[combi[0] / 5][combi[0] % 5] = 1;
	q.push(make_pair(combi[0] / 5, combi[0] % 5));
	int cnt = 0;

	while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;

        cnt++;

        if (cnt == 7) 
			return true;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + next_x[i];
            int nx = x + next_y[i];

            if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5) 
				continue;
            if (!visited[ny * 5 + nx])
				continue;
            if (check[ny][nx]) 
				continue;

            q.push(make_pair(ny, nx));
            check[ny][nx] = true;
        }
    }

	return false;
}

void combination(int cnt, int pre, int y){
	if (y >= 4)
		return ;
	if (cnt == 7){
		if (bfs())
			ans++;
		return ;
	}

	for (int i = pre; i < 25; i++){
		if (visited[i] == 1)
			continue;
		
		visited[i] = 1;
		combi[cnt] = i;
		combination(cnt+1, i+1, map[i / 5][i % 5] == 'Y' ? y + 1 : y);
		visited[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++) 
			cin >> map[i][j];
	
	combination(0, 0, 0);

	cout << ans;

	return 0;
}