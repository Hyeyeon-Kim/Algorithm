#include <string>
#include <vector>
#include <iostream>
#include <string>
using namespace std;


string binary(int num, int n){
    string s = "";
    
    while (num){
        char c = (num % 2) ? '#': ' '; 
        s = c + s; 
        num /= 2;
    }
    if (s.size() == n)
        return s;
    s.insert(0, n - s.size() , ' ');
    return s;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2){
    vector<string> answer(arr1.size());
    // cout << binary(2);
    
    for (int i = 0; i < arr1.size(); i++){
        arr1[i] |= arr2[i]; 
        answer[i] = binary(arr1[i], arr1.size());
    }
    
    return answer;
}

/*
32 16 8 4 2 1
0  1  1 1 1 0
*/