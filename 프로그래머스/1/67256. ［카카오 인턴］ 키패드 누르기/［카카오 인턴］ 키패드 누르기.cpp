#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <iostream>
using namespace std;

// char button(int ){
// }

string solution(vector<int> numbers, string hand) {
    string answer = "";
    map<char, int> m;
    
    for (int i = 0; i <= 9; i++)
        m.insert({i+'0', i});
    m.insert({'*', 10});
    m.insert({'#', 11});
    
//     0 1 2 3 4 5 6 7 8 9 * #
    int coor[12][2] = {{3,1},{0, 0},{0, 1},{0, 2},{1, 0},{1,1},{1,2},{2,0},{2,1},{2,2},{3,0},{3,2}};
    int dist[12][12] = {0};
    
    for (int i =0 ; i < 12;i ++){
        for (int j =0; j < 12;j ++)
            dist[i][j] = abs(coor[i][0]-coor[j][0]) + abs(coor[i][1]-coor[j][1]);
    }
    
    // for (int i =0 ; i < 12;i ++){
    //     for (int j =0; j < 12;j ++)
    //         cout << dist[i][j] << " ";
    //     cout << endl;
    // }

    
    char preL = '*', preR = '#';
    
    for (int n : numbers){
        char now = hand == "right" ? 'R' : 'L';
            
        if (n == 1 || n == 4 || n == 7)
            now = 'L';
        else if (n == 3 || n == 6 || n == 9)
            now = 'R';
        else{
            if (dist[m[preL]][n ] != dist[m[preR]][n ]){
                if (dist[m[preL]][n] < dist[m[preR]][n])
                    now = 'L';
                else
                    now = 'R';
            }
        }
        
        cout << preL << " " << preR << " " << n << " " << now << " " << dist[m[preL]][n ] << " " << dist[m[preR]][n] << "\n";
        
        answer += now;
        
        if (now == 'L')
            preL = n + '0';
        else
            preR = n + '0';
    }
    
    return answer;
}