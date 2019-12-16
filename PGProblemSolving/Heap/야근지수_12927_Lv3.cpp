//
//  야근지수_12927_Lv3.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2019/12/09.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

// MARK: - 야근지수 Lv3

#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<long long, vector<long long>, less<long long>> PQ;
    for(int i=0; i<works.size(); i++) {
        PQ.push(works[i]);
    }
    
    while(n>0) {
        int topValue = int(PQ.top());
        if(topValue == 0) return 0;
        PQ.pop();
        PQ.push(topValue-1);
        n--;
    }
    
    while(!PQ.empty()) {
        answer += PQ.top() * PQ.top();
        PQ.pop();
    }
    
    return answer;
}
