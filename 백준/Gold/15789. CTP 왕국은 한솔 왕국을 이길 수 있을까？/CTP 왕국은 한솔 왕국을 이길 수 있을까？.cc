#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int n, m;
vector<int> kingdom;

int rootfind(int x){
	if (kingdom[x] != x)
		return kingdom[x] = rootfind(kingdom[x]);
	return x;
}

void join(int a, int b){
	int x = rootfind(a);
	int y = rootfind(b);

	if (x < y)
		kingdom[y] = x;
	else
		kingdom[x] = y;
}

bool com(pair<int, int> a, pair<int, int> b){
	return a.second < b.second;
}

int main(){

	cin >> n >> m;
	kingdom.resize(n+1);

	for (int i = 1 ; i <= n; i++)
		kingdom[i] = i;
	
	for (int i = 0 ; i < m; i++){
		int a, b;
		cin >> a >> b;

		join(a, b);
	}

	map <int, int> m;

	for (int i = 1 ; i <= n; i++)
	{
		int root = rootfind(kingdom[i]);
		auto iter = m.find(root);  
		if (iter == m.end())
			m.insert({root, 1});
		else
			iter->second += 1;
	}

	vector <pair<int, int>> data(m.begin(), m.end());
	sort(data.begin(), data.end(), &com);

	int c, h, k;
	cin >> c >> h >> k;

	int cPower = m[rootfind(c)];
	int hPower = m[rootfind(h)];
	// cout << ans << endl;

	while (k && !data.empty()){
		int node = data.back().first;
		int cnt = data.back().second;
		data.pop_back();

		if (rootfind(node) != rootfind(h) && rootfind(node) != rootfind(c)){
			join(c, node);
			cPower += cnt;
			k--;
		}
	}

	cout << cPower;

	// for (int i =0 ; i < data.size(); i++)
	// 	cout << data[i].first << " " << data[i].second << endl;

}