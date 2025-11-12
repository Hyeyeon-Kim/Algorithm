#include <string>
#include <vector>
#include <iostream>
using namespace std;

int ctoi(char c){
    return c - '0';
}

int minute(string clock){
    int s =  (ctoi(clock[0]) * 10 + ctoi(clock[1])) * 60 + (ctoi(clock[3]) * 10 + ctoi(clock[4]));
    return s;
}

string itos(int cur){
    string str = "00:00";
    
    int m = cur / 60;
    int s = cur % 60;
    
    str[0] = (m / 10) + '0';
    str[1] = (m % 10) + '0';
    str[3] = (s / 10) + '0';
    str[4] = (s % 10) + '0';
    return str; 
}

int pre_move(int pos){
    if (pos < 10)
        return 0;
    else 
        return pos - 10;
}

int next_move(int pos, int video_len){
    if (pos + 10 > video_len)
        return video_len;
    else 
        return pos + 10;
}

int skip(int pos, int op_start, int op_end){
    // cout << op_start << ", " << op_end << "   ";
    // cout << pos << ", "<< itos(pos) << "     ";
    // cout << (op_start <= pos <= op_end) << "      ";

    
    if (op_start <= pos && pos <= op_end)
        return op_end;
    else
        return pos;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    int video = minute(video_len);
    int cur = minute(pos);
    int op_s = minute(op_start);
    int op_e =  minute(op_end);
    
    // cout << op_s << ", " << op_e << endl;
    cur = skip(cur, op_s, op_e);
    
    for (int i = 0  ; i < commands.size(); i++){
        
        if (commands[i] == "next"){
            cur = next_move(cur, video);
        }
        else if (commands[i] == "prev"){
            cur = pre_move(cur);
        }
        
         cur = skip(cur, op_s, op_e);
        
        // cout << cur << ", "<< itos(cur) << "     ";
        cout << itos(cur) << endl;
    }
    
    return itos(cur);
}