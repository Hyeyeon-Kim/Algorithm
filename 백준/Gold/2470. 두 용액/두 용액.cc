#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool com(int a, int b){
    return a > b;
}

int main(){
    int n;
    cin >> n;

    vector <int> input(n);

    for (int i =0 ; i < n; i++)
        cin >> input[i];
    
    sort(input.begin(), input.end());

    int s = 0, e = n-1;
    long long ans = 2147483647;
    pair<int, int> solution;

    while (s < e){
        long long sum = input[s]+input[e];

        if (abs(sum) < ans){
            ans = abs(sum);
            solution = {input[s], input[e]};
        }

        if (sum == 0) {
            break;
        }

        else if (sum > 0)
            e--;
        else
            s++;
    }

   cout << solution.first << " " << solution.second << endl;

}




