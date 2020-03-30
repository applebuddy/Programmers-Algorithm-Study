//
//  직사각형그리기.swift
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 20/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

// MARK: - 직가각형 그리기

// MARK: 가로 n, 세로 m 길이의 직사각형을 그려라!!

import Foundation

let n = readLine()!.components(separatedBy: [" "]).map { Int($0)! }
let (a, b) = (n[0], n[1])

func drawRect(a: Int, b: Int) {
    for _ in 0 ..< b {
        for _ in 0 ..< a {
            print("*", terminator: "")
        }
        print("")
    }
}
