#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

vector<int> number(int n){
    vector <int> nums;
    
    for (int i = 1; i <= sqrt(n); i++){
        if (n % i == 0){
            nums.push_back(i);
            if (i != n / i)
                nums.push_back(n / i);
        }
    }
    return nums;
}

int solution(int num, int limit, int power) {
    int answer = 0;
    
    for (int i = 1; i <= num; i++){
        vector <int> nums = number(i);
        int powe = nums.size();
        
        if (powe > limit)
            answer += power;
        else
            answer += powe;
    }
    return answer;
}