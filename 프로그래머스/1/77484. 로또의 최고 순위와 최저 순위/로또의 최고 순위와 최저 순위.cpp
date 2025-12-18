#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    int hit = 0;
    int blank = 0;
    int arr[46] = {0};
    
    for (int i = 0; i < 6; i++){
        if (lottos[i] == 0)
            blank++;
        arr[lottos[i]] = 1;
    }
    
    for (int i = 0; i < 6; i++){
        if (arr[win_nums[i]] == 1)
            hit++;
    }
    
    int worst = min(6, 7 - hit);
    int best = min(6, 7 - hit - blank);
    
    return {best, worst};
}