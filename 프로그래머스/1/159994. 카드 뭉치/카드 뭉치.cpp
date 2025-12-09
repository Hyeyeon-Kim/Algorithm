#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    
    stack<string> card1; 
    
    for (int  i = cards1.size()-1; i >= 0; i--)
        card1.push(cards1[i]);
    
    stack<string> card2; 
    
    for (int  i = cards2.size()-1; i >= 0; i--)
        card2.push(cards2[i]);
    
    // while(!card1.empty()){
    //     string s = card1.top();
    //     cout << s <<  " ";
    //     card1.pop();
    // }
    
    for (string s: goal){
        if (!card1.empty() && s == card1.top()){
            card1.pop();
        }
        else if (!card2.empty() && s == card2.top())
            card2.pop();
        else
            return "No";
    }
    
    return "Yes";
}