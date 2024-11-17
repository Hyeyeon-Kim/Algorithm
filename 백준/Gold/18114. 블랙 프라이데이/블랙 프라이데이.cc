#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int n, c;
int arr[5001];
set<int> s;

bool solve() {
    // Step 1: 정렬
    sort(arr, arr + n);

    // Step 2: 하나의 숫자로 만족하는지 확인
    if (s.find(c) != s.end()) 
        return true;


    // Step 3: 두 숫자의 합으로 만족하는지 확인
    for (int i = 0; i < n; i++) {
        int target = c - arr[i];
        if (s.find(target) != s.end() && target != arr[i]) 
            return true;
    }

    // Step 4: 세 숫자의 합으로 만족하는지 확인
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // c - (arr[i] + arr[j])를 찾기 위해 이진 탐색
            int target = c - (arr[i] + arr[j]);
            if (s.find(target) != s.end() && target != arr[i] && target != arr[j]) 
                return true;
        }
    }

    return false;
}

int main() {
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        s.insert(arr[i]);
    }

    if (solve())
        cout << 1 << endl;
    else
        cout << 0 << endl;

    return 0;
}
