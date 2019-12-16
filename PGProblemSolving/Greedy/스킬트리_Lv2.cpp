//
//  스킬트리_Lv2.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 18/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

/// MARK: - 스킬트리
/// MARK: skill_trees의 스킬 조합 들 중, skill을 순서대로 조합하고 있는 경우 갯수를 출력하라!!

#include <string>
#include <vector>

using namespace std;

bool checkSkill(string skill, string skill_tree) {
    /// 앞서 발견 한 스킬트리의 인덱스 변수
    int prev = 0;
    /// 앞 순서의 스킬트리를 사용하지 않았을 경우를 체크할 변수
    bool psd = true;
    for(auto s : skill) {
        /// 특정 스킬트리가 존재하는지 확인
        int cur = int(skill_tree.find(s));
        if(cur != string::npos) {
            /// 앞순서에 사용 안한 스킬트리가 존재하거나, 탐색한 인덱스가 이전 스킬트리 인덱스보다 앞에 있을때
            /// -> false 반환
            /// else, 정상적으로 스킬트리 존재 시, prev값 갱신
            if(psd == false || cur < prev) return false;
            else prev = cur;
        } else psd = false;
    }
    return true;
}

int checkSkillTree(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(int i=0; i<skill_trees.size(); i++) {
        if(checkSkill(skill,skill_trees[i])) {
            answer++;
        }
    }
    return answer;
}
