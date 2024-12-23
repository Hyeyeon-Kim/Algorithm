#include <iostream>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    int N = 0, K = 0;    //학생의 수, 좋은 친구가 되는 조건(K)
    int friends[1000000];
    int cnt[23]={0,};	//이름의 길이 배열
    string friend1 = "";
    long long ans = 0;    //좋은 친구쌍의 수

    cin>>N>>K;
    for(int i=1; i<=N; i++){
        cin>>friend1;
        friends[i] = friend1.size();
    }

	//처음에는 겹치는 부분을 고려하지 않고, 1등부터 K+1등까지 길이를 cnt배열에 개수를 넣는다.
    for(int i=1; i<=K+1; i++){
        cnt[friends[i]]++;
    }
    
    //겹치는 부분을 고려하여, 윈도우의 끝에 추가될 friends[i+k+1]만 추가해준다.
    for(int i=1; i<=N; i++){
        cnt[friends[i]]--;	//자기 자신의 길이는 제외한다.
        ans += cnt[friends[i]];	//좋은 친구쌍의 수을 더해준다.
        cnt[friends[i+K+1]]++;	//슬라이딩 윈도우를 오른쪽으로 이동시킨다.
    }
    cout<<ans<<"\n";
}