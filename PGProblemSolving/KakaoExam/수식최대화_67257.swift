
// MARK: - 수식최대화 67257

// MARK: DFS swift 문제풀이

import Foundation

let mxLen = 3
var input = [Character]()
var vList = [Int]()
var cList = [Character]()
var Ans = 0

var dic: [Bool] = [false, false, false]
var arr: [Int] = []

func calcValue(_ standard: inout [Int]) -> Int {
    let pDic: [Character: Int] = ["-": standard[0], "+": standard[1], "*": standard[2]]
    var tv: [Int] = vList
    var tc: [Character] = cList
    for p in 0 ..< mxLen {
        var ttv: [Int] = [tv[0]]
        var ttc = [Character]()
        var kdx = 0
        for jdx in tc.indices {
            let code = tc[jdx]
            if pDic[tc[jdx]] == p {
                var result = 0
                if code == "-" {
                    result = ttv.last! - tv[kdx + 1]
                } else if code == "+" {
                    result = ttv.last! + tv[kdx + 1]
                } else {
                    result = ttv.last! * tv[kdx + 1]
                }

                ttv[ttv.count - 1] = result
            } else {
                ttc.append(tc[jdx])
                ttv.append(tv[jdx + 1])
            }
            kdx += 1
        }

        if ttv.count == 1 {
            return ttv.first ?? 0
        }

        tc = ttc
        tv = ttv
    }

    return tv.first ?? 0
}

func DFS(_ idx: Int, _: Int) {
    if idx >= mxLen {
        var now = calcValue(&arr)
        now = now > 0 ? now : now * -1
        Ans = Ans > now ? Ans : now
        return
    }

    for i in 0 ..< mxLen {
        if dic[i] == true { continue }
        dic[i] = true
        arr.append(i)
        DFS(idx + 1, i)
        arr.removeLast()
        dic[i] = false
    }
}

func solution(_ expression: String) -> Int64 {
    input = Array(expression)
    var tmp = 0
    for ch in input {
        let ascii = Int(ch.asciiValue!) - 48
        if ascii <= 9, ascii >= 0 {
            tmp = tmp * 10 + ascii
        } else {
            cList.append(ch)
            vList.append(tmp)
            tmp = 0
        }
    }
    vList.append(tmp)

    DFS(0, 0)
    return Int64(Ans)
}

print(solution("100-200*300-500+20"))
