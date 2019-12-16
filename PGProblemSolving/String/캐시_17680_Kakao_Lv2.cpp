//
//  캐시_17680_Kakao_Lv2.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2019/11/18.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

/// MARK: - 캐시_17680_Kakao_Lv2
#if 0
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    unordered_map<string,int> UMP;
    int time = 1;
    for(int i=0; i<cities.size(); i++) {
        string city = cities[i];
        for(int i=0; i<city.length(); i++) city[i] = tolower(city[i]);
        
        if(UMP[city]==0) {
            UMP[city] = time;
            if(UMP.size() > cacheSize) {
                int minTime = 100001;
                string eraseValue = "";
                for(auto m: UMP) {
                    if(m.second < minTime) {
                        minTime = m.second;
                        eraseValue = m.first;
                    }
                }
                UMP.erase(eraseValue);
            }
            answer+=5;
        }
        else {
            UMP[city] = time;
            answer++;
        }
        time++;
    }
    return answer;
}
#endif
