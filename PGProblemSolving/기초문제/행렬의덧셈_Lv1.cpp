//
//  행렬의덧셈_Lv1.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 19/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

/// MARK: - 행렬의 덧셈
/// MARK: 행렬의 행/열 크기가 같은 2차원 배열, arr1, arr2의 행렬합 결과를 출력하라!!

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> sumOfTheMetrix(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> Ans(arr1.size(),vector<int>());
    for(int i=0; i<arr1.size(); i++) {
        for(int j=0; j<arr1[i].size(); j++) {
            Ans[i].push_back(arr1[i][j] + arr2[i][j]);
        }
    }
    return Ans;
}
