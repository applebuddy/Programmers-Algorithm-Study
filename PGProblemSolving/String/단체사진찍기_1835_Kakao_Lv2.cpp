//
//  단체사진찍기_1835_Kakao_Lv2.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2019/11/15.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

#if 0
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int Ans=0;
    vector<char> CV = {'A','C','F','J','M','N','R','T'};
    do {
        map<char,int> MP;
        for(int i=0; i<CV.size(); i++) MP[CV[i]]=i;

        bool flag = true;
        for(int i=0; i<data.size(); i++) {
            int dif = abs(MP[data[i][0]]-MP[data[i][2]])-1;
            if(data[i][3]=='=') {
                if(dif!=(data[i][4]-'0')) {
                    flag=false;
                    break;
                }
            } else if(data[i][3]=='>') {
                if(dif<=(data[i][4]-'0')) {
                    flag=false;
                    break;
                }
            } else if(data[i][3]=='<') {
                if(dif>=(data[i][4]-'0')) {
                    flag=false;
                    break;
                }
            }
        }
        if(flag) Ans++;
    } while(next_permutation(CV.begin(), CV.end()));

    return Ans;
}
#endif
