//
//  H-Index_Lv2.swift
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2019/12/18.
//  Copyright © 2019 MinKyeongTae. All rights reserved.
//

// MARK: H-Index Lv2

/*
 import Foundation

 func solution(_ citations:[Int]) -> Int {
 let citat = citations.sorted()
 let citatCnt = citations.count
 for H in stride(from: 1000, to: 0, by: -1) {
     var qCnt = 0
     var flag = true
     for j in citat.indices {
         if H <= citat[j] { qCnt += 1 }
         else {
             if citat[j] > H {
                 flag = false
                 break
             }
         }
     }
     if H <= qCnt && flag { return H }
 }

 return 0
 }
 */
