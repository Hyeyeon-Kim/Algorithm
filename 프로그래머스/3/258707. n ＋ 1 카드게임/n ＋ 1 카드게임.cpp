#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <set>
using namespace std;

int round = 0;

void simulation(int n, int coin, queue<pair<int, int>> cards, set<int> myCard, vector<int> needCard, set<int> choiceCard){
    round++;
    
    if (cards.empty())
        return ;
     
    
    choiceCard.insert(cards.front().first);
    choiceCard.insert(cards.front().second);
    cards.pop();
    
    int spend = -1;
    
    for (auto c: myCard){
        auto it = myCard.find(n+1-c);

        if (it != myCard.end()){
            myCard.erase(myCard.find(c));
            myCard.erase(it);
            spend = 0;
            break;
        }
    }
    
    if (spend == -1 && coin - 1 >= 0){
        for (auto c: choiceCard){
            auto it = myCard.find(n+1-c);
            
            if (it != myCard.end()){
                choiceCard.erase(choiceCard.find(c));
                myCard.erase(it);
                spend = 1;
                break;
            }
        }
    }
    
    if (spend == -1 && coin - 2 >= 0){
        for (auto c: choiceCard){
            auto it = choiceCard.find(n+1-c);
            
            if (it != choiceCard.end()){
                choiceCard.erase(choiceCard.find(c));
                choiceCard.erase(it);
                spend = 2;
                break;
            }
        }
    }
    
    if (spend == -1)
        return ;
//     cout << coin << ": ";
    
//     for (auto c: choiceCard){
//         cout << c << " ";
//     }
//     cout << endl;
    
//     for (auto c: myCard){
//         cout << c << " ";
//     }
//     cout << endl << endl;

    simulation(n, coin-spend, cards, myCard, needCard, choiceCard);
}

int solution(int coin, vector<int> cards) {
    int n = cards.size();
    
    queue<pair<int, int>> cardOrder;
    for (int i = n/3; i < n; i += 2)
        cardOrder.push({cards[i], cards[i+1]});
    
    vector<int> needCard(n+1);
    set<int> myCard, choiceCard;

    for (int i = 0; i < n/3; i++){
        myCard.insert(cards[i]);
        needCard[cards[i]] = 1;
    }
    
    simulation(n, coin, cardOrder, myCard, needCard, choiceCard);
    
    return round;
}

//n 최대 996
// (n - n/3)/2 최대 332 라운드까지 진행