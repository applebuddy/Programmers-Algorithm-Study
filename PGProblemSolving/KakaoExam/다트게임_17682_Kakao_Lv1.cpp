//
//  다트게임_17682_Kakao_Lv1.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2019/11/24.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

/// MARK: - 다트게임 17682 Kakao Lv1
#if 0
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int solution(string dartResult) {
    vector<int> Ans;
    int answer = 0, score = 0;
    string tempStr = "";
    while(dartResult.length() > 0) {
        if(dartResult[0] >= '0' && dartResult[0] <= '9') tempStr += dartResult[0];
        else {
            if(tempStr != "") score = stoi(tempStr);
            tempStr = "";
            if(dartResult[0] == 'S') Ans.push_back(score);
            else if(dartResult[0] == 'D') Ans.push_back(pow(score,2));
            else if(dartResult[0] == 'T') Ans.push_back(pow(score,3));
            else if(dartResult[0] == '*') {
                if(Ans.size() >= 1) Ans[Ans.size()-1] *= 2;
                if(Ans.size() > 1) Ans[Ans.size()-2] *= 2;
            } else if(Ans.size() >= 1) Ans[Ans.size()-1] *= -1;
        }
        dartResult = dartResult.substr(1,dartResult.length()-1);
    }
    
    for(auto v: Ans) answer += v;
    return answer;
}
#endif
