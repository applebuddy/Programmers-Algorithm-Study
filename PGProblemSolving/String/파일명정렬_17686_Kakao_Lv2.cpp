//
//  파일명정렬_17686.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2019/11/15.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

/// MARK: - 파일명 정렬_17686

#if 0
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct File {
    int order = 0;
    int compValue = 0;
    string head = "";
    string number = "";
};

vector<string> solution(vector<string> files) {
    vector<File> FV;
    vector<string> Ans;
    map<string,int> MP;

    int cnt=0;
    for(auto v: files) {
        File F;
        F.order = cnt;
        int headLast = 0;
        for(int i=0; i<v.length(); i++) {
            if(v[i]>='0' && v[i]<='9') {
                string temp = v.substr(0,i);
                for(int i=0; i<temp.length(); i++) {
                    temp[i] = tolower(temp[i]);
                }
                F.head = temp;
                headLast = i;
                break;
            }
        }
        
        for(int i=headLast; i<v.length(); i++) {
            string tempStr = "";
            bool flag = false;
            if(!(v[i]>='0' && v[i]<='9')) {
                flag = true;
                tempStr = v.substr(headLast,i-headLast);
            } else if((v[i]>='0' && v[i]<='9') && i==v.length()-1) {
                flag = true;
                tempStr = v.substr(headLast,v.length()-headLast);
            }

            if(flag) {
                while(tempStr.length() < 6) tempStr = "0" + tempStr;
                F.number = tempStr;
                break;
            }
        }
        MP[F.head + F.number]++;
        F.compValue = MP[F.head + F.number];
        FV.push_back(F);
        cnt++;
    }
    
    sort(FV.begin(), FV.end(), [](const File &a, const File &b) {
        if(a.head == b.head && a.number == b.number) {
            return a.compValue < b.compValue;
        }
        else if(a.head > b.head) return false;
        else if(a.head == b.head && a.number > b.number) return false;
        else return true;
    });
    
    for(auto f: FV) Ans.push_back(files[f.order]);
    return Ans;
}
#endif
