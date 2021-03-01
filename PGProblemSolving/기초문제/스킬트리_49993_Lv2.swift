//
//  자릿수더하기.swift
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 14/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

// MARK: - 스킬트리 : skill tree
/*
extension Character {
    var asciiIndex: Int {
        return Int(self.asciiValue!) - 65
    }
}

extension Array where Element == Character {
    func isValid(skillTree: String, dicList: inout [Int]) -> Bool {
        var prev = 0
        for skill in skillTree {
            if dicList[skill.asciiIndex] > 0 {
                let now = dicList[skill.asciiIndex]
                if now != 0 && prev + 1 != now {
                    return false
                }
                prev = now > 0 ? now : prev
            }
        }

        return true
    }
}

func solution(_ skill:String, _ skill_trees:[String]) -> Int {
    let arr = Array(skill)
    var dicList = [Int](repeating: 0, count: 26)
    var cnt = 1
    skill.forEach { char in
        dicList[char.asciiIndex] = cnt
        cnt += 1
    }
    
    return skill_trees.reduce(into: 0) { (answer, skillTree) in
        answer += arr.isValid(skillTree: skillTree, dicList: &dicList) ? 1 : 0
    }
}
*/
