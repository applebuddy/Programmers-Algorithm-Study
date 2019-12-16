//
//  정수삼각형_43105_Lv3.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 07/10/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

/// MARK: - 정수삼각형_43105
#if 0
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int integerTriangle(vector<vector<int>> triangle) {
    for(int i=0; i<triangle.size()-1; i++) {
        for(int j=0; j<triangle[i].size(); j++) {
            if(j==0) triangle[i+1].front() += triangle[i].front();
            else if(j==triangle.size()-1) triangle[i+1].back() += triangle[i].back();
            else {
                triangle[i+1][j] = (triangle[i+1][j]+triangle[i][j-1] > triangle[i+1][j]+triangle[i][j]) ? triangle[i+1][j]+triangle[i][j-1] : triangle[i+1][j]+triangle[i][j];
            }
        }
    }
    int answer = *max_element(triangle.back().begin(),triangle.back().end());
    return answer;
}
#endif
