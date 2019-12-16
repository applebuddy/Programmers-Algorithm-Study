//
//  섬연결하기_42861_Lv3.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 24/10/2019.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

/// MARK: - 섬연결하기_42861_Lv3

#if 0
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Edge {
public:
    int node[2];
    int weight;
    Edge(int from, int to, int weight) {
        this->node[0] = from;
        this->node[1] = to;
        this->weight = weight;
    }
};

int getParent(vector<int> &Parent, int N) {
    if(Parent[N]==N) return N;
    else return getParent(Parent, Parent[N]);
}

void mergeParent(vector<int> &Parent, int A, int B) {
    A = getParent(Parent,A);
    B = getParent(Parent,B);
    if(A<B) Parent[B] = A;
    else Parent[A] = B;
}

int theConnectionOfIsland(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<Edge> EV;
    vector<int> Parent(n,0);
    for(auto v: costs) EV.push_back(Edge(v[0],v[1],v[2]));
    for(int i=0; i<n; i++) Parent[i]=i;
    
    sort(EV.begin(), EV.end(), [](Edge &A, Edge &B) {
        return A.weight < B.weight;
    });
    
    int CNT=0, IDX=0;
    while(CNT != n-1) {
        int from = EV[IDX].node[0];
        int to = EV[IDX].node[1];
        if(getParent(Parent,from) != getParent(Parent,to)) {
            answer += EV[IDX].weight;
            mergeParent(Parent,from,to);
            CNT++;
        }
        IDX++;
    }
    
    return answer;
}
#endif
