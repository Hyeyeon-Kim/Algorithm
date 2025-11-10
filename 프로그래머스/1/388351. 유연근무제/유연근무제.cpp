#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int n = schedules.size();
    
    // int weekend_s = (6 - startday) < 0 ? 6 : 6 - startday;
    
    // cout << startday << " " << weekend_s<< endl;
        
    int answer = 0;
    
    for (int i = 0; i < n; i++){
        
        // int sh, sm, hp, mp, cnt = 0;
        bool ok = true;
        
        // sh = schedules[i] / 100;
        // sm = schedules[i] % 100; 
        // mp = (sm + 10) % 60;
        // hp = sh + (sm + 10) / 60;
        
        // cout << sh << ":" << sm << " ~ " << hp << ":" << mp << "     ";
        
        for (int j = 0; j < 7; j++){
            int day = (startday + j - 1) % 7 + 1; // j번째 날의 실제 요일 (1~7)
            if (day == 6 || day == 7) 
                continue;
            
           int limit = (schedules[i] / 100) * 60 + (schedules[i] % 100) + 10;
            int logtime = (timelogs[i][j] / 100) * 60 + (timelogs[i][j] % 100);

            if (logtime > limit) { // 지각
                ok = 0;
                break;
            }
            
//             int h, m;
            
//             h = timelogs[i][j] / 100;
//             m = timelogs[i][j] % 100;
            
//             // cout << h << ":" << m << "     ";
            
//             if (sh > h){
//                 cout << h << ":" << m << "     ";
//                 cnt++;
//             }
//             else if (sh == h){
//                 if (m <= mp){
//                     cout << h << ":" << m << "     ";
//                     cnt++;
//                 }
//             }            
//             else if (sh < h && hp == h){
//                 if (sm >= m && m <= mp){
//                     cout << h << ":" << m << "     ";
//                     cnt++;
//                 }
//             }
//         }     
        
        }
        if (ok)
            answer++;
    }
    
    return answer;
}

/*
1 5
2 4
3 3
4 2
5 1
6 0
7 6
*/