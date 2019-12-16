//
//  N-Queen_12952_Lv3.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2019/12/12.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

// MARK: N-Queen_12952_Lv3; BackTracking Problem

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
