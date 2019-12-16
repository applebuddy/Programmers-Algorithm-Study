//
//  기지국설치_Lv3.swift
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 23/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

///// MARK: - 기지국설치 : Greedy Algorithm Problem
///// MARK: 최소한의 기지국을 설치하라!!!
///// * n : 길이, stations : 기 설치 기지국 위치, w : 기지국 좌/우 송신범위

import Foundation

func solution(_ n: Int, _ stations: [Int], _ w: Int) -> Int {
    var Ans = 0
    var cur = 1
    var telIdx = 0

    while cur <= n {
        if telIdx < stations.count, cur >= stations[telIdx] - w {
            cur = stations[telIdx] + w + 1
            telIdx += 1
        } else {
            cur += w * 2 + 1
            Ans += 1
        }
    }
    return Ans
}
