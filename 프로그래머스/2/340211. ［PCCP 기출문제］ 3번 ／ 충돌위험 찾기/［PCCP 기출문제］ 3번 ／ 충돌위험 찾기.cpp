#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

unordered_map<int, pair<int, int>> graph; // 각 포인트의 좌표를 저장하는 맵
vector<map<pair<int,int>,int>> path; // 시간별 좌표에 로봇이 몇 대 모였는지 기록
int ans = 0; // 충돌 상황 횟수

// 각 로봇의 경로를 따라가며 충돌 상황을 기록하는 함수
void createPath(vector<int>& route){
    pair<int, int> last;
    int time = 0;
    for(int i = 0; i < route.size() - 1; i++){
        pair<int, int> begin = graph[route[i]]; // 현재 포인트의 좌표
        pair<int, int> end = graph[route[i+1]]; // 다음 포인트의 좌표
        last = end;

        // 최단 경로를 따라 이동
        while(begin != end){
            path[time][begin]++;
            if(path[time][begin] == 2) ans++; // 2대 이상의 로봇이 모인 경우
            int xDiff = begin.first - end.first;
            int yDiff = begin.second - end.second;

            // r 좌표가 먼저 변하는 규칙
            if (xDiff != 0) {
                if (xDiff < 0) begin.first++;
                else begin.first--;
            } else if (yDiff != 0) {
                if (yDiff < 0) begin.second++;
                else begin.second--;
            }
            time++;
        }
    }

    path[time][last]++;
    if(path[time][last] == 2) ans++;
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    for(int i = 1; i <= points.size(); i++){
        graph[i] = {points[i - 1][0], points[i - 1][1]};
    }
    path.resize(20001); 
    for(auto route : routes){
        createPath(route);
    }

    return ans;
}