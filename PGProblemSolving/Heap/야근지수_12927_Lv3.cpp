//
//  야근지수_12927_Lv3.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2019/12/09.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

// MARK: 야근지수 Lv3

// MARK: - 야근지수 복습풀이
#if 0
#include <string>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<ll> PQ;
    for(int i=0; i<works.size(); i++) PQ.push(works[i]);
    for(int i=0; i<n; i++) {
        PQ.push(PQ.top()-1);
        PQ.pop();
        if(PQ.top()==0) return 0;
    }
    
    while(!PQ.empty()) {
        answer += PQ.top() * PQ.top();
        PQ.pop();
    }
    
    return answer;
}
#endif

#if 0
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
#endif
