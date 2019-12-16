//
//  타겟넘버DP_43165_Lv2.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 11/10/2019.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

/// MARK: - 타겟넘버 : Dynamic Programming version.
#if 0
#include <string>
#include <vector>

using namespace std;

int Ans = 0;

vector<vector<int>> C(21,vector<int>(2001,-1001));
int DFS(vector<int> numbers, int target, int count, int sum) {
    if(count==numbers.size()) {
        if(target == sum) return C[count][sum+1000] = 1;
        else return C[count][sum+1000] = 0;
    }
    if(C[count][sum+1000] != -1001) return C[count][sum+1000];
    
    return C[count][sum+1000] = DFS(numbers,target,count+1,sum+numbers[count]) + DFS(numbers,target,count+1,sum-numbers[count]);
}
#endif
