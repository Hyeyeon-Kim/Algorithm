#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

bool sosu(int num){
    vector <int> arr;
    
    for (int i = 1; i <= sqrt(num); i++){
        if (num % i != 0)
            continue;
        arr.push_back(i);
        if (i != num / i)
            arr.push_back(num / i);
    }
    cout << arr.size() << " " << num << "\n";
    
//     for (int i : arr)
//         cout << i << " " << endl;
    return arr.size() == 2;
}

int solution(vector<int> nums) {
    int answer = 0;

    for (int i = 0; i < nums.size(); i++){
        for (int j = i + 1; j < nums.size(); j++){
            for (int k = j + 1; k < nums.size(); k++){
                if(sosu(nums[i] + nums[j] + nums[k]))
                    answer++;
            }
        }
    }

    return answer;
}