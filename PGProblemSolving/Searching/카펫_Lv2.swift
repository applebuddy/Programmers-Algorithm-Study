//
//  카펫.swift
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 17/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

// MARK: - 카펫

/// * Problem Description
//  -Leo는 카펫을 사러 갔다가 아래 그림과 같이 중앙에는 빨간색으로 칠해져 있고 모서리는 갈색으로 칠해져 있는 격자 모양 카펫을 봤습니다.
//  -Leo는 집으로 돌아와서 아까 본 카펫의 빨간색과 갈색으로 색칠된 격자의 개수는 기억했지만, 전체 카펫의 크기는 기억하지 못했습니다.
//  -Leo가 본 카펫에서 갈색 격자의 수 brown, 빨간색 격자의 수 red가 매개변수로 주어질 때 카펫의 가로, 세로 크기를 순서대로 배열에 담아 return 하도록 solution 함수를 작성해주세요.

import Foundation

func carpet(_ brown: Int, _ red: Int) -> [Int] {
    var Ans = [Int]()
    for i in 3 ..< brown {
        let sum = brown + red
        if sum % i == 0 {
            let j = sum / i
            if (j - 2) * (i - 2) == red {
                Ans.append(i)
                Ans.append(j)
            }
        }
    }
    return Ans[0] > Ans[1] ? Ans : [Ans[1], Ans[0]]
}
