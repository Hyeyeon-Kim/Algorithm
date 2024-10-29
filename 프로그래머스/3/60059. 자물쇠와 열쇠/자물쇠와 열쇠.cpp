#include <string>
#include <vector>
#include <iostream>
using namespace std;

int n, m, slot = 0;
vector<vector<int>> Lock;

// 자물쇠에 열쇠가 맞는지 확인하는 함수
bool check(vector<vector<int>> &lock) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (lock[n + i][n + j] != 1) // 모든 부분이 1이어야 맞는 상태
                return false;
        }
    }
    return true;
}

// 열쇠를 90도 회전시키는 함수
vector<vector<int>> rotateKey(vector<vector<int>> &key) {
    vector<vector<int>> rotated(m, vector<int>(m, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            rotated[j][m - 1 - i] = key[i][j];
        }
    }
    return rotated;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    n = lock.size();
    m = key.size();
    
    // 자물쇠를 3배 크기로 확장하여 가운데에 배치
    vector<vector<int>> expandedLock(n * 3, vector<int>(n * 3, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            expandedLock[n + i][n + j] = lock[i][j];
        }
    }
    
    // 열쇠를 4가지 회전 상태로 탐색
    for (int rotation = 0; rotation < 4; rotation++) {
        key = rotateKey(key); // 열쇠를 회전
        
        // 열쇠를 자물쇠 위에 모든 위치에 대해 시도
        for (int x = 0; x <= n * 2; x++) {
            for (int y = 0; y <= n * 2; y++) {
                
                // 열쇠를 현재 위치에 더하기
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < m; j++) {
                        expandedLock[x + i][y + j] += key[i][j];
                    }
                }
                
                // 자물쇠가 열리는지 확인
                if (check(expandedLock))
                    return true;
                
                // 열쇠를 뺀다 (원래 상태로 복구)
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < m; j++) {
                        expandedLock[x + i][y + j] -= key[i][j];
                    }
                }
            }
        }
    }
    
    return false; // 열쇠가 맞지 않으면 false
}
