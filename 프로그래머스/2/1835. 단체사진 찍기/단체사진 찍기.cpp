#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


int solution(int n, vector<string> data) {
    string ch = "ACFJMNRT";
    int ans = 0;
    
    do{
        bool ok = true;
        
        for (auto d : data){
            int dist = abs((int)ch.find(d[0]) - (int)ch.find(d[2])) - 1; 
            
            char o = d[3];
            int num = d[4] - '0';
            
            if (o == '=' && dist != num){
                ok = false;
                break;
            }
            else if (o == '<' && dist >= num){
                ok = false;
                break;
            }
            else if (o == '>' && dist <= num){
                ok = false;
                break;
            }
        }
        
        if (ok)
            ans++;
    }
    while(next_permutation(ch.begin(), ch.end()));
    
    return ans;
}