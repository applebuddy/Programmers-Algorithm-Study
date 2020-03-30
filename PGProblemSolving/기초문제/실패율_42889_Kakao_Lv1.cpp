//
//  실패율_42889_Kakao_Lv1.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2019/11/21.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

/// MARK: - 실패율_42889_Kakao_Lv1
#if 0
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int,pair<int,int>> PPair;
typedef pair<int,double> Pair;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    vector<PPair> PV(N,{0,{0,0}});
    vector<Pair> V(N, {0,0.0});
    for(int i=1; i<=N; i++) {
        PV[i-1].first = i;
        V[i-1].first = i;
        for(int k=0; k<stages.size(); k++) {
            if(i<=stages[k]) PV[i-1].second.first++;
            if(i<stages[k]) PV[i-1].second.second++;
        }
    }
    
    for(int i=0; i<PV.size(); i++) {
        double mo = double(PV[i].second.first);
        double ja = double(PV[i].second.first - PV[i].second.second);
        V[i].second = mo==0 ? 0 : ja/mo;
    }
    
    sort(V.begin(), V.end(), [](Pair &a, Pair &b) {
        return (a.second == b.second && a.first < b.first) || (a.second > b.second);
    });
    
    for(auto v: V) answer.push_back(v.first);
    
    return answer;
}
#endif
