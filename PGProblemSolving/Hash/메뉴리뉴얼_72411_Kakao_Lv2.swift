
// MARK: - 메뉴리뉴얼 Kakao Lv2

/*
var stringDic: [[Character]: Int] = [:]
var courseDic = [Bool](repeating: false, count: 11)
var list: [Character] = []
var answer: [String] = []

func DFS(_ idx: Int, _ target: [Character]) {
    if list.count >= 2 && courseDic[list.count] {
        stringDic[list] = (stringDic[list] ?? 0) + 1
    }
    
    var tdx = idx
    while tdx < target.count {
        list.append(target[tdx])
        DFS(tdx+1, target)
        list.removeLast()
        tdx += 1
    }
}

func solution(_ orders:[String], _ course:[Int]) -> [String] {
    let orders = orders.map { $0.sorted() }
    course.forEach { courseDic[$0] = true }
    orders.forEach { order in
        list = []
        let target = Array(order)
        DFS(0, target)
    }
    
    var orderList = [[([Character], Int)]](repeating: [], count: 11)
    stringDic.forEach { (key, value) in
        orderList[key.count].append((key, value))
    }
    
    course.forEach { cIdx in
        orderList[cIdx].sort { $0.1 > $1.1 }
        if orderList[cIdx].isEmpty { return }
        let mxCount = orderList[cIdx].first!.1
        var oIdx = 0
        if mxCount < 2 { return }
        while oIdx < orderList[cIdx].count {
            if orderList[cIdx][oIdx].1 == mxCount {
                answer.append(String(orderList[cIdx][oIdx].0))
            }
            oIdx += 1
        }
    }
    
    return answer.sorted()
}
*/
