//
//  예산.swift
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 13/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

// MARK: - 예산

// 현재의 예산으로 최대한의 부서를 지원하라!!

import Foundation

func budget(_ d: [Int], _ budget: Int) -> Int {
    var money = budget
    var Ans = 0
    let sArr = d.sorted()
    for i in sArr.indices {
        if money >= sArr[i] {
            money -= sArr[i]
            Ans += 1
        } else { break }
    }
    return Ans
}
