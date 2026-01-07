#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int cur = health;
    
    int idx = 0;
    int suc = 0;
    
    for (int i = 0; i <= attacks[attacks.size()-1][0] ; i++){
        // cout << cur << "  ";
        if (attacks[idx][0] == i){
            cur -= attacks[idx][1];
            idx++;
            suc = 0;
        }
        else{
            cur += bandage[1];
            suc++;
            if (suc == bandage[0]){
                cur += bandage[2];
                suc = 0;
            }
        }
        
        if (cur <= 0)
            return -1;
    
        if (cur > health)
            cur = health;
        // cout << cur << "\n";
    }
    return cur;
}