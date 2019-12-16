//
//  후보키_42890_Kakao_Lv2.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2019/11/19.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

///
#if 0
// 9,11번 테스트케이스 틀리는 답안
// MARK: - 비트마스크 사용버전
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
        string PS = string(i,'1');
        for(int j=0; j<col-i; j++) PS += '0';
        
        do {
            set<set<string>> SST;
            for(int T=0; T<row; T++) {
                set<string> tempST;
                int sstSize = SST.size();
                for(int k=0; k<col; k++) {
                    if(PS[k]=='1') tempST.insert(relation[T][k]);
                }
                SST.insert(tempST);
                if(SST.size()==sstSize) break;
            }
            
            if(SST.size()==row) {
                Ans.push_back(PS);
            }

        }while(prev_permutation(PS.begin(), PS.end()));
        
    }
    
    sort(Ans.begin(), Ans.end(), [](const string &A, const string &B) {
        return (countOne(A) > countOne(B));
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

#if 0
// 9,11번 테스트케이스 틀리는 답안
// MARK: - set_intersection 사용 버전
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
        string PS = string(i,'1');
        for(int j=0; j<col-i; j++) PS += '0';
        
        do {
            set<set<string>> SST;
            for(int T=0; T<row; T++) {
                set<string> tempST;
                int sstSize = SST.size();
                for(int k=0; k<col; k++) {
                    if(PS[k]=='1') tempST.insert(relation[T][k]);
                }
                SST.insert(tempST);
                if(SST.size()==sstSize) break;
            }
            
            if(SST.size()==row) {
                Ans.push_back(PS);
            }

        }while(prev_permutation(PS.begin(), PS.end()));
        
    }
    
    vector<set<int>> AV;
    for(int i=0; i<Ans.size(); i++) {
        set<int> tempST;
        for(int j=0; j<Ans[i].size(); j++) if(Ans[i][j]=='1') tempST.insert(j);
        
        
        AV.push_back(tempST);
    }
    
    sort(AV.begin(), AV.end(), [](const set<int> &A, const set<int> &B) {
        return (A.size()==B.size() && A>B) || A.size()>B.size();
    });
    
    for(auto v: AV) {
        for(auto s: v) printf("%d, ",s);
        puts("");
    }
    
    
    while(!AV.empty()) {
        set<int> key = AV.back();
        AV.pop_back();
        answer++;
        for(int i=0; i<AV.size();) {
            vector<int> Comp;
            set_intersection(AV[i].begin(),AV[i].end(),key.begin(),key.end(),back_inserter(Comp));
            if(Comp.size() == key.size()) {
                // printf("%s, %d\n",key.c_str(), toInt(key));
                AV.erase(AV.begin()+i, AV.begin()+i+1);
            }
            else i++;
        }
    }
    return answer;
}
#endif
