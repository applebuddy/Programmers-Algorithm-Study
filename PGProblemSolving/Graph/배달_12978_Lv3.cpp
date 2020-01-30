//
//  배달_12978_Lv3.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2019/12/03.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

/// MARK: 배달 Lv3 129783

// MARK: - 배달 Dijkstra 복습 문제풀이
#if 0
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> Pair;

vector<int> C(2001, 2e9);
vector<Pair> G[51];

struct Compare {
    bool operator() (const Pair &a, const Pair &b) {
        return a.second < b.second;
    }
};

void dijkstra(int start) {
    C[1] = 0;
    priority_queue<Pair, vector<Pair>, Compare> PQ;
    PQ.push({start, 1});
    while(!PQ.empty()) {
        int nowNode = PQ.top().first;
        PQ.pop();
        for(int i=0; i<G[nowNode].size(); i++) {
            int nextNode = G[nowNode][i].first;
            int nextDistance = C[nowNode] + G[nowNode][i].second;
            if(C[nextNode] >= nextDistance) {
                C[nextNode] = nextDistance;
                PQ.push({nextNode, nextDistance});
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    for(auto &v: road) {
        G[v[0]].push_back({v[1],v[2]});
        G[v[1]].push_back({v[0],v[2]});
    }
    dijkstra(1);
    for(int i=1; i<=N; i++) if(C[i]<=K) answer++;
    return answer;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>
#define INF 2100000000
using namespace std;

typedef pair<int,int> Pair;
vector<Pair> G[51];

class Compare {
public:
    template <class T = Pair>
    bool operator() (T &a, T &b) {
        return a.second > b.second;
    }
};

void dijkstra(int node, vector<int> &distance) {
    priority_queue<Pair, vector<Pair>, Compare> PQ;
    PQ.push({node, distance[node]});
    
    while(!PQ.empty()) {
        int nowNode = PQ.top().first;
        int nowDistance = PQ.top().second;
        PQ.pop();
        for(int i=0; i<G[nowNode].size(); i++) {
            int nextNode = G[nowNode][i].first;
            int nextDistance = G[nowNode][i].second + nowDistance;
            if(distance[nextNode] > nextDistance) {
                distance[nextNode] = nextDistance;
                PQ.push({nextNode, nextDistance});
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<int> distance(51,INF);
    distance[1] = 0;
    
    for(int i=0; i<road.size(); i++) {
        G[road[i][0]].push_back({road[i][1],road[i][2]});
        G[road[i][1]].push_back({road[i][0],road[i][2]});
    }
    
    dijkstra(1, distance);
    for(int i=1; i<=N; i++) if(distance[i] <= K) answer++;
    return answer;
}
#endif
