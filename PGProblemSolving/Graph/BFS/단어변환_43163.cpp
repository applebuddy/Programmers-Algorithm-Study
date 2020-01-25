//
//  단어변환_43163.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 08/11/2019.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

/// MARK: 단어변환 Lv3

// MARK: - 단어변환 DFS사용 문제풀이
#if 0
#include <string>
#include <vector>
#include <map>

using namespace std;

int answer = 0;
map<string,int> MP;

bool checkOneDiff(string now, string next) {
    int diff = 0;
    for(int i=0; i<now.length(); i++) {
        if(now[i] != next[i]) diff++;
        if(diff > 1) return false;
    }
    return diff == 1;
}

void DFS(string now, int count, string target, vector<string> words) {
    if(now == target) {
        answer = count;
        return;
    }
    
    for(int i=0; i<words.size(); i++) {
        if(MP[words[i]]!=0 || checkOneDiff(now, words[i])==false) continue;
        MP[words[i]]=1;
        DFS(words[i], count+1, target, words);
        MP[words[i]]=0;
    }
    
}

int solution(string begin, string target, vector<string> words) {
    DFS(begin, 0, target, words);
    return answer;
}
#endif

// MARK: - Set, BFS 사용 문제풀이 (DFS보다 빠름)
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
