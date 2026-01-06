#include <string>
#include <vector>
#include <iostream>
using namespace std;

int change(string s){
    return ((s[0] - '0') * 10 + (s[1] - '0')) * 60 + (s[3] - '0') * 10 + (s[4] - '0');
}

string re(int num){
    string ss = "     ";
    int m = num / 60;
    int s = num % 60;
    
    ss[0] = m / 10 + '0';
    ss[1] = m % 10 + '0';
    ss[2] = ':';
    ss[3] = s / 10 + '0';
    ss[4] = s % 10 + '0';
    return ss;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    
    int cur = change(pos);
    int end = change(video_len);
    int os = change(op_start);
    int oe = change(op_end);
    
    for (string c : commands){
        if (cur >= os && cur <= oe){
            cur = oe;
        }
            
        if (c == "prev"){
            if (cur - 10 <= 0)
                cur = 0;
            else
                cur -= 10;
        }
        else {
            if (cur + 10 >= end)
                cur = end;
            else
                cur += 10;
        }
    }
    
    if (cur >= os && cur <= oe){
        cur = oe;
    }
    
    return re(cur);
}