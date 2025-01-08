#include <iostream>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

int next_x[4] = {0, 1, 0, -1};
int next_y[4] = {1, 0, -1, 0};

int cheese[101][101];
int c, r;
int time_ = 0, last_melt = 0;

void first_find_air(){
	queue<pair<int,int>> q;
	
	int visit_[101][101] = {0};
	q.push({0, 0});

	while (1){
		queue<pair<int,int>> melt_cheese;
		while (!q.empty()){
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++){
				int nx = next_x[i] + x;
				int ny = next_y[i] + y;

				if (nx < 0 || nx > c || ny < 0 || ny > r)
					continue;

				if (visit_[ny][nx] == 0){
					if (cheese[ny][nx] == 0){
						q.push({nx, ny});
					}
					else {
						cheese[ny][nx] = 0;
						melt_cheese.push({nx,ny});
					}
					visit_[ny][nx] = 1;
				}
			}
		}
		if (melt_cheese.empty())
			break;
		q = melt_cheese;
		last_melt = melt_cheese.size();
		time_++;
	}
}
	
int main()
{
	cin >> r >> c;

	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			cin >> cheese[i][j];
	
	first_find_air();
	cout << time_ << endl << last_melt << endl;
}