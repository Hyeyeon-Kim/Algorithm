#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int n = board.size();
    vector<stack<int>> mashin(n+1);
    stack<int>bucket; 
    int tmp[5][5] = {0};
        
    for (int i = 0; i < n; i++){
        for (int j = n-1; j >= 0; j--){
            if (board[j][i] == 0)
                continue;
            mashin[i+1].push(board[j][i]);
        }
    }
    
    int answer = 0;
    
    // for (int i = 1; i <= n; i++){
    //     while (!mashin[i].empty()){
    //         cout << mashin[i].top() << " ";
    //         mashin[i].pop();
    //     }
    //     cout << endl;
    // }
    
    /*
    [1,5,3,5,1,2,1,4]
    
    [0,0,0,0,0]
    [0,0,1,0,3]
    [0,2,5,0,1]
    [4,2,4,4,2]
    [3,5,1,3,1]
    
    2
    4
*/
    
    for (int move : moves){
        if (mashin[move].empty())
            continue;
        int type = mashin[move].top();
        
        mashin[move].pop();
        
        // cout << type << "    ";
        
        // while ()
        
        if (bucket.empty()){
            // cout << "empty\n";
            bucket.push(type);
            continue;
        }
        
        // cout << bucket.top() << " ";
        if (bucket.top() == type){
            answer++;
            bucket.pop();
            // cout << endl;
            continue;
            // cout << bucket.top() << " "<< answer << " ";
        }
        // cout << endl;/
        bucket.push(type);
    }

    return answer*2;
}