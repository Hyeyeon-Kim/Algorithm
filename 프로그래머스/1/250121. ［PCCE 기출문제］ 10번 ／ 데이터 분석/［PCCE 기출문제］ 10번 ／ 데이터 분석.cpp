#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int getIdx(string str){
    if (str == "code")
        return 0;
    else if (str == "date")
        return 1;
    else if (str == "maximum")
        return 2;
    else
        return 3;
}

vector<vector<int>> answer;
int n;
int ext_idx;
int sort_idx;

bool com(vector<int> &a, vector<int> &b){
    // cout << (a[sort_idx] > b[sort_idx]) << " "<< a[sort_idx] << " "<< b[sort_idx] << "\n";
        return a[sort_idx] < b[sort_idx];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    n = data.size();
    ext_idx = getIdx(ext);
    sort_idx = getIdx(sort_by);
    
    for (int i = 0; i < n; i++){
        if (data[i][ext_idx] < val_ext)   
            answer.push_back(data[i]);
    }
    
    sort(answer.begin(), answer.end(), com);
    
    // for (int i = 0; i < n; i++){
    //     cout
    // }
    
    return answer;
}