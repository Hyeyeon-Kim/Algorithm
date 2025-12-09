#include <string>
#include <vector>
#include <deque>
#include <iostream>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    deque<string> card1(cards1.begin(), cards1.end()); 
    deque<string> card2(cards2.begin(), cards2.end()); 

    for (string s: goal){
        if (!card1.empty() && s == card1.front()){
            card1.pop_front();
        }
        else if (!card2.empty() && s == card2.front())
            card2.pop_front();
        else
            return "No";
    }
    
    return "Yes";
}