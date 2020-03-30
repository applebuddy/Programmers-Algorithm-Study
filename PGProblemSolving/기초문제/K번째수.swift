//
//  K번째수.swift
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 02/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

// MARK: - K번째 수

import Foundation

/// * Map, $ 인자값을 사용하여 간결하게 구현할 수 있다.
func getKorderNumbers(_ array: [Int], _ commands: [[Int]]) -> [Int] {
    return commands.map {
        Array(array[($0[0] - 1) ... ($0[1] - 1)]).sorted()[$0[2] - 1]
    }
}

// func solution(_ array:[Int], _ commands:[[Int]]) -> [Int] {
//    var ansArr = [Int]()
//    for (_,command) in commands.enumerated() {
//        var subArr = [Int]()
//        subArr = Array(array[(command[0]-1) ... (command[1]-1)])
//        ansArr.append(subArr.sorted()[command[2]-1])
//    }
//    return ansArr
// }
