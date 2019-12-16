//
//  N-Queen.swift
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2019/11/29.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

// MARK: - 단순 DFS(백트래킹) 활용, 통과 답안

import Foundation

var answer = 0
var length = 0
var arr = [[Int]]()

func placeQueen(_ x: Int, _ y: Int, _ checkArr: [[Int]]) -> Bool {
    if checkArr[x][y] == 1 { return false }

    for i in 0 ..< length {
        if i != x { if checkArr[i][y] == 1 { return false } }
        if i != y { if checkArr[x][i] == 1 { return false } }
    }

    var startX = x + 1
    var startY = y + 1
    while startX >= 0, startX < length, startY >= 0, startY < length {
        if checkArr[startX][startY] == 1 { return false }
        startX += 1
        startY += 1
    }

    startX = x - 1
    startY = y - 1
    while startX >= 0, startX < length, startY >= 0, startY < length {
        if checkArr[startX][startY] == 1 { return false }
        startX -= 1
        startY -= 1
    }

    startX = x + 1
    startY = y - 1
    while startX >= 0, startX < length, startY >= 0, startY < length {
        if checkArr[startX][startY] == 1 { return false }
        startX += 1
        startY -= 1
    }

    startX = x - 1
    startY = y + 1
    while startX >= 0, startX < length, startY >= 0, startY < length {
        if checkArr[startX][startY] == 1 { return false }
        startX -= 1
        startY += 1
    }

    return true
}

func DFS(_ start: Int, _ count: Int) {
    if count >= length {
        answer += 1
        return
    }

    var checkArr = arr
    let beforeArr = checkArr
    for i in start ..< length {
        if placeQueen(count, i, checkArr) {
            checkArr[count][i] = 1
            arr = checkArr
            DFS(0, count + 1)
        }
        checkArr[count][i] = 0
        arr = beforeArr
    }
}

func NQueen2(_ n: Int) -> Int {
    if n <= 1 { return n }
    arr = [[Int]](repeating: [Int](repeating: 0, count: n), count: n)
    length = n

    DFS(0, 0)
    return answer
}

// MARK: isSuperSet 기능 활용, 맨끝 1개 시간초과 제외 해결 답안

/*
 import Foundation

 var answer = 0
 var length = 0

 func placeQueen(_ x: Int, _ y: Int, _ checkArr: inout [[Int]]) -> Bool {
 if checkArr[x][y] == 1 { return false }
 checkArr[x][y] = 1

 for i in 0..<length {
     if i != x { if checkArr[i][y] == 1 { return false } }
     if i != y { if checkArr[x][i] == 1 { return false } }
 }

 var startX = x + 1
 var startY = y + 1
 while(startX >= 0 && startX < length && startY >= 0 && startY < length) {
     if checkArr[startX][startY] == 1 { return false }
     startX += 1
     startY += 1
 }

 startX = x - 1
 startY = y - 1
 while(startX >= 0 && startX < length && startY >= 0 && startY < length) {
     if checkArr[startX][startY] == 1 { return false }
     startX -= 1
     startY -= 1
 }

 startX = x + 1
 startY = y - 1
 while(startX >= 0 && startX < length && startY >= 0 && startY < length) {
     if checkArr[startX][startY] == 1 { return false }
     startX += 1
     startY -= 1
 }

 startX = x - 1
 startY = y + 1
 while(startX >= 0 && startX < length && startY >= 0 && startY < length) {
     if checkArr[startX][startY] == 1 { return false }
     startX -= 1
     startY += 1
 }

 return true
 }

 func DFS(_ start: Int, _ count: Int, _ orderSet: inout Set<Int>, _ checkArr: inout [[Int]]) {
 if count >= length {
     answer += 1
     return
 }

 var beforeArr = checkArr
 for i in start..<length {
     if(orderSet.isSuperset(of: Set([i]))) { continue }
     orderSet.insert(i)
     if placeQueen(count, i, &checkArr) { DFS(0, count+1, &orderSet, &checkArr) }
     orderSet.remove(i)
     checkArr = beforeArr
 }
 }

 func solution(_ n:Int) -> Int {
 if n <= 1 { return n }
 var arr = [[Int]](repeating: [Int](repeating: 0, count: n), count: n)
 var orderSet = Set<Int>()
 length = n

 DFS(0, 0, &orderSet, &arr)
 return answer
 }
 */
