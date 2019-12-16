//
//  모의고사.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 13/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

// MARK: - 모의고사
// 1,2,3번 학생 중 가장 높은 점수인 사람을 구해라!!
// * 동점자 존재 시 오름차순으로 학생 번호를 출력한다.
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> prelliminaryExamination(vector<int> answers) {
    vector<int> Ans;
    int one[5] = {1,2,3,4,5};
    int two[8] = {2,1,2,3,2,4,2,5};
    int three[10] = {3,3,1,1,2,2,4,4,5,5};
    int score[3] = {0,0,0};
    
    for(int i=0; i<answers.size(); i++) {
        if(one[i%5] == answers[i]) score[0]++;
        if(two[i%8] == answers[i]) score[1]++;
        if(three[i%10] == answers[i]) score[2]++;
    }
    
    int maxV = max(max(score[0],score[1]),score[2]);
    for(int i=0; i<3; i++) {
        if(score[i]==maxV) Ans.push_back(i+1);
    }
    
    return Ans;
}

