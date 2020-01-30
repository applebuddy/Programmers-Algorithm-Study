//
//  종이접기_62049_Lv3.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2019/11/16.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

/// MARK: 종기접기 Lv2 : 데칼코마니 수열 문제

// MARK: - 복습 문제풀이
#if 0
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer = {0};
    n--;
    while(n--) {
        vector<int> origin = answer;
        for(int i=0; i<origin.size(); i++) {
            origin[i] = origin[i]==0 ? 1 : 0;
        }
        reverse(origin.begin(), origin.end());
        answer.push_back(0);
        answer.insert(answer.end(), origin.begin(), origin.end());
    }
    return answer;
}
#endif

#if 0
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    answer.push_back(0);
    if(n==1) return answer;
    answer = {0,0,1};
    if(n==2) return answer;
    int cnt=3;
    while(1) {
        vector<int> rev = answer;
        reverse(rev.begin(),rev.end());
        for(int i=0; i<rev.size(); i++) rev[i] = rev[i]==0 ? 1 : 0;
        answer.push_back(0);
        answer.insert(answer.end(),rev.begin(),rev.end());
        if(n==cnt) break;
        cnt++;
    }
    return answer;
}
#endif
