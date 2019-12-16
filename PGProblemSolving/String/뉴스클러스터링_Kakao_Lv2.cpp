//
//  뉴스클러스터링_Kakao_Lv2.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2019/11/15.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

#if 0
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool checkChar(char ch) {
    if(ch>='a' && ch<='z') return true;
    else return false;
}

int solution(string str1, string str2) {
    int answer = 0;
    for(int i=0; i<str1.length(); i++) str1[i] = tolower(str1[i]);
    for(int i=0; i<str2.length(); i++) str2[i] = tolower(str2[i]);
    multiset<string> setA;
    multiset<string> setB;
    double countA=0, countB=0;
    for(int i=0; i<str1.length()-1; i++) {
        if(checkChar(str1[i]) && checkChar(str1[i+1])) {
            setA.insert(str1.substr(i,2));
            countA++;
        }
    }
    for(int i=0; i<str2.length()-1; i++) {
        if(checkChar(str2[i]) && checkChar(str2[i+1])) {
            setB.insert(str2.substr(i,2));
            countB++;
        }
    }

    vector<string> unionV;
    vector<string> intersectionV;

    set_union(setA.begin(), setA.end(), setB.begin(), setB.end(), back_inserter(unionV));
    set_intersection(setA.begin(), setA.end(), setB.begin(), setB.end(), back_inserter(intersectionV));
    double A = unionV.size();
    double B = intersectionV.size();
    int C = B/A*65536.0;
    answer = C;
    
    map<string,int> MP;
    for(auto s: setA) MP[s]++;
    for(auto s: setB) MP[s]++;
    
    if((A==0 && B==0) || A==0) return 65536;
    else return answer;
}

int main() {
    int Ans = solution("FRANCE","french");
    printf("%d\n",Ans);
    return 0;
}
#endif
