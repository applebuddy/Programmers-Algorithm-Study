//
//  가장큰정사각형찾기.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 19/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

/// MARK: - 가장 큰 정사각형 찾기ㅣ
/// MARK: 2차원벡터, board 내의 1로만 이루어진 정사각형의 최대 크기를 출력하라!!
#if 0
#include <vector>
#include <iostream>

using namespace std;

int findBiggestRectangular(vector<vector<int>> board)
{
    int Ans=0;
    int flag = false;
    if(board.size()==1 || board[0].size()==1) {
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[i].size(); j++) {
                if(board[i][j] == 1) return 1;
            }
        }
        return 0;
    }
    
    for(int i=1; i<board.size(); i++) {
        for(int j=1; j<board[i].size(); j++) {
            if((board[i-1][j-1]>0 || board[i][j-1]>0 || board[i-1][j]>0 || board[i][j]>0) && flag==false) {
                flag = true;
            }
            
            if(board[i][j]>0 && board[i-1][j-1]>0 && board[i][j-1]>0 && board[i-1][j]>0) {
                board[i][j] = min(board[i-1][j-1],min(board[i][j-1], board[i-1][j]))+1;
                Ans = max(Ans,board[i][j]);
            }
        }
    }
    
    return (flag==true) ? max(1,Ans*Ans) : 0;
}
#endif
