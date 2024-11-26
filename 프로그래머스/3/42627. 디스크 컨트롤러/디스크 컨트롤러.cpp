#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct work{
    int spend;
    int request;
}work;

struct cmp {
     bool operator()(work a, work b) {
        return a.spend > b.spend;
    }
};

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end());
    
    int time = 0;
    int return_time = 0; 
    int index = 0; // jobs의 인덱스
    
    priority_queue <work, vector<work>, cmp> pq; 
    
    while (index < jobs.size() || !pq.empty())
    {
        while (index < jobs.size() && jobs[index][0] <= time){
            pq.push({jobs[index][1], jobs[index][0]});
            index++;
        }
        
        if (!pq.empty())
        {
            work current = pq.top();
            pq.pop();
        
            time += current.spend;
            return_time += time - current.request;
        }
        else
            time = jobs[index][0];
    }
    
    return return_time/jobs.size();
}