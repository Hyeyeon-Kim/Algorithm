#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main(){

    int n,k;
    int share[101];
    int team[101];
    cin >> n >> k;

    for (int i =0; i <n ;i++)
        cin >> share[i];

    for (int i =0; i <n ;i++)
        cin >> team[i];

    vector <pair<int, int>> v;

    for (int i =0; i < n ;i++){
        for (int j = 0; j < n; j++){
            v.push_back({share[i] * team[j], team[j]}); 
        }
    }
    sort(v.begin(), v.end());

    set <int> s;
    int cnt = 0;
    for (int i = v.size()-1; i >= 0; i--){
        if (s.find(v[i].second) == s.end()){
            // cout << i << " ";
            if (cnt == k){
                cout << v[i].first;
                break;
            }
            cnt++;
            s.insert(v[i].second);
        }
    }
        

    // for (int j =0; j < v.size(); j++)
    //     cout << v[j].second << " ";
    // cout << endl;

    // cout << v[v.size()-1];
}

// 각 공유 카드로 만들 수 있는 팀 카드 조합 중 3번쨰로 큰 값 중 가장 큰 값