#include <iostream>
#include <set>
using namespace std;

int node[501];
int rank_[501]; 
bool hasCycle[501] = {0};

int root(int x){
	if (node[x] == x)
		return x;
	return node[x] = root(node[x]);
}

void join(int a, int b){
	int  x = root(a);
	int  y = root(b);

	if (x != y) {
        // Union-Find 최적화: 트리의 높이를 고려하여 병합
        if (rank_[x] < rank_[y]) {
            node[x] = y;
        } 
		else if (rank_[x] > rank_[y]) {
            node[y] = x;
        } else {
            node[y] = x;
            rank_[x]++;
        }
    }
}

int main(){
	int n, m;
	int T = 1;

	while (1){
		cin >> n >> m;

		if (n == 0 && m == 0)
			break;

		for (int i = 1; i <= n; i++){
			node[i] = i;
			rank_[i] = 0;
			hasCycle[i] = false; 
		}

		for (int i = 0; i < m; i++){
			int a, b;

			cin >> a >> b;	

			int rootA = root(a);
            int rootB = root(b);

			if (root(a) == root(b))
				hasCycle[rootA] = true;
			else
				join(a, b);
		}

		int cnt = 0;
		set<int> s;
		for (int i = 1; i <= n; i++){
			int rootI = root(i);

			if (s.find(rootI) == s.end()) {
                s.insert(rootI);
                if (!hasCycle[rootI]) {
                    cnt++;  // 사이클이 없는 집합은 트리
                }
            }
		}

		cout << "Case " << T;
        if (cnt == 0) {
            cout << ": No trees.\n";
        } else if (cnt == 1) {
            cout << ": There is one tree.\n";
        } else {
            cout << ": A forest of " << cnt << " trees.\n";
        }
		T++;
	}
}