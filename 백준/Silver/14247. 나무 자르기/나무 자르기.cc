#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;

    cin >> n;
    vector <pair<int,int>> grow(n);
    vector <int> tree(n);

    for (int i = 0; i < n; i++)
        cin >> tree[i];
    for (int i = 0; i < n; i++){
        cin >> grow[i].first;
        grow[i].second = i;
    }

    sort(grow.begin(), grow.end());

    long long ans = 0;
    for (int i = 0; i < n; i++){
        // cout << grow[i].first << " " << grow[i].second << endl;
        ans += grow[i].first * i + tree[grow[i].second];
    }

    cout << ans;

}

