#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> num;
vector<int> oper(4);
int min_ = 2147483647;
int max_ = -2147483647;

void dfs(int plus, int sub, int mul, int div, int cnt, int val){
	if (cnt == n - 1){
		min_ = min(min_, val);
		max_ = max(max_, val);
		// cout << val << endl;
		return ;
	}

	if (plus < oper[0]){
		dfs(plus+1, sub, mul, div, cnt+1, val+num[cnt+1]);
	}
	if (sub < oper[1])
	{
		dfs(plus, sub+1, mul, div, cnt+1, val - num[cnt+1]);
	}
	if (mul < oper[2])
	{
		dfs(plus, sub, mul+1, div, cnt+1, val * num[cnt+1]);
	}
	if (div < oper[3])
	{
		dfs(plus, sub, mul, div+1, cnt+1, val / num[cnt+1]);
	}
}

int main() {
	cin >> n;

	num.resize(n);

	for (int i = 0; i < n; i++)
		cin >> num[i];
	
	for (int i =0; i < 4; i++)
		cin >> oper[i];
	dfs(0,0,0,0,0, num[0]);
	cout << max_ << "\n" << min_;
	return 0;
}

