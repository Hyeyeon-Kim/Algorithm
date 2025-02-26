#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
priority_queue<int> pq;

int solve(){

	int ans = 0;

	while (!pq.empty()){
		int a = pq.top();
		pq.pop();
		
		int b;
		
		if (!pq.empty()){
			b = pq.top();
			pq.pop();
			if (b > 1)
				pq.push(--b);
		}
		if (a > 1)
			pq.push(--a);

		ans++;

		if (ans > 1440)
			return -1;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++){
		int num;
		cin >> num;
		pq.push(num);
	}

	cout << solve();
}   
