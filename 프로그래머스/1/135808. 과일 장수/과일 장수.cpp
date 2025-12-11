#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int k, int m, vector<int> score) {
    sort(score.begin(), score.end(), greater<int>());
    int answer = 0;
    
    for (int i = 0; i < score.size(); i += m){
        
        int apple = 100;
        if (i + m > score.size())
            continue;
        
        for (int j = 0; j < m; j++){
            apple = min(score[i + j], apple);
        }
        // cout << endl;
        answer += apple * m;
    }
    

    return answer;
}