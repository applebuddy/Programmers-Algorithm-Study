//
//  조이스틱.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 10/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

int INDEX=0;
int checkNum(string name, string s, int index){
    int k=index;
    int l=0,r=0;
    int k2=k;
    while(1){
        if(k==name.length()-1){
            k=0;
            r++;
        }else{
            k++;
            r++;
        }
        if(s[k]!=name[k] || k==index) break;
    }
    
    while(1){
        if(k2==0){
            k2=(int)name.length()-1;
            l++;
        }else{
            k2--;
            l++;
        }
        if(s[k2]!=name[k2] || k2==index) break;
    }
    
    if(min(l,r)==r) {
        INDEX=k; return r;
    } else {
        INDEX=k2; return l;
    }
}

int joyStick(string name) {
    int answer = 0;
    string s = "";
    for(int i=0; i<name.length(); i++){
        s+="A";
    }
    
    // 1) 위아래 조절하는 소요를 판단한다.
    for(int i=0; i<name.length(); i++){
        if(name[i]-'A' > 'Z'-name[i]+1){
            answer += 'Z'-name[i]+1;
        }else{
            answer += name[i]-'A';
        }
    }
    // 첫 인덱스는 미리 조절을 해준다.
    stringstream ss_;
    ss_ << name[0];
    s.replace(0,1,ss_.str());
    
    
    int pre=0;
    while(s!=name){
        stringstream ss;
        int p = checkNum(name,s,INDEX); // 이동해야할 인덱스값을 반환한다.
        answer+=p;
        cout << answer << endl;
        ss << name[INDEX];
        s.replace(INDEX,1,ss.str());
        cout << "s : " << s << endl;
        pre = INDEX;
    }
    
    return answer;
}
