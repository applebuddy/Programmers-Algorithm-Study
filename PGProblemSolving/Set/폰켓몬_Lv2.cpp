//
//  폰켓몬_Lv2.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 19/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

/// MARK: - 폰켓몬
/// MARK: nums.size()/2 개의 폰켓몬을 선택할때 얻을 수 있는 최대 폰켓몬 종류를 알아내라!!
/// * 폰켓몬은 nums의 번호로 매겨져있다. 같은 숫자는 같은 종류의 폰켓몬으로 취급한다.

#include <vector>
#include <set>
#include <cmath>
using namespace std;

int phoneCketMon(vector<int> nums)
{
    set<int> st;
    for(auto v : nums) {
        st.insert(v);
    }
    
    return min(int(st.size()),int(nums.size())/2);
}
