#include <string>
#include <vector>
#include <iostream>
using namespace std;

pair<int, int> getDir(char c){
    if (c == 'N'){
        return {-1, 0};
    }
    else if (c == 'S'){
        return {1, 0};
    }
    else if (c == 'W'){
        return {0, -1};
    }
    else{
        return {0, 1};
    }
}

vector<int> solution(vector<string> park, vector<string> routes) {
    int x, y;
    
    int n = park.size();
    int m = park[0].size();
    
    for (int i = 0; i < park.size(); i++){
        for (int j = 0; j < park[i].size(); j++){
            if (park[i][j] == 'S'){
                x = j;
                y = i;
            }
        }
    }
    
    for (string cmd : routes){
        
        cout << y << " " << x << "    ";
        pair<int, int> dir = getDir(cmd[0]);
        int cnt = cmd[2] - '0';
        
        bool can = true;
        int ny = y, nx = x;
        
        while (cnt && can){
            ny += dir.first; 
            nx += dir.second;
            
            if (nx < 0 || ny < 0 || nx >= m || ny >= n){
                can = false;
                break;
            }
            if (park[ny][nx] == 'X')
                can = false;  
            cnt--;
        }
        
        if (!can)
            continue;
        
        x = nx;
        y = ny; 
        
        cout << y << " " << x << "\n";
    }
    
    return {y, x};
}

//  N
// W E
//  S


/*
    "OSO"
    "OOO"
    "OXO"
    "OOO"
*/