//
//  베스트앨범.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 17/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//


/// MARK: 베스트앨범 : Hash Problem (100% Passed)
/// Algorithm Problem Description
//    스트리밍 사이트에서 장르 별로 가장 많이 재생된 노래를 두 개씩 모아 베스트 앨범을 출시하려 합니다. 노래는 고유 번호로 구분하며, 노래를 수록하는 기준은 다음과 같습니다.
//
//    속한 노래가 많이 재생된 장르를 먼저 수록합니다.
//    장르 내에서 많이 재생된 노래를 먼저 수록합니다.
//    장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록합니다.

// MARK: - 멀티맵 활용 풀이답안(해시맵 + 우선순위큐 보다 좀 더 느림)
#if 0
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<string,int> SPair;
typedef multimap<string,pair<int,int>> MultiMap;

vector<int> solution(vector<string> genres, vector<int> plays) {
    MultiMap MMP;
    map<string,int> MP;
    vector<pair<string,int>> PV;
    vector<int> Ans;
    
    for(int i=0; i<genres.size(); i++) {
        MP[genres[i]] += plays[i];
        MMP.insert({genres[i], {plays[i], i}});
    }
    
    for(auto &mp: MP) PV.push_back({mp.first, mp.second});
    sort(PV.begin(), PV.end(), [](const SPair &a, const SPair &b) {
        return a.second > b.second;
    });
    
    for(int i=0; i<PV.size(); i++) {
        vector<pair<int,int>> tempV;
        MultiMap::iterator iter;
        for(iter=MMP.equal_range(PV[i].first).first; iter!=MMP.equal_range(PV[i].first).second; iter++) {
            tempV.push_back((*iter).second);
        }
        sort(tempV.begin(), tempV.end(), [](pair<int,int> &a, pair<int,int> &b) {
            return a.first > b.first;
        });
        for(int i=0; i<min((int)tempV.size(), 2); i++) {
            Ans.push_back(tempV[i].second);
        }
    }
    return Ans;
}
#endif

// MARK: - 해시맵+우선순위큐 활용 풀이답안(해시맵 + 우선순위큐 보다 좀 더 느림)
#if 0
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;
typedef pair<int, int> Pair;

struct compare{
    bool operator()(const Pair &p1, const Pair &p2){
        if(p1.first < p2.first) return true;
        else if(p1.first == p2.first) {
            if(p1.second > p2.second) return true;
        }
        return false;
    }
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> Ans;
    map<string,priority_queue<Pair,vector<Pair>,compare>> mp;
    map<string,int> totMp;
    map<int,string,greater<int>> totMpr;
    
    for(int i=0; i<genres.size(); i++) {
        mp[genres[i]].push(make_pair(plays[i],i));
        totMp[genres[i]] += plays[i];
    }
    
    for(auto m : totMp) {
        totMpr[m.second] = m.first;
    }
    
    for(auto m : totMpr) {
        priority_queue<Pair,vector<Pair>,compare> tmp = mp[m.second];
        
        if(tmp.size() > 1) {
            Ans.push_back(tmp.top().second); tmp.pop(); Ans.push_back(tmp.top().second);
        } else {
            Ans.push_back(tmp.top().second);
        }
    }
    return Ans;
}
#endif
