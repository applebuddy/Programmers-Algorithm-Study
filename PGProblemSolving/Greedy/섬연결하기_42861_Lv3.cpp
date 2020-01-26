//
//  섬연결하기_42861_Lv3.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 24/10/2019.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

/// MARK: 섬연결하기_42861_Lv3

// MARK: - 섬연결하기 복습 풀이답안
#if 0
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getParent(int node, vector<int> &Parents) {
    if(Parents[node] == node) return node;
    else return getParent(Parents[node], Parents);
}

void mergeParent(int A, int B, vector<int> &Parents) {
    int nodeA = getParent(A, Parents);
    int nodeB = getParent(B, Parents);
    if(nodeA > nodeB) Parents[nodeB] = nodeA;
    else Parents[nodeA] = nodeB;
}

int solution(int n, vector<vector<int>> costs) {
    vector<int> Parents(n+1,0);
    for(int i=1; i<=n; i++) Parents[i] = i;
    sort(costs.begin(), costs.end(), [](vector<int> &a, vector<int> &b) {
        return a[2] < b[2];
    });
    
    int count = 0, idx = 0, answer = 0;
    while(count <= n-1) {
        int nodeA = getParent(costs[idx][0], Parents);
        int nodeB = getParent(costs[idx][1], Parents);
        if(nodeA != nodeB) {
            mergeParent(nodeA, nodeB, Parents);
            answer += costs[idx][2];
            count++;
        }
        idx++;
        if(idx >= costs.size()) break;
    }

    return answer;
}
#endif


// MARK: - 섬연결하기 이전 풀이답안
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
