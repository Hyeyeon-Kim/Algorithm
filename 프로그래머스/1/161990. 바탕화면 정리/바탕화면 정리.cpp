#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer(4);
    int n = wallpaper.size();
    int m = wallpaper[0].size();
    
    vector<int> i_arr;
    vector<int> j_arr;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (wallpaper[i][j] != '#')
                continue;
            
            i_arr.push_back(i);
            j_arr.push_back(j);

        }
    }
    
    sort(i_arr.begin(), i_arr.end());
    sort(j_arr.begin(), j_arr.end());
    
    // cout << *(max_element(i_arr.begin(), i_arr.end()));
    
    return {i_arr[0], j_arr[0], i_arr[i_arr.size()-1]+1, j_arr[j_arr.size()-1]+1};
}


