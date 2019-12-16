//
//  프렌츠4블록_Lv2.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2019/12/01.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

// MARK: - 프렌즈4블록_Lv2

#include <string>
#include <vector>

using namespace std;

int friends4Block(int m, int n, vector<string> board) {
    int answer = 0;
    vector<vector<char>> newV(board[0].size(), vector<char>(board.size(), ' '));

    // 처리하기 쉽게 배열을 회전하는 작업
    for(int i=0; i<board.size(); i++) {
        for(int j=0; j<board[0].size(); j++) {
            newV[j][board.size()-i-1] = board[i][j];
        }
    }

    // 배열의 없어질 2x2를 체크하고 제거하는 작업, removeCnt가 증가하지 않으면 해당 루프를 빠져나간다.
    while(1) {
        int removeCnt = 0;
        vector<vector<char>> C = newV;

        // 중복이 해당하는 경우 '.'으로 제거해야할 블록임을 표시한다.
        for(int i=0; i<newV.size()-1; i++) {
            for(int j=0; j<newV[i].size()-1; j++) {
                if((newV[i+1].size()-1 < j || newV[i+1].size()-1 < j+1)
                   || newV[i].empty() || newV[i+1].empty()) break;

                if(newV[i][j]==newV[i][j+1] && newV[i][j+1]==newV[i+1][j+1]
                  && newV[i+1][j+1]==newV[i+1][j] && newV[i+1][j]==newV[i][j]) {
                    C[i][j] = '.';
                    C[i][j+1] = '.';
                    C[i+1][j] = '.';
                    C[i+1][j+1] = '.';
                }
            }
        }

        // 제거할 블록을 하나씩 제거하고 다시 중복블럭 체크할 준비를 한다.
        for(int i=0; i<newV.size(); i++) {
            int idx = 0;
            while(idx < newV[i].size()) {
                if(C[i][idx] == '.') {
                    newV[i].erase(newV[i].begin()+idx, newV[i].begin()+idx+1);
                    C[i].erase(C[i].begin()+idx, C[i].begin()+idx+1);
                    removeCnt++;
                }
                else idx++;
            }
        }

        if(removeCnt == 0) break;
        else answer += removeCnt;
    }

    return answer;
}

//int main() {
//    int Ans = solution(6,6,{"TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"});
//    Ans = solution(4, 5, {"CCBDE", "AAADE", "AAABF", "CCBBF"});
//    printf("%d\n",Ans);
//    return 0;
//}
