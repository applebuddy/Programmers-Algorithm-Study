//
//  printer.swift
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 13/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

// MARK: 프린터 : Heap Problem

// '19. 12. 16. 문제 풀이

import Foundation

func solution(_ priorities: [Int], _ location: Int) -> Int {
    var maxQueue = priorities.sorted()
    var pArr = [(Int, Int)]()
    for i in priorities.indices { pArr.append((i, priorities[i])) }

    var Ans = 0
    while !maxQueue.isEmpty {
        if pArr.first!.1 == maxQueue.last! {
            Ans += 1
            if pArr.first!.0 == location { break }
            else {
                pArr.removeFirst()
                maxQueue.removeLast()
            }
        } else {
            var front = pArr.first!
            pArr.removeFirst()
            pArr.append(front)
        }
    }

    return Ans
}

/*
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
 */
