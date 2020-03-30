//
//  최댓값과최솟값_Lv2.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 19/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

// MARK: - 최댓값과 최솟값
// 공백 간격으로 숫자가 있는 문자열을 받아 해당 문자열의 최솟값, 최댓값 출력하기
#if 0
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string getMinMaxNumber(string s) {
    vector<int> Ans;
    string answer = "";
    string data = "";
    
    for(stringstream ss(s); ss >> data;) Ans.push_back(stoi(data));
    sort(Ans.begin(), Ans.end());
    answer += to_string(Ans.front()) + " ";
    answer += to_string(Ans.back());
    return answer;
}
#endif
