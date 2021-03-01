
// MARK: - 순위검색 Kakao Lv2

/*
typealias Pair = ([String], Int)
var dic: [String: [Int]] = [:]

let writeCase: ((Pair) -> ()) = { pair in
    (0..<16).forEach { idx in
        var key = ""
        var bit = idx
        (0..<4).reversed().forEach { jdx in
            if bit == 0 || bit % 2 == 0 {
                key = "-" + key
            } else {
                key = pair.0[jdx] + key
            }
            bit /= 2
        }
        dic[key, default: []].append(pair.1)
    }
}

let stoi: ((String) -> Int) = { string in
    var result = 0
    string.forEach {
        result = result * 10 + Int($0.asciiValue!) - 48
    }
    return result
}

let stoKey: ((String) -> Pair) = { string in
    var result: Pair = ([], 0)
    var temp = ""
    string.forEach { char in
        let ascii = Int(char.asciiValue!)
        if ascii >= 48 && ascii <= 57 {
            result.1 = result.1 * 10 + ascii - 48
            return
        }
        if char == "-" {
            result.0.append("-")
            return
        }
        if char == " " {
            if !temp.isEmpty && temp != "and" {
                result.0.append(temp)
            }
            temp = ""
            return
        }
                    
        temp += "\(char)"
    }
    result.0.append(temp)
    return result
}

func getCount(_ list: inout [Int], _ score: Int) -> Int {
    var (left, right) = (0, list.count - 1)
    while left <= right {
        let mid = (left + right) / 2
        if list[mid] >= score {
            right = mid - 1
        } else {
            left = mid + 1
        }
    }
    return list.count - right - 1
}

func solution(_ info: [String], _ query: [String]) -> [Int] {
    info.forEach {
        writeCase(stoKey($0))
    }
    
    for (key, _) in dic {
        dic[key]!.sort()
    }
    
    let queryList = query.reduce(into: [Pair]()) {
        $0.append(stoKey($1))
    }
    
    return queryList.reduce(into: [Int]()) { (answer, query) in
        var list = dic[query.0.joined()]
        if list == nil { answer.append(0); return }
        answer.append(getCount(&list!, query.1))
    }
}
*/
