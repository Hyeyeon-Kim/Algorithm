#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

vector<vector<int>> choiceDice(int dice_cnt, vector<int> visit, vector<int> choice, int cnt, vector<vector<int>> com){
    
    if (cnt == dice_cnt/2){
        com.push_back(choice);
        return com;
    }
    
    int start = (cnt == 0) ? 0 : choice[cnt - 1];
    
    for (int i = start; i < dice_cnt; i++){
        if (visit[i] == 0){
            visit[i] = 1;
            choice[cnt] = i;
            com = choiceDice(dice_cnt, visit, choice, cnt+1, com);
            visit[i] = 0;
        }
    }
    return com;
}

void combi(int sum, int max_cnt, int cnt, vector<vector<int>> dice, vector <int> dice_idx, vector <int> &com){
    if (cnt == max_cnt){
        com.push_back(sum);
        return ;
    }
    for (int i = 0; i < 6; i++)
        combi(sum+dice[dice_idx[cnt]][i], max_cnt, cnt + 1, dice, dice_idx, com);
}

void binarySearch(int target, int start, int end, vector<int>arr){
    
}

vector<int> score(vector<vector<int>> com, vector<vector<int>> dice){
    vector<vector<int>> vs_score(com.size(), vector<int>(2, 0)); 
    
    for (int i = 0; i < com.size()/2; i++){  //a, b dice 나누기
        vector <int> a_dice = com[i];
        vector <int> b_dice = com[com.size()-1-i];
        vector <int> tmp;
        
        vector <int> a_score, b_score;
        
        combi(0, a_dice.size(), 0, dice, a_dice, a_score);
        combi(0, b_dice.size(), 0, dice, b_dice, b_score);
        
        sort(a_score.begin(), a_score.end());
        sort(b_score.begin(), b_score.end());
        
        
        // 2, 2, 4, 4, 6, 6
        // 1, 2, 3, 4, 5, 6
        
        // vector <int> pre_score(3, 0);
        
        int pre_idx = 0;

        for (int j = 0; j < a_score.size(); j++){
            int draw = -1;
            
            for (int k = 0; k < b_score.size(); k++){
                if (k == b_score.size()-1){
                    if (draw != -1)
                        vs_score[i][0] += draw;
                    else if (a_score[j] > b_score[k])
                        vs_score[i][0] += b_score.size();
                    else
                        vs_score[i][0] += k;
                }
                else if (a_score[j] < b_score[k]){
                    if(draw == -1)
                        vs_score[i][0] += k;
                        // cout << k << " ";
                    else
                        vs_score[i][0] += draw;
                        // cout << draw << " ";
                    vs_score[i][1] += b_score.size() - k;
                    pre_idx = k;
                    break;
                }
                else if (a_score[j] == b_score[k]){
                    if (draw == -1)
                        draw = k;
                }
            }
        }
    }
    
        for (int i = 0; i < com.size()/2; i++)
            vs_score[com.size()-1-i][0] = vs_score[i][1];

        int max_score = 0, max_idx = 0;

    cout << endl;
        for (int i = 0; i < com.size(); i++){
            if (max_score < vs_score[i][0]){
                max_score = vs_score[i][0];
                max_idx = i;
            }
            // cout << vs_score[i][0] << endl;
        }

        vector<int> ans;

        for(int i = 0; i < com[max_idx].size(); i++)
            ans.push_back(com[max_idx][i]+1);
        return ans;
}

vector<int> solution(vector<vector<int>> dice) {
    
    vector<int> visit(dice.size());
    vector<int> choice(dice.size()/2);
    vector<vector<int>> com;
    vector<vector<int>> tmp;
    
    tmp = choiceDice(dice.size(), visit, choice, 0, com);

    return score(tmp, dice);
}