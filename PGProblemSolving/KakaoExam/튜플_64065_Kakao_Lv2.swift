
// MARK: - 튜플 Kakao Lv2
// MARK: Set swift 문제풀이

/*
import Foundation

func solution(_ s:String) -> [Int] {
    var stk = 0
    let arr = Array(s).map { String($0) }
    var tmpST = Set<String>()
    var tmpStr = ""
    var Ans = [Int]()
    var STV = Array<Set<String>>()
    for i in arr.indices {
        if arr[i] == "{" {
            stk += 1
            continue
        } else if arr[i] == "}" {
            stk -= 1
            if !tmpST.isEmpty || !tmpStr.isEmpty {
                tmpST.insert(tmpStr)
                tmpStr = ""
                STV.append(tmpST)
                tmpST = Set<String>()
            }
            continue
        }

        if stk == 2 {
            if arr[i] == "," {
                tmpST.insert(tmpStr)
                tmpStr = ""
            } else {
                tmpStr += arr[i]
            }
        }
    }

    STV.sort { $0.count < $1.count }
    for st in STV.first! {
        Ans.append(Int(st)!)
    }

    let len = STV.count
    if len > 1 {
        for i in 0..<len-1 {
            Ans.append(Int(STV[i].symmetricDifference(STV[i+1]).joined())!)
        }
    }

    return Ans
}
*/
