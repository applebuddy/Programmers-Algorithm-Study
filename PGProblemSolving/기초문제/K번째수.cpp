//
//  K번째수.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 13/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

// MARK: K번째 수
// MARK: array 특정 구간의(commands[i][0]~commands[i][1]번째 숫자) commands[i][2]번째로 큰 숫자를 구해라!

// MARK: - K번째수 복습 풀이답안
#if 0
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> Ans;
    for(auto &V: commands) {
        vector<int> TV = vector<int>(array.begin()+V[0]-1, array.begin()+V[1]);
        sort(TV.begin(), TV.end());
        
        Ans.push_back(TV[V[2]-1]);
    }
    
    return Ans;
}
#endif

//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int subVector(vector<int> v, const int &s, const int const &e, const int &o) {
//    vector<int> tv;
//    for(int i=s-1; i<=e-1; i++) {
//        tv.push_back(v[i]);
//    }
//    sort(tv.begin(), tv.end());
//    return tv[o-1];
//}
//
//vector<int> getKorderNumber(vector<int> array, vector<vector<int>> commands) {
//    vector<int> Ans;
//    for(int i=0; i<commands.size(); i++) {
//        Ans.push_back(subVector(array, commands[i][0], commands[i][1], commands[i][2]));
//    }
//    return Ans;
//}
