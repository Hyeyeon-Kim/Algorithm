#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int t;

    cin >> t;

    while (t--){
    int alpha[26] = {0};
    vector <vector<int>> v(26);
    string s;
    int k;

    cin >> s;
    cin >> k;

    for (int i = 0; i < s.length(); i++){
        alpha[s[i] - 'a']++;
        v[s[i] - 'a'].push_back(i);
    }

    int min_ = 10001;
    int max_ = 0;

    bool check = false;

    for (int i =0; i < 26; i++){
        if (alpha[i] == k){
            int len = v[i][v[i].size()-1]- v[i][0] + 1;

            check = true;
            if (len < min_)
                min_ = len;
            if(len > max_)
                max_ = len;
        }
        else if(alpha[i] > k){
            for (int j = 0; j < alpha[i]-(k-1); j++){
                int len = v[i][j+(k-1)]- v[i][j] + 1;

            check = true;
                if (len < min_)
                    min_ = len;
                if(len > max_)
                    max_ = len;
            }
        }
    }

    if (check)
        cout << min_ << " " << max_ << "\n";
    else
        cout << -1 << "\n";
    }
}

// 100*
// 1000/ 