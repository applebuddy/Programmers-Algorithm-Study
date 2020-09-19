//
//  소수찾기_42839_Lv2.swift
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2019/11/27.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

// MARK: - 소수찾기 Lv2

// MARK: 단순배열 사용, n배 빠른버전

import Foundation

func solution(_ numbers: String) -> Int {
    let arr = Array(numbers).map { Int(String($0))! }
    let max = Int(arr.sorted(by: >).map { String($0) }.joined())!
    var dic = [Int](repeating: 0, count: 10)
    var Ans = 0
    var P = [Bool](repeating: true, count: max + 1)
    var idx = 2, jdx = idx + idx
    while idx * idx <= max {
        if P[idx] {
            jdx = idx + idx
            while jdx <= max {
                P[jdx] = false
                jdx += idx
            }
        }
        idx += 1
    }

    for i in arr.indices {
        dic[arr[i]] += 1
    }

    for i in 2 ... max {
        if P[i] {
            var num = i
            var tDic = dic
            var isValid = true
            while num > 0 {
                if tDic[num % 10] <= 0 {
                    isValid = false
                    break
                }
                tDic[num % 10] -= 1
                num /= 10
            }

            if isValid { Ans += 1 }
        }
    }

    return Ans
}

// MARK: 딕셔너리 사용, 느린버전

/*
 import Foundation

 var checkDic = [Int: Int]()

 func checkNumber(_ num: Int) -> Bool {
 var tempDic = checkDic
 var N = num
 while N > 0 {
     if tempDic[N % 10] == nil || tempDic[N % 10] == 0 { return false }
     tempDic[N % 10] = tempDic[N % 10]! - 1
     N /= 10
 }
 return true
 }

 func findThePrime(_ numbers: String) -> Int {
 var Ans = 0
 var primeArr = [Bool](repeating: true, count: 10_000_001)
 let strArr = numbers.sorted(by: >).map { String($0) }
 let maxValue = Int(strArr.joined())!

 for i in strArr.indices {
     let num = Int(strArr[i])!
     checkDic[num] = (checkDic[num] ?? 0) + 1
 }

 let sprtValue = Int(sqrt(Double(maxValue)))
 for i in stride(from: 2, through: sprtValue, by: 1) {
     if primeArr[i] == true {
         for j in stride(from: i + i, through: maxValue, by: i) {
             primeArr[j] = false
         }
     }
 }

 for i in 2 ... maxValue {
     if checkNumber(i), primeArr[i] == true {
         Ans += 1
     }
 }

 return Ans
 }
 */
