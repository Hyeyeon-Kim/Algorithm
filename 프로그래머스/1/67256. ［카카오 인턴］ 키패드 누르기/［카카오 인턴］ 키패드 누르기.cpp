#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";

    int coor[12][2] = {{3,1},{0, 0},{0, 1},{0, 2},{1, 0},{1,1},{1,2},{2,0},{2,1},{2,2},{3,0},{3,2}};
    int dist[12][12] = {0};
    
    for (int i =0 ; i < 12;i ++){
        for (int j =0; j < 12;j ++)
            dist[i][j] = abs(coor[i][0]-coor[j][0]) + abs(coor[i][1]-coor[j][1]);
    }
    
    int preL = 10, preR = 11;
    
    for (int n : numbers){
        char now = hand == "right" ? 'R' : 'L';
            
        if (n == 1 || n == 4 || n == 7)
            now = 'L';
        else if (n == 3 || n == 6 || n == 9)
            now = 'R';
        else{
            if (dist[preL][n] != dist[preR][n]){
                if (dist[preL][n] < dist[preR][n])
                    now = 'L';
                else
                    now = 'R';
            }
        }
        
        answer += now;
        
        if (now == 'L')
            preL = n;
        else
            preR = n;
    }
    
    return answer;
}