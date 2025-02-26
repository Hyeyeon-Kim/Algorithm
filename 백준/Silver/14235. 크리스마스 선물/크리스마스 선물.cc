#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;

    cin >> n;

    priority_queue<int> pq;

    while (n--){
        int a; 

        cin >> a;

        if (a == 0){
            if (pq.empty())
                cout << -1 << "\n";
            else{
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else{
            for (int i = 0; i < a; i++){
                int num;
                cin >> num;
                pq.push(num);
            }
        }
    }
}