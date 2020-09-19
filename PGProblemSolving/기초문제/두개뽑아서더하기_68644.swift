
// MARK: - 두 개 뽑아서 더하기

// MARK: swift 문제풀이

import Foundation

func solutionWithSet(_ numbers:[Int]) -> [Int] {
    var st = Set<Int>()
    for idx in 0 ..< numbers.count-1 {
        for jdx in idx+1 ..< numbers.count {
            st.insert(numbers[idx] + numbers[jdx])
        }
    }
    
    return st.sorted()
}

func solutionWithDic(_ numbers: [Int]) -> [Int] {
    var dic = [Int: Bool]()
    for idx in 0 ..< numbers.count - 1 {
        for jdx in idx + 1 ..< numbers.count {
            dic[numbers[idx] + numbers[jdx]] = true
        }
    }

    return dic.map { $0.key }.sorted()
}

