//
//  JadenCase문자열만들기_12951_Lv2.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 08/10/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

#if 0
#include <string>
#include <vector>
#include <sstream>

using namespace std;

/// MARK: - sstream 없이 구현, 통과 답안)

string makingJadenCaseString(string s) {
    string Ans="";
    vector<string> AV;
    string temp="";
    for(stringstream ss(s); ss>>temp;) {
        for(int i=0; i<temp.length(); i++) {
            if(i==0) {
                if(temp[i]-'a'>=0 && temp[i]-'a'<=25) temp[i] = temp[i]-32;
            }
            else {
                if(temp[i]-'A'>=0 && temp[i]-'A'<=25) temp[i] = temp[i]+32;
            }
        }
        printf("%s\n",temp.c_str());
        AV.push_back(temp);
    }
    
    for(int i=0; i<AV.size(); i++) {
        Ans+=AV[i];
        if(i!=AV.size()-1) Ans+=' ';
    }
    
    if(s.back()==' ') Ans+=' ';
    return Ans;
}
#endif

/// MARK: - sstream 사용 구현, 테스트케이스 절반 통과 답안)
#if 0
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    string Ans="";
    vector<string> AV;
    string temp="";
    for(stringstream ss(s); ss>>temp;) {
        for(int i=0; i<temp.length(); i++) {
            if(i==0) {
                if(temp[i]-'a'>=0 && temp[i]-'a'<=25) temp[i] = temp[i]-32;
            }
            else {
                if(temp[i]-'A'>=0 && temp[i]-'A'<=25) temp[i] = temp[i]+32;
            }
        }
        printf("%s\n",temp.c_str());
        AV.push_back(temp);
    }
    
    for(int i=0; i<AV.size(); i++) {
        Ans+=AV[i];
        if(i!=AV.size()-1) Ans+=' ';
    }
    
    if(s.back()==' ') Ans+=' ';
    return Ans;
}

#endif
