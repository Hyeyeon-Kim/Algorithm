#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    long long prefix[1002][1002]  = {0};
    
    for (int i = 0; i < skill.size(); i++){
        int type = skill[i][0];
        int r1 = skill[i][1] + 1;
        int c1 = skill[i][2] + 1;
        int r2 = skill[i][3] + 1;
        int c2 = skill[i][4] + 1;
        int degree = skill[i][5];
        
        if (type == 1){
            prefix[r1][c1] += -degree;
            prefix[r2+1][c1] += degree;
            prefix[r1][c2+1] += degree;
            prefix[r2+1][c2+1] += -degree;
        }
        else {
            prefix[r1][c1] += degree;
            prefix[r2+1][c1] += -degree;
            prefix[r1][c2+1] += -degree;
            prefix[r2+1][c2+1] += degree;
        }
    }
        
    for (int i = 1; i <= board.size(); i++){
        for (int j = 1; j <= board[0].size(); j++){
            prefix[i][j] += prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }    
    }
    
    int answer = 0;
    
    for (int i = 1; i <= board.size(); i++){
        for (int j = 1; j <= board[0].size(); j++){
            if (board[i-1][j-1] + prefix[i][j] > 0)
                answer++;
        }
    }

    return answer;
}