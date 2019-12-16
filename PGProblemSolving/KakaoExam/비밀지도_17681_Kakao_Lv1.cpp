//
//  비밀지도_17681_Lv1.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2019/11/28.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

// MARK: - 비밀지도 Lv1
#if 0
#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<int> AnsV;
    for(int i=0; i<arr1.size(); i++) {
        string tempStr = "";
        int num = arr1[i] | arr2[i];
        while(num>0) {
            tempStr = num%2==1 ? '#' + tempStr : ' ' + tempStr;
            num/=2;
        }
        while(tempStr.length() < n) tempStr = ' ' + tempStr;
        answer.push_back(tempStr);
    }
    return answer;
}
#endif
