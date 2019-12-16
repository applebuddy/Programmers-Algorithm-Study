//
//  n등굣길_42898_Lv3.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 13/10/2019.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

/// MARK: - 등굣길_42898_Lv3
#if 0
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;
typedef pair<int,int> Pair;

vector<vector<int>> G(101,vector<int>(101,1));
vector<vector<int>> C(101,vector<int>(101,0));
map<int,int,greater<int>> MP;

int posX[] = {0,1};
int posY[] = {1,0};

void BFStoSchool(int X, int Y, int m, int n) {
    queue<Pair> Q;
    Q.push({X,Y});
    C[1][1]=1;
    while(!Q.empty()) {
        int nx = Q.front().first;
        int ny = Q.front().second;
        Q.pop();
        for(int i=0; i<2; i++) {
            int mx = nx + posX[i];
            int my = ny + posY[i];
            if(mx>m || mx<1 || my<1 || my>n) continue;
            if(G[mx][my]==0) continue;
            C[mx][my] = min(C[mx][my],C[nx][ny]+1);
            if(mx==m && my==n) {
                MP[C[mx][my]] = (MP[C[mx][my]]+1)%1000000007;
            }
            Q.push({mx,my});
        }
    }
}

int schoolRoad(int m, int n, vector<vector<int>> puddles) {
    Pair Ans = {2100000000,0};
    for(auto v: puddles) G[v[1]][v[0]]=0;
    BFStoSchool(1,1,m,n);
    for(auto m: MP) {
        if(Ans.first > m.first) {
            Ans.first = m.first;
            Ans.second = m.second;
        }
    }
    return Ans.second;
}
#endif
