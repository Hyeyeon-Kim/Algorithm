#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

bool com (int a, int b){
	if (a % 10 == 0 && b % 10 == 0)
		return a < b;
	else if (a % 10 == 0 || b % 10 == 0){
		if (a % 10 == 0)
			return true;
		else 
			return false;
	}
	else 
		return a < b;
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a.begin(), a.end(), &com);

	int ans = 0;

	for (int i = 0; i < n; i++)
	// 	cout << a[i] << " ";
	{
		if (m == 0)
			break;

		while (a[i] > 10 && m > 0){
			a[i] -= 10;
        	ans++;
        	m--;
		}

   		if (a[i] == 10)
        	ans++;		
	}

	cout << ans;
}