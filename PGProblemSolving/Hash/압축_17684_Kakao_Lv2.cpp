//
//  압축_17684_Kakao_Lv2.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2019/11/18.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

/// MARK: - 압축_17684_Kakao_Lv2
#if 0
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string,int> MP;
    int newCode = 27;
    for(int i=0; i<msg.length(); i++) {
        MP[to_string(msg[i])]=msg[i]-'A'+1;
    }
    
    int idx=0;
    while(1) {
        string W = to_string(msg[idx]);
        while(1) {
            if(idx >= msg.length()) break;
            string dicStr = W;
            dicStr += msg[idx+1];
            if(MP[dicStr]==0) {
                MP[dicStr]=newCode;
                idx++;
                newCode++;
                answer.push_back(MP[W]);
                break;
            } else {
                idx++;
                W = dicStr;;
            }
        }
        if(idx >= msg.length()) break;
    }
    return answer;
}
#endif
