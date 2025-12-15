#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>
using namespace std;

string solution(string X, string Y) {
    int xnum[10] = {0};
    int ynum[10] = {0};
    
    for (char n : X)
        xnum[n-'0']++;
    
    for (char n : Y)
        ynum[n-'0']++;
    
    bool can = false;
    
    string answer = "";
    for(int i = 9; i >= 0; i--){
        if (i == 0 && !can && xnum[i] != 0 && ynum[i] != 0){
            return "0";
        }
        else if (xnum[i] != 0 && ynum[i] != 0)
            can = true;
        
        int rep = min(xnum[i], ynum[i]);
        for (int j = 0 ; j < rep; j++)
            answer += i + '0';
    } 
    
    // size_t pos{};
    // quoted(answer);
    // int n = *(stoi(answer));
    // int i = stoi(answer, &pos);
    // cout << i;    
//     if (stoi(answer) == 0)
//         return "0";
    
    if (!can)
        return  "-1";
    return answer;
}