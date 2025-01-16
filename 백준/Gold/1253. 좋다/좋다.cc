#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main(){
	int n;

	cin >> n;

	vector<int> a(n);
	map<int, int> num;

	for (int i = 0; i < n; i++){
		cin >> a[i];
		if (num.find(a[i]) == num.end())
			num.insert({a[i], 1});
		else
			num[a[i]]++;
	}

	sort(a.begin(), a.end());

	int count = 0;

    for (int k = 0; k < n; k++) {
        int i = 0, j = n - 1;
        while (i < j) {
            if (i == k) {
                i++;
                continue;
            }
            if (j == k) {
                j--;
                continue;
            }
            if (a[i] + a[j] == a[k]) {
                count++;
                break;
            } else if (a[i] + a[j] < a[k]) {
                i++;
            } else {
                j--;
            }
        }
    }

	cout << count;

}