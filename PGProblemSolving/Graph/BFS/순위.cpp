//
//  순위.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 10/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

/// MARK: - 순위
/// 순위를 정할 수 있는 선수는 몇명인가??
/// * Key Point : 선수 간 전전 유무 관계를 그래프로 설정 -> BFS로 상대 전적을 유추할 수 있는 경우를 2차원 c 배열로 정리
///               -> 상대선수들에 대한 상대전적이 있는 선수만 카운팅 하면 답안 제출 -> The End

/// MARK: - 순위 통과답안 : 5th Review
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> G[101];
vector<vector<int>> C(101,vector<int>(101,0));

void BFS(int N) {
    queue<int> Q;
    Q.push(N);
    
    while(!Q.empty()) {
        int node = Q.front();
        Q.pop();
        for(int i=0; i<G[node].size(); i++) {
            int next = G[node][i];
            if(C[N][next]==0) {
                C[N][next]=1;
                C[next][N]=1;
                Q.push(next);
            }
        }
    }
}

int ranking_5(int n, vector<vector<int>> results) {
    int answer = 0;
    for(int i=0; i<n; i++) C[i+1][i+1]=1;
    for(auto v: results) G[v[0]].push_back(v[1]);
    for(int i=1; i<=n; i++) BFS(i);
    for(int i=1; i<=n; i++) {
        bool flag = true;
        for(int j=1; j<=n; j++) {
            if(!C[i][j]) {
                flag = false;
                break;
            }
        }
        if(flag) answer++;
    }
    return answer;
}

/////// 복습 3) '19. 10. 08.
//#include <string>
//#include <queue>
//#include <vector>
//#include <string.h>
//
//using namespace std;
//
//vector<vector<int>> C(101,vector<int>(101,0));
//vector<int> G[101];
//
//void BFS(int N) {
//    queue<int> Q;
//    Q.push(N);
//    while(!Q.empty()) {
//        int node = Q.front();
//        Q.pop();
//        for(int i=0; i<G[node].size(); i++) {
//            int next = G[node][i];
//            if(C[N][next]==0) {
//                C[N][next]=1;
//                C[next][N]=1;
//                Q.push(next);
//            }
//        }
//    }
//}
//
//int ranking_4(int n, vector<vector<int>> results) {
//    int answer = 0;
//
//    for(int i=1; i<=n; i++) {
//        C[i][i]=1;
//    }
//
//    for(auto v : results) {
//        G[v[0]].push_back(v[1]);
//    }
//
//    for(int i=1; i<=n; i++) BFS(i);
//
//    for(int i=1; i<=n; i++) {
//        bool flag=true;
//        for(int j=1; j<=n; j++) {
//            if(C[i][j]==0) { flag=false; break; }
//        }
//        if(flag) answer++;
//    }
//
//    return answer;
//}

///// 복습 3) '19. 09. 23.
//#include <string>
//#include <string.h>
//#include <queue>
//#include <vector>
//
//using namespace std;
//
//vector<vector<int>> C(101,vector<int>(101,0));
//vector<int> G[101];
//
//void BFS(int N) {
//    queue<int> Q;
//    Q.push(N);
//    while(!Q.empty()) {
//        int node = Q.front();
//        Q.pop();
//        for(int i=0; i<G[node].size(); i++) {
//            int next=G[node][i];
//            if(C[N][next]!=0) continue;
//            C[N][next] = 1;
//            C[next][N] = 1;
//            Q.push(next);
//        }
//    }
//}
//
//int ranking(int n, vector<vector<int>> results) {
//    int Ans = 0;
//    for(int i=1; i<=n; i++) {
//        C[i][i]=1;
//        memset(G,0,sizeof(G[i]));
//    }
//
//    for(auto v : results) {
//        G[v[0]].push_back(v[1]);
//    }
//
//    for(int i=1; i<=n; i++) {
//        BFS(i);
//    }
//
//    for(int i=1; i<=n; i++) {
//        bool flag = true;
//        for(int j=1; j<=n; j++) {
//            if(C[i][j]==1) continue;
//            flag = false;
//            break;
//        }
//        if(flag==true) Ans++;
//    }
//    return Ans;
//}

///// 복습 2) '19. 09. 23.
//#include <string>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//vector<vector<int>> C(101,vector<int>(101,0));
//void BFS(int N, const vector<vector<int>> & G) {
//    queue<int> Q;
//    Q.push(N);
//
//    while(!Q.empty()) {
//        int node = Q.front();
//        Q.pop();
//        for(int i=0; i<G[node].size(); i++) {
//            int next = G[node][i];
//            if(C[N][next]!=0) continue;
//            C[N][next] = 1;
//            C[next][N] = 1;
//            Q.push(next);
//        }
//    }
//}
//
//int ranking(int n, vector<vector<int>> results) {
//    vector<vector<int>> Graph(n+1,vector<int>());
//    int Ans = 0;
//    for(auto v : results) {
//        Graph[v[0]].push_back(v[1]);
//    }
//
//    for(int i=1; i<=n; i++) {
//        C[i][i] = 1;
//        BFS(i,Graph);
//    }
//
//    for(int i=1; i<=n; i++) {
//        bool flag = true;
//        for(int j=1; j<=n; j++) {
//            if(C[i][j]==0) {
//                flag = false;
//                break;
//            }
//        }
//        if(flag==true) Ans++;
//    }
//    return Ans;
//}


//// 복습 1)
//#include <string>
//#include <string.h>
//#include <stdio.h>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//int c[101][101];
//vector<int> g[101];
//
//void BFS(int n){
//    queue<int> q;
//    q.push(n);
//
//    while(!q.empty()){
//        int node=q.front();
//        q.pop();
//        for(int i=0; i<g[node].size(); i++){
//            int next=g[node][i];
//            if(c[n][next]==0){
//                c[n][next]=1;
//                c[next][n]=1;
//                q.push(next);
//            }
//        }
//    }
//}
//
//int ranking(int n, vector<vector<int>> results) {
//
//    int answer = 0;
//    for(int i=0; i<=n; i++){
//        memset(c[i],0,sizeof(c[i]));
//        c[i][i]=1;
//    }
//    for(auto r : results){
//        g[r[0]].push_back(r[1]);
//    }
//
//    for(int i=1; i<=n; i++){
//        BFS(i);
//    }
//
//    for(int i=1; i<=n; i++){
//        bool flag=true;
//        for(int j=1; j<=n; j++){
//            if(c[i][j]==0){
//                flag=false;
//                break;
//            }
//        }
//        if(flag==true){
//            answer++;
//        }
//    }
//
//    return answer;
//}
