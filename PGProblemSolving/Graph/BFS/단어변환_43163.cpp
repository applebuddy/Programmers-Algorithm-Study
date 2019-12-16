//
//  단어변환_43163.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 08/11/2019.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

/// MARK: - 단어변환
#if 0
#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef pair<string,int> Pair;

bool compare(string s, string s2) {
    int cnt=0;
    for(int i=0; i<s.length(); i++) {
        if(s[i]!=s2[i]) cnt++;
    }
    return cnt==1;
}

int solution(string begin, string target, vector<string> words) {
    queue<Pair> Q;
    Q.push({begin,0});
    set<string> ST(words.begin(), words.end());
    while(!Q.empty()) {
        string node = Q.front().first;
        int score = Q.front().second;
        Q.pop();
        if(node == target) return score;
        for(auto s: ST) {
            if(compare(node,s)) {
                Q.push({s,score+1});
                ST.erase(s);
            }
        }
    }
    
    return 0;
}
#endif
