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
            
            cout << i << " " << j << endl;
            
            i_arr.push_back(i);
            j_arr.push_back(j);
//             if (answer[0] > i)  // 작은거
//                 answer[0] = i;
            
//             else if (answer[1] > j)
//                 answer[1] = j;
            
//             if (answer[2] < i) // 큰거
//                 answer[2] = i;
            
//             if (answer[3] < j)
//                 answer[3] = j;
        }
    }
    sort(i_arr.begin(), i_arr.end());
    sort(j_arr.begin(), j_arr.end());
    
    for(int i : i_arr)
        cout << i << " ";
    cout << endl;
    
    for(int j : j_arr)
        cout << j << " ";
    cout << endl;
    
    return {i_arr[0], j_arr[0], i_arr[i_arr.size()-1]+1, j_arr[j_arr.size()-1]+1};
}


