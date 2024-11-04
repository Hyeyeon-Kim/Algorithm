#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> best_arrow;
int max_diff = -1;

void back(int idx, int cnt, int n, vector<int>& arrow, vector<int>& info) {
    if (cnt > n) return; // 화살 개수를 초과하면 반환

    if (idx == 11) {
        if (cnt != n) return; // 남은 화살이 있을 때 반환

        int rion = 0;
        int apeach = 0;

        // 점수 계산
        for (int i = 0; i <= 10; i++) {
            if (arrow[i] > info[i]) 
                rion += (10 - i);
            else if (info[i] > 0) 
                apeach += (10 - i);
        }

        int diff = rion - apeach;
        if (diff > max_diff) {
            max_diff = diff;
            best_arrow = arrow;
        }
        else if (diff == max_diff && max_diff != -1) {
            for (int i = 10; i >= 0; i--) {
                if (arrow[i] > best_arrow[i]) {
                    best_arrow = arrow;
                    break;
                } else if (arrow[i] < best_arrow[i]) 
                    break;
            }
        }
        return;
    }
    
    for (int i = n - cnt; i >= 0; i--) {
        arrow[idx] = i;
        back(idx + 1, cnt + i, n, arrow, info);
        arrow[idx] = 0; 
    }
}

vector<int> solution(int n, vector<int> info) {
    vector<int> arrow(11, 0);
    back(0, 0, n, arrow, info);

    if (max_diff <= 0)
        return {-1};
    return best_arrow;
}
