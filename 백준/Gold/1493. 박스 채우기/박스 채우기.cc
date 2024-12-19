#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int box[20] = {0};
int ans = 0;
bool impossible = false;

void square(int len, int wid, int hei){
	
	if (len < 1 || wid < 1 || hei < 1)
		return ;

	// 작은 박스로 나누기
	int stand = min({len, wid, hei});
	int idx = log2(stand);

	while (idx >= 0 && box[int(idx)] == 0){
		idx--;
	}
	
	if (idx < 0){
		impossible = true;
		return ;
	}
	
	int cubesize = 1 << idx;
	box[idx]--;
	ans++;

	square(len - cubesize, wid, hei);
	square(cubesize, wid - cubesize, hei);
	square(cubesize, cubesize, hei - cubesize);
}

int main() {

	int len, wid, hei;

	cin >> len >> wid >> hei;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		box[a] = b;
	}

	square(len, wid, hei);

	if (impossible)
		cout << "-1";
	else
		cout << ans;
}