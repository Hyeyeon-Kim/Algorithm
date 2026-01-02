#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool gdc(int num){
    int cnt = 0;
    
    for (int i = 1; i * i <= num; i++){
        if (num % i == 0){
            cnt++;
        if (num / i != i)
            cnt++;
        }
    }
    return cnt % 2 == 0;
} 

int solution(int left, int right) {
    int answer = 0;
    
    for (int i = left; i <= right; i++){
        if (gdc(i))
            answer += i;
        else
            answer -= i;
    }
    return answer;
}