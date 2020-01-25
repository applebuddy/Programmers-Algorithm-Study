//
//  입국심사_43238_Lv3.swift
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2019/11/24.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

// MARK: 입국심사 Lv3 43238 Lv3

// MARK: - 입국심사 복습풀이답안
/*
import Foundation

func solution(_ n:Int, _ times:[Int]) -> Int64 {
    var left = 1, right = times.max()! * n
    var answer = right
    while left <= right {
        let mid = (left + right) / 2
        var tot = 0
        for t in times { tot += mid / t }
        if tot < n {
            left = mid + 1
        } else {
            right = mid - 1
            answer = answer > mid ? mid : answer
        }
    }
    
    return Int64(answer)
}
*/

/*
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
*/
