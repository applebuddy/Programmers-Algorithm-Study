//
//  위장.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 10/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int hide(vector<vector<string>> clothes) {
    int answer = 0;
    map<string,int> m;
    
    for(int i=0; i<clothes.size(); i++){
        m[clothes[i][1]]++;
    }
    
    map<string,int>::iterator iter = m.begin();
    answer = iter->second;
    cout << iter->first << " ";
    for(iter++; iter!=m.end(); iter++){
        cout << iter->first << " ";
        answer += answer*(iter->second) + iter->second;
    }
    
    return answer;
}
