#include <string>
#include <vector>
#include <iostream>
using namespace std;

int toint(char a, char b) {
    return (a - '0') * 10 + (b - '0');    
}

string solution(string play_time, string adv_time, vector<string> logs) {
    vector<long long> dp(360000, 0);
    
    for (int i = 0; i < logs.size(); i++) {
        int start = (toint(logs[i][0], logs[i][1]) * 3600) + (toint(logs[i][3], logs[i][4]) * 60) + toint(logs[i][6], logs[i][7]);
        int end = (toint(logs[i][9], logs[i][10]) * 3600) + (toint(logs[i][12], logs[i][13]) * 60) + toint(logs[i][15], logs[i][16]);
        dp[start]++;
        dp[end]--;
    }

    int adv = (toint(adv_time[0], adv_time[1]) * 3600) + (toint(adv_time[3], adv_time[4]) * 60) + toint(adv_time[6], adv_time[7]);

    // 누적 시청자 수 계산
    for (int i = 1; i < 360000; i++)
        dp[i] += dp[i - 1];

    // 누적 시청 시간 계산
    for (int i = 1; i < 360000; i++)
        dp[i] += dp[i - 1];

    long long max_time = dp[adv - 1];
    int start_time = 0;

    // 최적의 광고 시작 시간 찾기
    for (int i = adv; i < 360000; i++) {
        long long tmp = dp[i] - dp[i - adv];
        if (tmp > max_time) {
            max_time = tmp;
            start_time = i - adv + 1;
        }
    }

    // 시간을 포맷팅하여 반환
    int h = start_time / 3600;
    int m = (start_time % 3600) / 60;
    int s = start_time % 60;
    char buffer[9];
    sprintf(buffer, "%02d:%02d:%02d", h, m, s);

    return string(buffer);
}
