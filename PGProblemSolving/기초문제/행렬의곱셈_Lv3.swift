//
//  행렬의곱셈_Lv3.swift
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2020/01/14.
//  Copyright © 2020 MinKyeongTae. All rights reserved.
//

// MARK: 행렬의곱셈 Lv3 문제풀이

/*
import Foundation

func solution(_ arr1:[[Int]], _ arr2:[[Int]]) -> [[Int]] {
    var Ans = [[Int]](repeating: [Int](repeating: 0, count: arr2[0].count), count: arr1.count)
    for i in arr1.indices {
        for k in arr2.indices {
            for j in arr2[0].indices {
                Ans[i][j] += arr1[i][k] * arr2[k][j]
            }
        }
    }
    return Ans
}
*/
