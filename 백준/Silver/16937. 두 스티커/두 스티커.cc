#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int max_ = 0;
int h, w, n;
vector<pair<int, int>> sticker;

int main() {
    cin >> h >> w;
    cin >> n;
    sticker.resize(n);

    for (int i =0 ; i < n; i++){
        int r, c;

        cin >> r >> c;
        sticker[i].first = r;
        sticker[i].second = c;
    }

    int result = 0;
    for (int i =0 ; i < n; i++){
        for (int j = i+1; j < n; j++){
            int r1 = sticker[i].first;
            int c1 = sticker[i].second;
            int r2 = sticker[j].first;
            int c2 = sticker[j].second;
            
            // 둘 다 회전
            if ((c1 + c2 <= h && max(r1, r2) <= w) || ((max(c1, c2) <= h && r1 + r2 <= w)))
                result = max(result, r1*c1 + r2*c2);
            
            // i만 회전
            if ((c1 + r2 <= h && max(r1, c2) <= w) || (max(c1, r2) <= h && r1 + c2 <= w))
                result = max(result, r1*c1 + r2*c2);
            
            // j만 회전
            if ((r1 + c2 <= h && max(c1, r2) <= w) || (max(r1, c2) <= h && c1 + r2 <= w))
                result = max(result, r1*c1 + r2*c2);

            // 둘 다 안 함
            if ((r1 + r2 <= h && max(c1, c2) <= w) || (max(r1, r2) <= h && c1 + c2 <= w))
                result = max(result, r1*c1 + r2*c2);
        }
    }
    cout << result;
}   
