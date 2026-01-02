#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    
    for (int i = 0; i < schedules.size(); i++){
        int h = schedules[i] / 100;
        int m = schedules[i] % 100;
        schedules[i] = h * 60 + m + 10;
        cout << schedules[i] << " ";
    }
    
    cout << endl;
    
    int ans = 0;
    
    for (int i = 0; i < timelogs.size(); i++){
        bool give = true; 
        for (int j = 0 ; j < 7; j++){
            if ((j + startday) % 7 == 0 ||  (j + startday) % 7 == 6)
                continue;

            int h = timelogs[i][j] / 100;
            int m = timelogs[i][j] % 100;
            int time = h * 60 + m;
            if (time > schedules[i])
                give = false; 
            cout << time << " ";
        }
        cout << give;
        if (give)
            ans++;
        cout << endl;
    }
    
    return ans;
}