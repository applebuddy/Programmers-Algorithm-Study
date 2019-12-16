//
//  다리를지나는트럭.swift
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 13/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

// MARK: - 다리를 지나는 트럭_42583 : Queue Algorithm Problem

/*
 import Foundation

 func TrucksPassingBridge(_ bridge_length: Int, _ weight: Int, _ truck_weights: [Int]) -> Int {
 var bridge = [Int]()
 var truckWs = truck_weights
 var sum = 0
 var Ans = 0
 for i in truck_weights.indices {
     while true {
         // 진입하는 트럭의 무게허용 가능일 경우
         if sum + truckWs[i] <= weight {
             bridge.append(truckWs[i])
             sum += truckWs[i]
             Ans += 1
             break
         } else {
             // 트럭의 무게중량 초과 + 큐 길이가 찼을때
             if bridge.count >= bridge_length {
                 sum -= bridge[0]
                 bridge.removeFirst()
                 // 트럭의 무게중량 초과 + 큐 길이가 안 찼을때
             } else {
                 bridge.append(0)
                 Ans += 1
             }
         }
     }
 }

 Ans += bridge_length
 return Ans
 }
 */
