//
//  체육복.swift
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 02/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

// MARK: - 체육복

import Foundation

func gymSuit(_ n: Int, _ lost: [Int], _ reserve: [Int]) -> Int {
    var ansArr = [Int](repeating: 1, count: n)
    var ans = 0

    for i in reserve.indices {
        ansArr[reserve[i] - 1] += 1
    }

    for i in lost.indices {
        ansArr[lost[i] - 1] -= 1
    }

    for (key, value) in ansArr.enumerated() {
        if key != 0, value < 1 {
            if ansArr[key - 1] > 1 {
                ansArr[key - 1] -= 1
                ansArr[key] += 1
            }
        }

        // 스위프트는 띄여쓰기 해야함
        if key != ansArr.count - 1, value < 1 {
            if ansArr[key + 1] > 1 {
                ansArr[key + 1] -= 1
                ansArr[key] += 1
            }
        }
    }

    for (_, value) in ansArr.enumerated() {
        if value >= 1 {
            ans += 1
        }
    }

    return ans
}
