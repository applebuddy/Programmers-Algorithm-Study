//
//  여행경로_43164_Lv3.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 13/10/2019.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

/// MARK: - 여행경로_43164_Lv3 : DFS Algorithm Problem
#if 0
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<string>> G(10001,vector<string>());
vector<string> ANS;
bool DFS(string from, vector<vector<string>> &tickets, vector<bool> &visit, vector<string> &Ans, int count) {
    Ans.push_back(from);
    
    if(count == tickets.size()) {
        ANS = Ans;
        return true;
    }

    for(int i=0; i<tickets.size(); i++) {
        if(tickets[i][0]==from && visit[i]==false) {
            visit[i]=true;
            bool isFinish = DFS(tickets[i][1],tickets,visit,Ans,count+1);
            if(isFinish) return true;
            else visit[i]=false;
        }
    }
    
    Ans.pop_back();
    return false;
}

vector<string> theTravelPath(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<bool> visit(tickets.size(),false);
    sort(tickets.begin(), tickets.end());
    DFS("ICN", tickets, visit, answer, 0);
    return ANS;
}
#endif
