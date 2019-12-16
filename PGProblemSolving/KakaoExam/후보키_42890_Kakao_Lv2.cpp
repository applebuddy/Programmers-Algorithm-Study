//
//  후보키_42890_Kakao_Lv2.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2019/12/16.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

// MARK: 후보키_42890 Kakao_Lv2

#if 0
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

int toInt(const string &S) {
    int sol = 0;
    int flag = 0;
    for(int i=S.length()-1; i>=0; i--) {
        if(S[i]=='1') sol += pow(2,flag);
        flag++;
    }
    return sol;
}

int countOne(const string &S) {
    int count=0;
    for(auto s: S) if(s=='1') count++;
    return count;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int row = relation.size();
    int col = relation[0].size();
    
    vector<string> Ans;
    
    for(int i=1; i<=col; i++) {
        string PS = string(col-i,'0');
        for(int j=0; j<i; j++) PS += '1';
        
        do {
            set<vector<string>> SST;
            for(int T=0; T<row; T++) {
                vector<string> tempST;
                int sstSize = SST.size();
                for(int k=0; k<col; k++) {
                    if(PS[k]=='1') tempST.push_back(relation[T][k]);
                }
                SST.insert(tempST);
                if(SST.size()==sstSize) break;
            }
            
            if(SST.size()==row) {
                Ans.push_back(PS);
            }

        }while(next_permutation(PS.begin(), PS.end()));
        
    }
    
    sort(Ans.begin(), Ans.end(), [](const string &A, const string &B) {
        return (A > B);
    });
    
    while(!Ans.empty()) {
        string key = Ans.back();
        Ans.pop_back();
        answer++;
        for(int i=0; i<Ans.size();) {
            if((toInt(key) & toInt(Ans[i])) == toInt(key)) {
                Ans.erase(Ans.begin()+i, Ans.begin()+i+1);
            }
            else i++;
        }
    }
    return answer;
}
#endif

