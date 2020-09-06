
// MARK: - 키패드 누르기 67256

// MARK: Implementation swift 문제풀이 - O(N) timeComplexity

func isLeftPos(_ num: Int) -> Bool {
    return num == 1 || num == 4 || num == 7
}

func isRightPos(_ num: Int) -> Bool {
    return num == 3 || num == 6 || num == 9
}

func solution(_ numbers:[Int], _ hand:String) -> String {
    var L = 10, R = 11
    let pos = [(3,1), (0,0), (0,1), (0,2),
               (1,0), (1,1), (1,2),
               (2,0), (2,1), (2,2), (3,0), (3,2)]
    var Ans = ""
    
    numbers.forEach {
        let leftDist = Int(abs(Double((pos[$0].0 - pos[L].0)))
            + abs(Double((pos[$0].1 - pos[L].1))))
        let rightDist = Int(abs(Double((pos[$0].0 - pos[R].0)))
            + abs(Double((pos[$0].1 - pos[R].1))))
        if isLeftPos($0) {
            L = $0
            Ans += "L"
        } else if isRightPos($0) {
            R = $0
            Ans += "R"
        } else if hand == "left" {
            if leftDist <= rightDist {
                L = $0
                Ans += "L"
            } else {
                R = $0
                Ans += "R"
            }
        } else {
            if leftDist >= rightDist {
                R = $0
                Ans += "R"
            } else {
                L = $0
                Ans += "L"
            }
        }
    }
    return Ans
}
