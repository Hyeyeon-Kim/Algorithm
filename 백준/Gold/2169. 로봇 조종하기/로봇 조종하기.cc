#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int map[1000][1001]; // 점수 맵
int dp[1000][1001];  // dp 테이블 (최대 점수 저장)

// 왼쪽, 오른쪽 계산을 위한 배열
int left_dp[1000][1001], right_dp[1000][1001];

int main() {
    // 입력 받기
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];

    // 첫 번째 행은 직접 초기화
    dp[0][0] = map[0][0];
    for (int j = 1; j < m; j++) {
        dp[0][j] = dp[0][j - 1] + map[0][j];
    }

    // 두 번째 행부터는 위, 왼쪽, 오른쪽을 고려하여 처리
    for (int i = 1; i < n; i++) {
        // 왼쪽에서 오른쪽으로 가는 경로 계산
        left_dp[i][0] = dp[i-1][0] + map[i][0];
        for (int j = 1; j < m; j++) {
            left_dp[i][j] = max(left_dp[i][j - 1], dp[i - 1][j]) + map[i][j];
        }

        // 오른쪽에서 왼쪽으로 가는 경로 계산
        right_dp[i][m - 1] = dp[i - 1][m - 1] + map[i][m - 1];
        for (int j = m - 2; j >= 0; j--) {
            right_dp[i][j] = max(right_dp[i][j + 1], dp[i - 1][j]) + map[i][j];
        }

        // 왼쪽, 오른쪽을 비교하여 dp 갱신
        for (int j = 0; j < m; j++) {
            dp[i][j] = max(left_dp[i][j], right_dp[i][j]);
        }
    }

    // 최종적으로 (n-1, m-1) 위치에 도착할 때의 최대 점수 출력
    cout << dp[n-1][m-1] << endl;

    return 0;
}
