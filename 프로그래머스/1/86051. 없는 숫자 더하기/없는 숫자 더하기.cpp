#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int num[10] = {0};
    int answer = 0;
    
    for (int n: numbers){
        num[n] = 1;
    }
    
    for (int i = 0; i < 10; i++)
        if (num[i] == 0)
            answer += i;
    return answer;
}