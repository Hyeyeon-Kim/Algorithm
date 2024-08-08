#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    map<int,vector<int>> input;  //in, out
    int root;
    vector <int> answer(4, 0);
    
    for (auto edge : edges){
        if (input.find(edge[0]) == input.end())
            input.insert({edge[0], {0, 1}});
        else
            input[edge[0]][1] += 1;
        
        
        if (input.find(edge[1]) == input.end())
            input.insert({edge[1], {1, 0}});
        else
            input[edge[1]][0] += 1;
    }
    
    int shapeCnt = 0;
    
    for (auto a: input){
        if (a.second[0] == 0 && a.second[1] >= 2){
            root = a.first;
            shapeCnt = input[root][1];
            input.erase(root);
            answer[0] = root;
        }
    }
    
    for (auto edge : edges){
        if (edge[0] == root)
            input[edge[1]][0]--;
    }
    
    //막대 갯수
    for (auto a: input){
        if (a.second[0] == 0)
            answer[2]++;
    }
    
    //8자 갯수
    for (auto a: input){
        if (a.second[0] == 2 && a.second[1] == 2)
            answer[3]++;
    } 
    answer[1] = shapeCnt - (answer[2] + answer[3]);

    return answer;
}