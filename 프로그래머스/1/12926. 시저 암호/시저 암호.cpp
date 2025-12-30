#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for (char c : s){
        if (c >= 'A' && c <= 'Z')
            c = ((c - 'A') + n) % 26 + 'A';
        else if (c >= 'a' && c <= 'z')
            c = ((c - 'a') + n) % 26 + 'a';
        answer += c;
    }
    return answer;
}