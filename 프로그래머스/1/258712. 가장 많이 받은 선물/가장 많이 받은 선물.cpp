#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    map <string, int> freIdx;
    vector <vector <int> > giftSum(friends.size(), vector <int>(friends.size(), 0));
    vector <pair<int, int>> giftScore(friends.size());
    
    for (int i = 0; i < friends.size(); i++)
        freIdx.insert({friends[i], i});
    
    for (int i = 0 ; i < gifts.size(); i++)
    {
        stringstream ss(gifts[i]);
        string s;
        
        ss >> s;
        int a = freIdx[s];
        ss >> s;
        int b = freIdx[s];

        giftSum[a][b]++;
        giftScore[a].first++;
        giftScore[b].second++;
    }
    
    vector <int> ans(friends.size());
    
    for (int a = 0; a < friends.size(); a++)
    {
        for (int b = a+1; b < friends.size(); b++)
        {
            int taker = 51;
            
            if (a == b)
                continue;
            int out = giftSum[a][b];
            int in = giftSum[b][a];
            
            if (in < out)
                taker = a;
            else if (in > out)
                taker = b;
            else{
                if (giftScore[a].first - giftScore[a].second > giftScore[b].first - giftScore[b].second)
                    taker = a;
                else if (giftScore[a].first - giftScore[a].second < giftScore[b].first - giftScore[b].second)
                    taker = b;
            }
            if (taker != 51)
                ans[taker]++;
        }
    }
    
//     for (int i = 0; i < friends.size(); i++)
//     {
//         for (int j = 0; j < friends.size(); j++)
//             cout << giftSum[i][j]<< " ";
//         cout << endl;
//     }
    
    int answer = 0;
    
    for (int i = 0; i < friends.size(); i++)
    {
        if (ans[i] > answer)
                answer = ans[i];
        // cout << ans[i] << endl;
        // cout << giftScore[i].first << " " << giftScore[i].second << endl;
    }
    return answer;
}

// 조건 1
// 두 사람이 선물을 주고받은 기록이 있다면, 이번 달까지 두 사람 사이에 더 많은 선물을 준 사람이 다음 달에 선물을 하나 받습니다.
// 조건 2
// 두 사람이 선물을 주고받은 기록이 하나도 없거나 주고받은 수가 같다면, 선물 지수가 더 큰 사람이 선물 지수가 더 작은 사람에게 선물을 하나 받습니다.