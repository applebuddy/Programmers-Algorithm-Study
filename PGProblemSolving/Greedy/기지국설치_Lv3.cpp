//
//  기지국설치_Lv3.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 21/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

///// MARK: - 기지국설치 : Greedy Algorithm Problem
///// MARK: 최소한의 기지국을 설치하라!!!
///// * n : 길이, stations : 기 설치 기지국 위치, w : 기지국 좌/우 송신범위

// MARK: - 기지국설치 복습 문제풀이
#if 0
#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int pos = 1, idx = 0, answer = 0;
    while(pos <= n) {
        if(idx < stations.size() && stations[idx] - w <= pos) {
            pos = stations[idx] + w + 1;
            idx++;
        } else {
            pos += w * 2 + 1;
            answer++;
        }
    }

    return answer;
}
#endif

// 기지국설치 복습 문제풀이 ✓
#if 0
#include <iostream>
#include <vector>
using namespace std;

int findBroadCastCenter(int n, vector<int> stations, int w)
{
    int Ans=0;
    int telIdx=0;
    int cur=1;
    
    while(cur <= n) {
        if(telIdx < stations.size() && cur >= stations[telIdx]-w) {
            cur = stations[telIdx] + w + 1;
            telIdx++;
        } else {
            cur += 2 * w + 1;
            Ans++;
        }
    }
    return Ans;
}
#endif

/// 기지국 설치 통과답안, '19. 09. 21.
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int findBroadcastPlaces(int n, vector<int> stations, int w)
//
//{
//
//    int state = 0;
//
//    int left = 1,count=0;
//
//    while(true){
//
//        //find left
//
//        if(state<stations.size() && left >= stations[state] - w)
//            // stations크기보다 state값이 작고, left가 stations[state]-w 값보다 같거나 크면,
//        {
//
//            left = stations[state]+w+1; // 해당 송신기의 앞쪽은 전부 통신이 되므로, 이 송신기는 안봐도 된다.
//
//            state++; // 다음 송신기인덱스로 넘어간다.
//
//        }
//
//        else{ // 만약 앞에 아직 통신이 안되는 곳이 있다면,
//
//            int newleft = left+w; // left+w으로 left값을 설정하고,
//
//            if( (state<=(int)stations.size()-2) && newleft>=stations[state+1]-w )newleft = stations[state+1]-w-1;
//            // state가 마지막 인덱스가 아니고, 다음송수신기와 newleft가 마주치면, 다음송수신기의 송수신범위 한칸앞으로 left설정한다.
//
//            left=newleft+w+1;// 그게 아니라면 기본값으로 newleft+w+1을 설정한다.
//
//            count++;
//
//        }
//
//        if(left> n)break;
//
//    }
//
//    return count;
//
//}
