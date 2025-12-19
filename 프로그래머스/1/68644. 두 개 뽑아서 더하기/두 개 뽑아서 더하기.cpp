#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

vector<int> solution(vector<int> numbers) {
    set <int> s;
    
    for (int i = 0; i < numbers.size(); i++){
        for (int j = i + 1; j < numbers.size(); j++){
            s.insert(numbers[i] + numbers[j]);
        }
    }
    return vector<int>(s.begin(), s.end());
}