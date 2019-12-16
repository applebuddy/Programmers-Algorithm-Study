//
//  하노이의탑_12946_Lv3.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 25/10/2019.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

/// MARK: - 하노이의탑_12946 : Recursive Algorithm Problem
//  - 하노이 탑 최소 이동 경우의 수 출력 문제 
#if 0
#include <string>
#include <vector>

using namespace std;
vector<vector<int>> answer;

void move(int from, int to) {
    answer.push_back({from,to});
    return;
}

void hanoi(int N, int from, int by, int to) {
    if(N==0) return;
    hanoi(N-1,from,to,by);
    move(from,to);
    hanoi(N-1,by,from,to);
    return;
}

vector<vector<int>> theHanoiTower(int n) {
    hanoi(n,1,2,3);
    return answer;
}
#endif
