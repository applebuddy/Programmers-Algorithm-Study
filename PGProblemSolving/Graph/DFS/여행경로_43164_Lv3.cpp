//
//  여행경로_43164_Lv3.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 13/10/2019.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

/// MARK: 여행경로_43164_Lv3 : DFS Algorithm Problem

// MARK: - 여행경로 복습 문제풀이
#if 0
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer = {"ICN"};

vector<bool> checkTicket(10001,false);

bool DFS(string node, int count, const vector<vector<string>> &tickets) {
    if(count == tickets.size()) {
        return true;
    }
    
    bool flag = false;
    for(int i=0; i<tickets.size(); i++) {
        if(tickets[i][0]!=node || checkTicket[i]==true) continue;
        checkTicket[i] = true;
        answer.push_back(tickets[i][1]);
        if(DFS(tickets[i][1], count+1, tickets)) {
            flag = true;
            break;
        }
        checkTicket[i] = false;
    }
    
    if(flag == true) return true;
        
    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end(), [](vector<string> a, vector<string> b) {
        return a[0] < b[0] || (a[0]==b[0] && a[1] < b[1]);
    });
    DFS("ICN", 0, tickets);
    return answer;
}
#endif

// MARK: - 여행경로 복습 이전 문제풀이
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
