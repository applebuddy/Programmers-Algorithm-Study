//
//  N-Queen_12952_Lv3.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2019/12/12.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

// MARK: N-Queen Lv3 12952; BackTracking Problem

// MARK: - N-Queen 복습 문제풀이
#if 0
#include <string>
#include <vector>

using namespace std;

int tx[] = {-1,-1};
int ty[] = {-1,1};
int answer = 0;

vector<vector<int>> Board(13,vector<int>(13,0));

bool checkBoard(int x, int y, int n) {
    
    for(int i=0; i<n; i++) {
        if(i!=x && Board[i][y]==1) return false;
        if(i!=y && Board[x][i]==1) return false;
    }
    
    for(int i=0; i<2; i++) {
        int nx = x + tx[i];
        int ny = y + ty[i];
        while(nx>=0 && ny>=0 && nx<n && ny<n) {
        if(Board[nx][ny]==1) return false;
        nx+=tx[i];
        ny+=ty[i];
        }
    }
    
    return true;
}

void DFS(int idx, int n) {
    if(idx >= n) {
        answer++;
        return;
    }
    
    for(int i=0; i<n; i++) {
        Board[idx][i] = 1;
        if(checkBoard(idx, i, n)) {
            DFS(idx+1, n);
        }
        Board[idx][i] = 0;
    }
    return;
}

int solution(int n) {
    DFS(0, n);
    return answer;
}
#endif

#if 0
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> board(13, vector<int>(13,0));
int nx[4] = {-1, 1, 1, -1};
int ny[4] = {1, 1, -1, -1};
int Ans = 0;

bool checkPos(int x, int y, int n) {
    for(int i=1; i<=n; i++) {
        if(x != i && board[i][y]==1) return false;
        if(y != i && board[x][i]==1) return false;
    }
    
    for(int i=0; i<4; i++) {
        int xPos = x + nx[i], yPos = y + ny[i];
        while(xPos >= 1 && xPos <= n && yPos >= 1 && yPos <= n) {
            if(board[xPos][yPos]==1) return false;
            xPos += nx[i];
            yPos += ny[i];
        }
    }
    
    return true;
}

void DFS(int idx, int n) {
    if(idx > n) {
        Ans++;
        return;
    }
    
    for(int i=1; i<=n; i++) {
        if(checkPos(idx, i, n)) {
            board[idx][i]=1;
            DFS(idx+1,n);
        }
        board[idx][i]=0;
    }
    return;
}

int solution(int n) {
    DFS(1,n);
    return Ans;
}
#endif
