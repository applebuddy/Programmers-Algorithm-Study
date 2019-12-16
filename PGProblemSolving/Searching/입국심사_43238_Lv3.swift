//
//  입국심사_43238_Lv3.swift
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2019/11/24.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

// MARK: - 입국심사 43238 Lv3

import Foundation

func solution(_ n: Int, _ times: [Int]) -> Int64 {
    var max = 0, sum = 0
    for i in times.indices { max = max < times[i] ? times[i] : max }
    var left = 1, right = max * n, Ans = right
    while left <= right {
        sum = 0
        let mid = (left + right) / 2
        for i in times.indices { sum += (mid / times[i]) }
        if sum >= n {
            Ans = Ans > mid ? mid : Ans
            right = mid - 1
        } else { left = mid + 1 }
    }
    return Int64(Ans)
}
