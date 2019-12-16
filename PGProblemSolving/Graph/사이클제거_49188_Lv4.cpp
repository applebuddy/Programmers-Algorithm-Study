//
//  사이클제거_49188_Lv4.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2019/12/10.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

// MARK: - 사이클제거 Lv4 (시간초과 답안)
#if 0
#include <string>
#include <vector>

using namespace std;

vector<int> G[5001];

int getParent(int node, vector<int> &Parent) {
    if(Parent[node] == node) return node;
    return getParent(Parent[node], Parent);
}

void mergeParent(int a, int b, vector<int> &Parent) {
    a = getParent(a, Parent);
    b = getParent(b, Parent);
    if(a < b) Parent[b] = a;
    else Parent[a] = b;
}

int solution(int n, vector<vector<int>> edges) {
    int answer = 0;
    vector<int> Parent(n+1,0);
    for(int i=1; i<=n; i++) Parent[i] = i;
    
    for(int i=1; i<=n; i++) {
        bool flag = true;
        vector<int> parent = Parent;
        for(int j=0; j<edges.size(); j++) {
            if(edges[j][0] == i || edges[j][1] == i) continue;
            int nodeA = getParent(edges[j][0], parent);
            int nodeB = getParent(edges[j][1], parent);
            if(nodeA == nodeB) {
                flag = false;
                break;
            } else mergeParent(nodeA, nodeB, parent);
        }
        if(flag) answer += i;
    }
    return answer;
}
#endif
