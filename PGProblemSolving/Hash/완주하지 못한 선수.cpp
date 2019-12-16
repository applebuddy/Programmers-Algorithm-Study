//
//  완주하지 못한 선수.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 10/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

/// MARK: - 완주하지 못한 선수_42576_Lv2

#if 0
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

/// MARK: unordered_map 사용 통과 답안)
string playerWhoCounldntFinish2(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string,int> UMP;
    for(auto v : participant) UMP[v]++;
    for(auto v : completion) UMP[v]--;
    for(auto v : participant) if(UMP[v]==1) return v;
    return "";
}
#endif

//string playerWhoCouldntFinish(vector<string> participant, vector<string> completion) {
//    string answer = "";
//    map<string,int> mp;
//
//    for(auto p : participant){
//        mp[p]++;
//    }
//
//    for(auto c : completion){
//        mp[c]--;
//    }
//
//    for(auto p : participant){
//        if(mp[p]==1) {
//            answer = p;
//            break;
//        }
//    }
//    return answer;
//}
