#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, m;
vector<vector<int>> commands;
vector<int> arr;

int main() {
    cin.tie(nullptr);

    cin >> n >> m;

    commands.resize(m);
    arr.resize(n);

    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;

        if (a <= 2) {
            int idx, x;
            cin >> idx >> x;
            commands[i] = {a, idx, x};
        } else {
            int idx;
            cin >> idx;
            commands[i] = {a, idx};
        }
    }

	for (int i = 0; i < m; i++) {
		int idx = commands[i][1] - 1, x;
		if (commands[i][0] <= 2)
			x = commands[i][2];

		if (commands[i][0] == 1){
			arr[idx] = arr[idx] | (1 << (20 - x));
		}
		else if (commands[i][0] == 2){
			arr[idx] = arr[idx] & ~(1 << (20 - x));
		}
		else if (commands[i][0] == 3){

			arr[idx] = arr[idx] >> 1 ;
		}
		else if (commands[i][0] == 4){
			arr[idx] = (arr[idx] << 1) & ((1 << 20) - 1);
		}
	}
	set<int> s;
	for (int i = 0; i < n; i++) {
		s.insert(arr[i]);
	}
	cout << s.size();

    return 0;
}
