//
//  가장먼노드_49189_Lv3.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 08/10/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

/// MARK: - 가장 먼 노드_49189_Lv3

#if 0
#include <string>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;
vector<int> G[20001];
int C[20001];

void BFS(int N) {
    queue<int> Q;
    C[N]=1;
    Q.push(N);
    while(!Q.empty()) {
        int node = Q.front();
        Q.pop();
        for(int i=0; i<G[node].size(); i++) {
            int next = G[node][i];
            if(C[next]==0) {
                C[next]=C[node]+1;
                Q.push(next);
            }
        }
    }
    return;
}

int theFarthestNode(int n, vector<vector<int>> edge) {
    memset(C,0,sizeof(C));
    int answer = 0;
    
    for(int i=0; i<edge.size(); i++) {
        int a = edge[i][0];
        int b = edge[i][1];
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    BFS(1);
    int MAX = *max_element(C,C+n+1);
    for(int i=1; i<=n; i++) if(C[i]==MAX) answer++;
    
    return answer;
}
#endif
