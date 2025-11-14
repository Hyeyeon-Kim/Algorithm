#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int met_cnt;
int ans = -1;
int n, m;
vector<int> mat;
vector<vector<string>> other;

bool is_ok(int x, int y, int idx){
    // cout << x << " : " << y << "   ";
    for (int i = 0; i < mat[idx]; i++){
        for (int j = 0; j < mat[idx]; j++){
            // cout << (x + j >= m || y + i >= n || x + j < 0 || y + i < 0) << "-  ";
            if (x + j >= m || y + i >= n || x + j < 0 || y + i < 0)
                return false;
            // cout << (other[y + i][x + j] != "-1") << "\n";
            if (other[y + i][x + j] != "-1")
                return false;
        }
    }
    return true;
}

void dfs(int x, int y, int idx){
    // cout << x << " : " << y  << endl;
    // cout << x << " : " << y  << endl;
    if (idx == met_cnt)
        return ;
    bool tmp = is_ok(x, y, idx);
    cout << x << " " << y << " " << mat[idx] << "   " << tmp << endl;
    if (tmp){
        ans = mat[idx];
        return ;
    }
    
    if (x < m)
        dfs(x+1, y, idx);
    else if (y < n)
        dfs(0, y + 1, idx);
    else
        dfs(0, 0, idx + 1);
}

int solution(vector<int> mats, vector<vector<string>> park) {
    sort(mats.begin(), mats.end(), greater<int>());
    n = park.size();
    m = park[0].size();
    mat = mats;
    other = park;
    met_cnt = mats.size();
    
    dfs(0, 0, 0);
    return ans;
}

// 250 * 10 * 400 