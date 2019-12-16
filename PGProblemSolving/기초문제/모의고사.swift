//
//  모의고사.swift
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 02/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

import Foundation

let firstArr = [1, 2, 3, 4, 5]
let secondArr = [2, 1, 2, 3, 2, 4, 2, 5]
let thirdArr = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
var countArr = [0, 0, 0]
var ans = [Int]()

func prelliminaryExamination(_ answers: [Int]) -> [Int] {
    for i in answers.indices {
        if firstArr[i % 5] == answers[i] { countArr[0] += 1 }
        if secondArr[i % 8] == answers[i] { countArr[1] += 1 }
        if thirdArr[i % 10] == answers[i] { countArr[2] += 1 }
    }

    for i in countArr.indices {
        if countArr[i] == countArr.max() {
            ans.append(i + 1)
        }
    }

    return ans
}
