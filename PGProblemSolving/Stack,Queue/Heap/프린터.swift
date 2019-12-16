//
//  printer.swift
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 13/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

// MARK: - 프린터 : Heap Problem

import Foundation

func printer(_ priorities: [Int], _ location: Int) -> Int {
    let pArr = priorities
    var pQueue = priorities.sorted(by: >)

    var Ans = 0
    var idx = 0
    var cnt = 1
    while !pQueue.isEmpty {
        if pQueue[0] == pArr[idx] {
            pQueue.removeFirst()
            if idx == location {
                Ans = cnt
                break
            }
            cnt += 1
        }
        if idx == pArr.count - 1 { idx = 0 }
        else { idx += 1 }
    }
    return Ans
}
