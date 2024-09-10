#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int n, m;
int board[4][6][3];
int tmp[6][3];
int parade[6][6] = {0};
int ans = 0;

void print(){
	for (int i =0; i < 6; i++){
		for (int j = 0; j < 6; j++){
			cout << parade[i][j] << " ";
		}
		cout << endl;
	}
}

bool valid(int y, int x, int status){
	//parade[y][x] == parade[line][col]
	if (parade[x][y] == 0) 
		return true;

	if (status == 1)
		return parade[x][y] == 3;
	if (status == 2)
		return parade[x][y] == 2;
	if (status == 3)
		return parade[x][y] == 1;
}

void dfs(int line, int col){
	if (col >= 6){
		line += 1;
		col = 0;
	}
	if (line >= 6) { // 모든 라인과 열을 다 탐색한 경우
        bool valid_result = true;
        for (int i = 0; i < 6; i++) {
            if (tmp[i][0] != 0 || tmp[i][1] != 0 || tmp[i][2] != 0) {
                valid_result = false;
                break;
            }
        }
        if (valid_result)
            ans = 1;
        return;
    }
	if (line == col)
		return dfs(line, col+1);

	if (tmp[line][0]){
		tmp[line][0]--;
		parade[line][col] = 1;
		if (valid(line, col, 1))
			dfs(line, col+1);
		parade[line][col] = 0;
		tmp[line][0]++;
	}
	if (tmp[line][1]){
		tmp[line][1]--;
		parade[line][col] = 2;
		if (valid(line, col, 2))
			dfs(line, col+1);
		parade[line][col] = 0;
		tmp[line][1]++;
	}
	if (tmp[line][2]){
		tmp[line][2]--;
		parade[line][col] = 3;
		if (valid(line, col, 3))
			dfs(line, col+1);
		parade[line][col] = 0;
		tmp[line][2]++;
	}
}

int main(){
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 18; j++){
			cin >> board[i][j/ 3][j % 3]; 
		}
	}

	for (int k = 0; k < 4; k++)
	{	
		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 3; j++)
				tmp[i][j] = board[k][i][j];
		dfs(0, 0);
		cout << ans << " ";
		memset(parade, 0, sizeof(parade));
		ans = 0;
	}
}