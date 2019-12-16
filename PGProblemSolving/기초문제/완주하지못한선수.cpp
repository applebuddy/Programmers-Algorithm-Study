//
//  완주하지못한선수.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 13/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// HASH map을 사용한 문제풀이
string solution(vector<string> participant, vector<string> completion) {
    // 해시테이블로 선수들의 정보를 저장한다.
    // HASH -> Key: 선수들 이름 / Value: 선수들 도착 유무
    map<string,int> m;
    string Ans = "";
    for(auto p : participant) m[p]++;
    for(auto c : completion) m[c]--;
    
    map<string,int>::iterator iter;
    for(iter=m.begin(); iter!=m.end(); iter++) {
        if((*iter).second != 0) { Ans = iter->first; }
    }
    return Ans;
}

// Sorting을 사용한 문제 풀이

//string solution(vector<string> participant, vector<string> completion) {
//    string Ans = "";
//    sort(participant.begin(), participant.end());
//    sort(completion.begin(), completion.end());
//
//    for(int i=0; i<participant.size(); i++) {
//        if(participant[i] != completion[i]) {
//            Ans = participant[i];
//            break;
//        }
//    }
//    return Ans;
//}
