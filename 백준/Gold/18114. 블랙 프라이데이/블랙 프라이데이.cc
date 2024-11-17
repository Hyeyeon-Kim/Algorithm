#include <iostream>
#include <algorithm>
using namespace std;

int n, c;
int arr[5001];

bool solve() {
    // Step 1: 정렬
    sort(arr, arr + n);

    // Step 2: 하나의 숫자로 만족하는지 확인
    for (int i = 0; i < n; i++) {
        if (arr[i] == c) return true;
    }

    // Step 3: 두 숫자의 합으로 만족하는지 확인
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == c) return true;
        }
    }

    // Step 4: 세 숫자의 합으로 만족하는지 확인
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // c - (arr[i] + arr[j])를 찾기 위해 이진 탐색
            int target = c - (arr[i] + arr[j]);
            if (binary_search(arr + j + 1, arr + n, target)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (solve())
        cout << 1 << endl;
    else
        cout << 0 << endl;

    return 0;
}
