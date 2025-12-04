#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

// void swap (string *a, string *b){
//     string *tmp;
    
//     tmp = a;
//     a = b;
//     b = tmp;
// }

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> player_idx;
    
    for (int i = 0; i < players.size(); i++){
        player_idx.insert({players[i], i});
    }
    
    // swap(players[0], players[1]);
    
    // for (auto tmp : player_idx)
    //         cout << tmp.first << " " << tmp.second << "    ";
    //     cout << "\n";
    
    for (string str : callings){
        int idx = player_idx[str];
        // cout << str << " " << idx << "  ";
        
        if (idx != 0){
            
            
//             cout << players[idx] << " " << players[idx-1] << "    ";
            
//             cout << player_idx[str] << " " << player_idx[players[idx-1]] << "    ";
            
            player_idx[str] = idx - 1;
            player_idx[players[idx-1]] = idx;
            
            // cout << player_idx[str] << " " << player_idx[players[idx-1]] << "    ";
            
            swap(players[idx], players[idx-1]);
        }
        
        // for (auto tmp : player_idx)
        //     cout << tmp.first << " ";
        // cout << "    ";
        
        // for (string tmp : players)
        //     cout << tmp << " ";
        // cout << endl;
    }
    
    return players;
}