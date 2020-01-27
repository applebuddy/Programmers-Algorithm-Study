//
//  TESTMAN.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 29/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

//#include <iostream>
//#include <map>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <cmath>
//#include <queue>
//#include <set>
//using namespace std;
//
//
//
//typedef pair<int,int> Pair;
//typedef pair<int,set<int>> Pair2;
//vector<int> Q;
//map<int,int> MP;
//
//void eraseVector(int N) {
//    for(int i=0; i<Q.size(); i++) {
//        if(Q[i]==N) {
//            Q.erase(Q.begin()+i);
//            return;
//        }
//    }
//}
//
//int main() {
//
//    int T; cin>>T;
//    for(int i=0; i<T; i++) {
//        string str;
//        int num;
//        cin>>str;
//        
//        // 큐에 값을 넣을때 맵에도 빈도수를 기록한다.
//        if(str=="enqueue") {
//            cin >> num;
//            Q.push_back(num);
//            MP[num]++;
//        }
//        else {
//            if(Q.size()==0) {
//                printf("%d\n",-1);
//            }
//            else {
//                vector<Pair> tv;
//                for(auto m : MP) tv.push_back(make_pair(m.first,m.second));
//                sort(tv.begin(), tv.end(), [](Pair a, Pair b) {
//                    return a.second > b.second;
//                });
//                if(tv[0].second == tv[1].second) {
//                    int temp = Q.front();
//                    Q.erase(Q.begin(),Q.begin()+1);
//                    MP[temp]--;
//                    if(MP[temp]==0) MP.erase(temp);
//                    printf("%d\n",temp);
//                } else {
//                    // 명확히 가장 큰 빈도수가 존재한다면, 그 빈도수의 값을 디큐한다.
//                    int temp = tv[0].first;
//                    printf("%d\n",temp);
//                    eraseVector(temp);
//                    MP[temp]--;
//                    if(MP[temp]==0) MP.erase(temp);
//                }
//            }
//        }
//    }
//    
//    return 0;
//}

//12
//enqueue 1
//enqueue 2
//enqueue 2
//enqueue 1
//enqueue 2
//dequeue
//dequeue
//dequeue
//dequeue
//dequeue
//
//enqueue 7
//dequeue

//ios_base :: sync_with_stdio(0); cin.tie(0);
//map<string,int> MP;
//map<int,int> CNT;
//vector<Pair> V;
//int N;
//cin >> N;
//for(int i=0; i<N; i++) {
//    string str; cin >> str;
//    MP[str]++;
//}
//
//for(auto m : MP) {
//    CNT[m.second]++;
//}
//
//for(auto m : CNT) V.push_back(make_pair(m.first,m.second));
//
//sort(V.begin(), V.end(), [](Pair a, Pair b) {
//    return a.first < b.first;
//});
//// 각 빈도수가 전부 일치한다면 그 카드 쌍 그대로 출력
//if(V.size()==1) printf("Y\n%d\n%d", V[0].first * V[0].second,(int)MP.size());
//else if(V.size()==2) {
//    if(abs(V[0].first-V[1].first)==1 && abs(V[0].second-V[1].second)==1 && (V[0].second <= V[1].second)) {
//        printf("Y\n%d\n%d", max(V[0].first,V[1].first) * (max(V[0].second,V[1].second)+1),(int)MP.size());
//    }
//    else {
//        if(V[0].second==1 && V[1].second==1) printf("Y\n%d\n%d", max(V[0].first,V[1].first) * (max(V[0].second,V[1].second)+1),(int)MP.size());
//        else printf("N\n%d\n%d",N,(int)MP.size());
//    }
//}
//else {
//    printf("N\n%d\n%d",N,(int)MP.size());
//}
