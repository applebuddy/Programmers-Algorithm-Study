//
//  소수만들기_Lv2.swift
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 19/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

// MARK: - 소수만들기

// MARK: nums 배열에 존재하는 숫자 3개를 이용해 소수를 만드는 경우의 수를 출력하라!!

/// * nums 배열에 존재하는 숫자는 중복숫자가 존재하지 않는다.

import Foundation

var MAX = 3001
func solution(_ nums: [Int]) -> Int {
    var Ans = 0
    var prime = [Bool](repeating: false, count: MAX)

    for i in stride(from: 2, through: Int(Double(MAX).squareRoot()), by: 1) {
        if prime[i] == false {
            for j in stride(from: i + i, through: MAX, by: i) {
                prime[j] = true
            }
        }
    }

    for i in nums.indices {
        for j in i + 1 ..< nums.count {
            for k in j + 1 ..< nums.count {
                if prime[nums[i] + nums[j] + nums[k]] == false { Ans += 1 }
            }
        }
    }
    return Ans
}
