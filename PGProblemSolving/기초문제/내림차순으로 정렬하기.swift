//
//  File.swift
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 12/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

// MARK: - 내림차순으로 정렬하기

import Foundation

func descendingOrder(_ s: String) -> String {
    // return Array(s).sorted(by: >).map { String($0) }.joined()
    return String(s.sorted(by: >))
}
