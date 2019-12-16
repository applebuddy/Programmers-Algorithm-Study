//
//  이중우선순위큐_42628_Lv3.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2019/11/17.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

/// MARK: - 이중 우선순위 큐_42628_Lv3

#if 0
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

priority_queue<int> maxPQ;
priority_queue<int, vector<int>, greater<int>> minPQ;
map<int,int> minMap;
map<int,int> maxMap;

void checkMaxPQ() {
    while(1) {
        if(maxPQ.empty()) break;
        if(maxMap[maxPQ.top()]>0) {
            maxMap[maxPQ.top()]--;
            maxPQ.pop();
        } else break;
    }
}

void checkMinPQ() {
    while(1) {
        if(minPQ.empty()) break;
        if(minMap[minPQ.top()]>0) {
            minMap[minPQ.top()]--;
            minPQ.pop();
        } else break;
    }
}

vector<int> solution(vector<string> operations) {
    vector<int> answer(2,0);

    for(int i=0; i<operations.size(); i++) {
        string opStr = operations[i];
        checkMinPQ();
        checkMaxPQ();
        int val = stoi(opStr.substr(2,opStr.length()-2));
        if(opStr[0]=='I') {
            maxPQ.push(val);
            minPQ.push(val);
        } else {
            if(val==1) {
                if(maxPQ.empty()) continue;
                minMap[maxPQ.top()]++;
                maxPQ.pop();
            } else {
                if(minPQ.empty()) continue;
                maxMap[minPQ.top()]++;
                minPQ.pop();

            }
        }
    }

    checkMinPQ();
    checkMaxPQ();

    answer[0] = maxPQ.empty() ? 0 : maxPQ.top();
    answer[1] = minPQ.empty() ? 0 : minPQ.top();
    return answer;
}
#endif
