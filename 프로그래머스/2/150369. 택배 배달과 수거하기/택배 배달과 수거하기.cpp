#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    stack<pair<int, int>> deli;
    stack<pair<int, int>> pick;

    // 스택 초기화
    for (int i = 0; i < n; i++) {
        if (deliveries[i] != 0)
            deli.push({i + 1, deliveries[i]});
        if (pickups[i] != 0)
            pick.push({i + 1, pickups[i]});
    }

    long long answer = 0;

    while (!deli.empty() || !pick.empty()) {
        int home = 0;

        // 가장 먼 위치 선택
        if (!deli.empty()) home = max(home, deli.top().first);
        if (!pick.empty()) home = max(home, pick.top().first);

        answer += home * 2; // 왕복 거리 계산

        int dbox = 0, pbox = 0;

        // 배달 처리
        while (!deli.empty() && dbox < cap) {
            if (dbox + deli.top().second <= cap) {
                dbox += deli.top().second;
                deli.pop();
            } else {
                deli.top().second -= (cap - dbox);
                dbox = cap;
            }
        }

        // 픽업 처리
        while (!pick.empty() && pbox < cap) {
            if (pbox + pick.top().second <= cap) {
                pbox += pick.top().second;
                pick.pop();
            } else {
                pick.top().second -= (cap - pbox);
                pbox = cap;
            }
        }
    }

    return answer;
}
