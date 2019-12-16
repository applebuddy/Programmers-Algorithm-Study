//
//  네트워크_Lv3.swift
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2019/11/20.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

// MARK: - 네크워크_43162_Lv3

import Foundation

var G = [[Int]](repeating: [Int](), count: 201)
var C = [Int](repeating: 0, count: 201)

func DFS(_ node: Int) {
    C[node] = 1
    for i in G[node].indices {
        let nextNode = G[node][i]
        if C[nextNode] == 0 {
            C[nextNode] += 1
            DFS(nextNode)
        }
    }
    return
}

func solution(_: Int, _ computers: [[Int]]) -> Int {
    var Ans = 0
    for i in computers.indices {
        for j in computers[i].indices {
            if computers[i][j] == 1 {
                G[i].append(j)
            }
        }
    }

    for i in computers.indices {
        if C[i] == 0 { Ans += 1 }
        DFS(i)
    }

    return Ans
}
