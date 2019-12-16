//
//  직사각형빠진점찾기.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 19/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

/// MARK: - 빠진 직사각형 점 찾기
/// MARK: 어느 직사각형의 세개의 점이 2차원 벡터, v로 주어진다. 빠진점의 x,y좌표를 출력해라!!

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Compare {
    public :
    template <class T = vector<int>>
    bool operator () (T& a, T& b) const {
        return a[0] < b[0];
    }
};

vector<int> findMissingRectPoints(vector<vector<int>> v) {
    sort(v.begin(), v.end(), Compare());
    int x,y;
    vector<int> ans;
    
    if(v[0][0]==v[1][0]) x = v[2][0];
    else x = v[0][0];
    
    if(v[0][1]==v[1][1]) y = v[2][1];
    else y = v[0][1];
    
    ans.push_back(x);
    ans.push_back(y);
    return ans;
}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//class Compare {
//    public :
//    template <class T = vector<int>>
//    bool operator() (T& a, T& b) const {
//        return a[0] < b[0];
//    }
//};
//
//bool compare(vector<int> a, vector<int> b) {
//    return a[0] < b[0];
//}
//
//vector<int> solution(vector<vector<int>> v) {
//    sort(v.begin(), v.end(), Compare());
//    vector<int> Ans;
//    if(v[0][0]==v[1][0]) Ans.push_back(v[2][0]);
//    else Ans.push_back(v[0][0]);
//    printf("%d\n",v[0][0]);
//    if(v[0][1]==v[1][1]) Ans.push_back(v[2][1]);
//    else Ans.push_back(v[0][1]);
//
//    return Ans;
//}
