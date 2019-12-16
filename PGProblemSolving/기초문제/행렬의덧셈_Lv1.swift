//
//  행렬의덧셈_Lv1.swift
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 19/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

// MARK: - 행렬의 덧셈

// MARK: 행렬의 행/열 크기가 같은 2차원 배열, arr1, arr2의 행렬합 결과를 출력하라!!

import Foundation

func sumOfMetrix(_ arr1: [[Int]], _ arr2: [[Int]]) -> [[Int]] {
    var Ans = [[Int]](repeating: [Int](), count: arr1.count)
    for i in arr1.indices {
        for j in arr1[i].indices {
            Ans[i].append(arr1[i][j] + arr2[i][j])
        }
    }
    return Ans
}
