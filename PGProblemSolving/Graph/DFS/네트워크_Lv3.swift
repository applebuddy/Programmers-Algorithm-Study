//
//  네트워크_Lv3.swift
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2019/11/20.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

// MARK: 네크워크_43162_Lv3

// MARK: - 입력배열 활용 풀이답안
/*
import Foundation

var answer = 0
var C = [Int](repeating: 0, count: 201)

func DFS(_ node: Int, _ computers: inout [[Int]]) {
    C[node] = 1
    for i in computers[node].indices {
        if C[i] == 1 || computers[node][i] == 0 { continue }
        C[i] = 1
        DFS(i, &computers)
    }
}

func solution(_ n:Int, _ computers:[[Int]]) -> Int {
    var Comp = computers
    for i in 0..<n {
        if C[i]==0 {
            C[i]=1
            answer += 1
            DFS(i, &Comp)
        }
    }
    return answer
}
 */

// MARK: - 예전 풀이답안(인접리스트 재구성 후 풀이답안)
/*
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
*/
