//
//  카펫.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 17/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

/// MARK: 카펫
/// * Problem Description
//  -Leo는 카펫을 사러 갔다가 아래 그림과 같이 중앙에는 빨간색으로 칠해져 있고 모서리는 갈색으로 칠해져 있는 격자 모양 카펫을 봤습니다.
//  -Leo는 집으로 돌아와서 아까 본 카펫의 빨간색과 갈색으로 색칠된 격자의 개수는 기억했지만, 전체 카펫의 크기는 기억하지 못했습니다.
//  -Leo가 본 카펫에서 갈색 격자의 수 brown, 빨간색 격자의 수 red가 매개변수로 주어질 때 카펫의 가로, 세로 크기를 순서대로 배열에 담아 return 하도록 solution 함수를 작성해주세요.

// MARK: - 카펫 Lv2 문제풀이
#if 0
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    int w=3, h=3;
    int dim = brown + red;
    while(w < dim) {
        if(dim % w != 0) {
            w++;
            continue;
        }
        h = dim/w;
        if((w-2) * (h-2) == red) {
            break;
        }
        w++;
    }
    
    if(w < h) swap(w, h);
    return {w, h};
}
#endif
