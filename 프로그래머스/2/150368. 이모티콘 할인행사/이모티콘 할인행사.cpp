#include <string>
#include <vector>
#include <iostream>
using namespace std;

int m, n;
int discount [4] = {10, 20, 30, 40};
vector<int> decide;
vector<vector<int>> user;
vector<int> emoticon;

int max_plus = 0;
int max_profit = 0;

void user_check(){
    int plus = 0;
    int profit = 0;
    
    for (int i = 0; i < n; i++){
        int cost = 0;
        
        for (int j = 0 ; j < m; j++){
            if (user[i][0] <= decide[j]){
                cost += emoticon[j] * ((100-decide[j])*0.01);
            }
        }
        if (cost >= user[i][1])
            plus++;
        else
            profit += cost;
    }
    
    if (plus > max_plus){
        max_plus = plus;
        max_profit = profit;
    }
    else if (plus == max_plus && profit > max_profit)
        max_profit = profit;
}

void discount_decide(int cnt){
    if (m == cnt){
        user_check();
        return ;
    }
    
    for (int i = 0; i < 4; i++){
        decide[cnt] = discount[i];
        discount_decide(cnt + 1);
        decide[cnt] = 0;
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    n = users.size();
    m = emoticons.size();
    decide = vector<int>(m);
    user = users;
    emoticon = emoticons;
    
    discount_decide(0);

    return {max_plus, max_profit};
}