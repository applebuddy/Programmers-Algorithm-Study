//
//  가장 먼 노드.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 10/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

// MARK: 가장먼노드 Lv3

// MARK: - BFS 문제풀이
#if 0
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> C(20001, 0);
vector<int> G[20001];
int Max = 0;

void BFS(int node) {
    queue<int> Q;
    Q.push(node);
    while(!Q.empty()) {
        int nowNode = Q.front();
        Q.pop();
        for(int i=0; i<G[nowNode].size(); i++) {
            int nextNode = G[nowNode][i];
            if(C[nextNode]>0) continue;
            C[nextNode] = C[nowNode] + 1;
            Max = Max < C[nextNode] ? C[nextNode] : Max;
            Q.push(nextNode);
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for(auto &v: edge) {
        G[v[0]].push_back(v[1]);
        G[v[1]].push_back(v[0]);
    }
    
    C[1] = 1;
    BFS(1);
    for(int i=1; i<=n; i++) if(C[i]==Max) answer++;
    return answer;
}
#endif
