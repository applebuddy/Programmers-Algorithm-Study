//
//  정수삼각형_43105_Lv3.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 07/10/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

/// MARK: 정수삼각형 Lv3 43105

// MARK: - 정수삼각형 복습 풀이답안
#if 0
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = triangle[0][0];
    for(int i=1; i<triangle.size(); i++) {
        for(int j=0; j<triangle[i].size(); j++) {
            if(j==0) triangle[i][j] += triangle[i-1][j];
            else if(j==triangle[i].size()-1) triangle[i][j] += triangle[i-1][triangle[i-1].size()-1];
            else triangle[i][j] += max(triangle[i-1][j-1], triangle[i-1][j]);
            answer = triangle[i][j] > answer ? triangle[i][j] : answer;
        }
    }
    return answer;
}
#endif

// MARK: - 정수삼각형 풀이답안
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
