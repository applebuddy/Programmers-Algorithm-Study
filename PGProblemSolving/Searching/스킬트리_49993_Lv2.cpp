//
//  스킬트리_49993_Lv2.cpp
//  PGProblemSolving
//
//  Created by MinKyeongTae on 11/10/2019.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

/// MARK: - 스킬트리_49993_Lv2

#include <string>
#include <vector>

using namespace std;

bool checkSkillTree(const string &skill, const string &tree) {
    bool flag=true;
    int pos = 0;
    for(auto s: skill) {
        int cur = (int)tree.find(s);
        if(cur != string::npos) {
            if(flag==false || cur < pos) return false;
            pos = cur;
        } else flag=false;
    }
    return true;
}
