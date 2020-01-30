//
//  게임맵최단거리_Lv4.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2020/01/30.
//  Copyright © 2020 MinKyeongTae. All rights reserved.
//

// MARK: 게임맵최단거리 Lv4

// MARK: - BFS 문제풀이 
#if 0
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> Pair;
int tx[] = {0,0,-1,1};
int ty[] = {1,-1,0,0};

vector<vector<int>> C(101,vector<int>(101,0));

void BFS(int X, int Y, const int &N, const int &M, const vector<vector<int>> &G) {
    queue<Pair> Q;
    C[X][Y]=1;
    Q.push({X,Y});
    while(!Q.empty()) {
        Pair node = Q.front();
        Q.pop();
        int x = node.first;
        int y = node.second;
        for(int i=0; i<4; i++) {
            int nx = x + tx[i];
            int ny = y + ty[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(G[nx][ny]==0 || C[nx][ny]>0) continue;
            C[nx][ny] = C[x][y] + 1;
            Q.push({nx,ny});
        }
    }
}

int solution(vector<vector<int> > maps)
{
    int result = 0;
    BFS(0,0, maps.size(), maps[0].size(), maps);
    result = C[maps.size()-1][maps[0].size()-1];
    if(result==0) return -1;
    return result;
}
#endif
