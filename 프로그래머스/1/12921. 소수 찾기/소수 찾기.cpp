#include <string>
#include <vector>

using namespace std;
bool gdc[1000001] = {0};

int solution(int n) {
    gdc[1] = true;
    
    for (int i = 1; i <= n; i++){
        if (gdc[i])
            continue;
        
        for (int j = 2; j * i <= n; j++)
            gdc[i*j] = true;
    }
    
    int answer = 0;
    
    for (int i = 1; i <= n; i++){
        if (gdc[i] == false)
            answer++;
    }

    return answer;
}