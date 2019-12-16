//
//  네트워크_Lv3.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 24/10/2019.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

/// MARK: - 네트워크_Lv3 : DFS Algorithm Problem
#if 0
#include <string>
#include <vector>

using namespace std;

vector<int> G[201];
vector<int> C(201,0);

int DFS(int node) {
    int cnt=0;
    for(int i=0; i<G[node].size(); i++) {
        int next = G[node][i];
        if(C[next]!=0) continue;
        C[next]=1;
        cnt++;
        DFS(next);
    }
    return cnt;
}

int theNetworks(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0; i<computers.size(); i++) {
        for(int j=0; j<computers[i].size(); j++) {
            if(computers[i][j]==1) {
                G[i+1].push_back(j+1);
            }
        }
    }
    
    for(int i=1; i<=n; i++) {
        if(DFS(i)!=0) answer++;
    }
    return answer;
}
#endif
