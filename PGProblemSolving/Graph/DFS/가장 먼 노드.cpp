//
//  가장 먼 노드.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 10/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//
#if 0
//#include <string>
//#include <vector>
//#include <string.h>
//#include <stdio.h>
//#include <algorithm>
//#include <queue>
//using namespace std;
//vector<int> g[20001];
//int c[20001];
//
//void BFS(int n){
//    queue<int> q;
//    q.push(n);
//    c[n]=1;
//    while(!q.empty()){
//        int node=q.front();
//        q.pop();
//        for(int i=0; i<g[node].size(); i++){
//            int next=g[node][i];
//            if(c[next]==0){
//                c[next]=c[node]+1;
//                q.push(next);
//            }
//        }
//    }
//}
//
//int farthestNode(int n, vector<vector<int>> edge) {
//    int answer = 1;
//    memset(c,0,sizeof(c));
//    
//    for(int i=0; i<edge.size(); i++){
//        int a=edge[i][0];
//        int b=edge[i][1];
//        g[a].push_back(b);
//        g[b].push_back(a);
//    }
//    
//    for(int i=1; i<=n; i++){
//        sort(g[i].begin(),g[i].end());
//    }
//    
//    BFS(1);
//    sort(c+1, c+n+1, greater<int>());
//    int max = c[1];
//    for(int i=2; i<=n; i++){
//        if(c[i]==max) answer++;
//        else break;
//    }
//    
//    return answer;
//}
#endif
