#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string str)
{
    stack<int> s;
    
    for (char c : str){
        
        if (c == '(')
            s.push(c);
        else
        {
            if (s.empty())
                return false;
            else
                s.pop();
        }
    }
    
    if (s.empty())
        return 1;
    else 
        return 0;
}