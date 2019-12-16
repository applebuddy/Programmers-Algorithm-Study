//
//  최댓값과최솟값.swift
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 19/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

import Foundation

func getMinMaxNumber(_ s: String) -> String {
    let Ans = s.components(separatedBy: " ").map { Int($0)! }.sorted()
    return "\(Ans[0]) \(Ans[Ans.count - 1])"
}
