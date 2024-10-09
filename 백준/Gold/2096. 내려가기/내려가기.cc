#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int input[3] = {0};
int min_[3] = {0};
int max_[3] = {0};

int main() {
    int n;

    cin >> n;

    cin >> input[0] >> input[1] >> input[2];
    max_[0] = input[0];
    max_[1] = input[1];
    max_[2] = input[2];

    min_[0] = input[0];
    min_[1] = input[1];
    min_[2] = input[2];
    
    for (int i = 1; i < n; i++){
        cin >> input[0] >> input[1] >> input[2];

        int a[3] = {0};
        a[0] = max(max_[0], max_[1]); 
        a[1] = max(max(max_[0], max_[2]), max_[1]);
        a[2] = max(max_[1], max_[2]);

        max_[0] = input[0] + a[0];
        max_[1] = input[1]+ a[1];
        max_[2] = input[2]+ a[2];

        a[0] = min(min_[0], min_[1]);
        a[1] = min(min(min_[0], min_[2]), min_[1]);
        a[2] = min(min_[1], min_[2]);
     
        min_[0] = input[0]+ a[0];
        min_[1] = input[1]+ a[1];
        min_[2] = input[2]+ a[2];

        // cout << min_[0] << " " << min_[1] << " " << min_[2] << "    ";
        // cout << max_[0] << " " << max_[1] << " " << max_[2] << endl;
    }


    cout << max(max(max_[0], max_[1]), max_[2]);
    cout << " " << min(min(min_[0], min_[1]), min_[2]);
}   
