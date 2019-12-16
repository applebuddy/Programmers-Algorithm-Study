//
//  베스트앨범.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 17/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//


/// MARK: - 베스트앨범 : Hash Problem (100% Passed)
/// Algorithm Problem Description
//    스트리밍 사이트에서 장르 별로 가장 많이 재생된 노래를 두 개씩 모아 베스트 앨범을 출시하려 합니다. 노래는 고유 번호로 구분하며, 노래를 수록하는 기준은 다음과 같습니다.
//
//    속한 노래가 많이 재생된 장르를 먼저 수록합니다.
//    장르 내에서 많이 재생된 노래를 먼저 수록합니다.
//    장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록합니다.

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

