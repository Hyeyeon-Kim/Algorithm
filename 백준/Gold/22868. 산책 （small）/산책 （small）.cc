#include <iostream>
#include <algorithm> 
#include <vector>
#include <queue>
using namespace std;

typedef struct channel{
	int cnt;
	int node;
	vector <int> work;
}chennel;

int main(){
	int n, m;
	cin >> n >> m;

	vector<vector<int> > gragh (n+1);

	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		gragh[a].push_back(b);
		gragh[b].push_back(a);
	}

	for (int i = 0; i < n; i++)
		sort(gragh[i].begin(), gragh[i].end());

	int s, e;
	cin >> s >> e;

	vector <int > visit(n+1);
	queue<chennel> q;
	vector<int> work;
	q.push({0, s, work});

	int a;

	while (!q.empty()){
		int cnt = q.front().cnt;
		int node = q.front().node;
		vector<int> w = q.front().work;

		visit[node] = 1;
		q.pop();

		if (node == e){
			work = w;
			a = cnt;
			break;
		}

		for (int i = 0; i < gragh[node].size(); i++){
			int next = gragh[node][i];

			if (visit[next] == 0){
				w.push_back(next);
				q.push({cnt+1, next, w});
				w.pop_back();
			}
		}
	}

	vector <int > v(n+1);
	for (int i = 0; i < work.size();i++)
		v[work[i]] = 1;
	
	queue<pair<int,int>> q1;
	q1.push({a, e});

	while (!q1.empty()){
		int cnt = q1.front().first;
		int node = q1.front().second;

		v[node] = 1;
		q1.pop();

		if (node == s){
			a = cnt;
			break;
		}

		for (int i = 0; i < gragh[node].size(); i++){
			int next = gragh[node][i];

			if (v[next] == 0){
				q1.push({cnt+1, next});
			}
		}
	}
	cout << a << endl;
}