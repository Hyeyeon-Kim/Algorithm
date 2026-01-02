#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    map<char, pair<int, int>> way;
    
    way['N'] = {0, -1};
    way['S'] = {0, 1};
    way['W'] = {-1, 0};
    way['E'] = {1, 0};
    
    int x = 0, y = 0;
    int h = park.size(), w = park[0].size();
    
    
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            if (park[i][j] == 'S'){
                x = j;
                y = i;
            }
        }
    }
    
    cout << y << " " << x << endl;
    
    for (string route: routes){
        
        int nx = x;
        int ny = y;
        bool can = true;
        
        for (int i = 0; i < route[2] - '0'; i++){
             nx += way[route[0]].first;
             ny += way[route[0]].second;
            
            if (nx < 0 || ny < 0 || nx >= w || ny >= h || park[ny][nx] == 'X'){
                can = false;
                break;
            }
            cout << ny << "," << nx << "  ";
        }
        cout << can << "      ";
        cout << endl;
        
        if (can){
            x = nx;
            y = ny;
        }
    }
    
    return {y, x};
}