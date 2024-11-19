#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool com(pair<string, int> a,pair<string, int> b ){
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second > b.second;
}

int main()
{
    int n;

    cin >> n;

    map<string, int> student;

    for (int i =0 ;i < n; i++){
        string s;
        cin >> s;
        student.insert({s, 0});
    }

    for (int i = 0; i < n; i++)
    {
        string s;

        while (cin >> s){
            student[s]++;
        }
    }

    vector<pair<string, int>> studentVec(student.begin(), student.end());

    sort(studentVec.begin(), studentVec.end(), &com);

    for (auto iter : studentVec)
        cout << iter.first << " " << iter.second << endl;
}
