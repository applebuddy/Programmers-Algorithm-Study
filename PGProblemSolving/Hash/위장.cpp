//
//  위장.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 10/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

// MARK: 위장 Lv2 문제풀이
#if 0
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string,int> MP;
    for(auto &v : clothes) MP[v[1]]++;
    for(auto &mp : MP) answer *= (mp.second+1);
    return answer-1;
}
#endif
