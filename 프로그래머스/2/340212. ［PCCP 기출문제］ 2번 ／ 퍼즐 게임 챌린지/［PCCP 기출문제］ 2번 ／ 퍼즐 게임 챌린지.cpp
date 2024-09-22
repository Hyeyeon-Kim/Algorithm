// diff len 10^5
// diff 10^5
// time 10^4
//limit 10^15 lonlong 10^64

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    long long len = diffs.size();
    
    long long s = 1;
    long long e = 1000001;
    
    long long answer = 100001;
    
    while (s < e){
        long long level = (s+e)/2;
        long long time = 0;
    
        for (int i = 0; i < len; i++){
            long long diff = diffs[i];
            long long time_cur = times[i];
            long long time_prev = i == 0 ? 0 : times[i-1];
            
            if (diff > level)
                time += (diff-level) * (time_prev + time_cur) + time_cur;
            else
                time += time_cur;
        }
        
        // cout << level << " " << time << endl;
    
        if (time > limit){
            s = level + 1;
        }
        else {
            e = level;
            answer = min(answer, level);
        }
    }
    
    return answer;
}