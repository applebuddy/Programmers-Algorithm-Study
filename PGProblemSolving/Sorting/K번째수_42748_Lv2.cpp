//
//  K번째수_42748_Lv2.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 12/10/2019.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

/// MARK: - K번째 수_42748

/// MARK: vector 사용, 간략 통과 답안
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> The_K_thNumber(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(auto v: commands) {
        vector<int> temp;
        for(int i=v[0]-1; i<=v[1]-1; i++) temp.push_back(array[i]);
        sort(temp.begin(), temp.end());
        answer.push_back(temp[v[2]-1]);
    }
    return answer;
}

/// MARK: vector clear(), assign() 활용 통과 답안
//vector<int> solution(vector<int> array, vector<vector<int>> commands) {
//    vector<int> answer;
//    vector<int> temp;
//
//    for(vector<int>& command : commands){
//       temp.clear();
//       temp.assign(array.begin() + command[0]-1,array.begin() + command[1]);
//
//        for(int i=0; i<temp.size(); i++){
//            cout << temp[i] << " ";
//        }
//        sort(temp.begin(), temp.end());
//        answer.push_back(temp[command[2]-1]);
//        cout << endl;
//    }
//
//    return answer;
//}
