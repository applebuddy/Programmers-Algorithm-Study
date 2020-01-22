//
//  기능개발_42586.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 07/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

/// MARK: 기능개발 : Queue / Stack Problem

// MARK: - 기능개발 복습 풀이답안
#if 0
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int idx = 0;
    vector<int> Ans;
    vector<int> res(progresses.size(),0);
    for(int i=0; i<progresses.size(); i++) {
        res[i] = 100 - progresses[i];
    }
    
    while(idx < progresses.size()) {
        int cnt = 0;
        int now = (res[idx] - 1) / speeds[idx] + 1;
        while(res[idx] - speeds[idx] * now <= 0) {
            cnt++;
            idx++;
            if(idx >= progresses.size()) break;
        }
        Ans.push_back(cnt);
    }
    return Ans;
}
#endif

/// MARK: - 기능개발 : 단순 Queue를 사용한 문제풀이 : PASSED
#if 0
#include <string>
#include <vector>
#include <queue>

using namespace std;


vector<int> functionDevelopment2(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    
    for(int i=0; i<progresses.size(); i++) {
        if((100-progresses[i])%speeds[i] == 0) {
            q.push((100-progresses[i])/speeds[i]);
        } else {
            q.push((100-progresses[i])/speeds[i]+1);
        }
    }
    
    int pos = q.front();
    int cnt = 0;
    while(!q.empty()) {
        while(pos>=q.front() && !q.empty()) {
            q.pop();
            cnt++;
        }
        pos = q.front();
        answer.push_back(cnt);
        cnt=0;
    }
    
    return answer;
}
#endif

/// MARK: 기능개발 : queue<pair<int,int>> 를 사용한 풀이 : PASSED
#if 0
#include <string>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int,int> Pair;
vector<int> functionDevelopment2(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int day=0;
    queue<Pair> Q;
    for(int i=0; i<progresses.size(); i++) Q.push({progresses[i], speeds[i]});
    while(!Q.empty()) {
        int cnt=1;
        day = (100 - Q.front().first - 1) / Q.front().second + 1;
        Q.pop();
        while(1) {
            if(!Q.empty() && (100 - Q.front().first - 1) / Q.front().second + 1 <= day) {
                cnt++;
                Q.pop();
            } else break;
        }
        answer.push_back(cnt);
    }
    return answer;
}
#endif

#if 0
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> functionDevelopment(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<pair<int,int>> q;
    int day=1;
    for(int i=0; i<progresses.size(); i++){
        q.push(make_pair(progresses[i],speeds[i]));
    }
    
    while(!q.empty()){
        int count = 0;
        while(100 <= (q.front().first + q.front().second*day)){ // 맨앞의 큐값이 100%를 달성하면,
            q.pop();
            count++;
        }
        if(count!=0){
            answer.push_back(count);
            count=0;
        }
        day++;
    }
    
    return answer;
}
#endif
