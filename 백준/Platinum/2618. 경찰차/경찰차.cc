#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, w;
vector<pair<int, int>> events;
vector<vector<int>> dp;
vector<vector<int>> choice;

int dist(pair<int, int> a, pair<int, int> b){
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int solve (int i, int j){
	int k = max(i, j) + 1;

	if (k > w)
		return 0;
	
	int ret = dp[i][j];
	if (ret != -1)
		return ret;
	
	pair<int, int> car1;
	pair<int, int> car2;

	if (i == 0)
		car1 = {1, 1};
	else
		car1 = events[i];

	if (j == 0)
		car2 = {n, n};
	else
		car2 = events[j];
	
	int d1 = dist(car1, events[k]) + solve(k, j);
	int d2 = dist(car2, events[k]) + solve(i, k);

	if (d1 < d2){
		ret = d1;
		choice[i][j] = 1;
	}
	else{
		ret = d2;
		choice[i][j] = 2;
	}
	dp[i][j] = ret;
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> w;
	events = vector<pair<int, int>> (w+1);
	dp = vector<vector<int>> (w+1, vector<int>(w+1, -1));
	choice = vector<vector<int>> (w+1, vector<int>(w+1));

	for (int i = 1; i <= w; i++){
		int x, y;
		
		cin >> x >> y;
		events[i] = {x, y};
	}


	int totalCost = solve(0, 0);
    cout << totalCost << "\n";
	
	int i = 0, j = 0;
    for (int k = 1; k <= w; k++){
        if (choice[i][j] == 1) {
            cout << 1 << "\n";
            i = k;  
        } else {
            cout << 2 << "\n";
            j = k;
        }
    }
}