
// MARK: - 불량사용자 Kakao Lv3
// MARK: DFS + Hash + Set swift 문제풀이

/*
import Foundation

var banList = [[String]]()
var dic = [String: Bool]()
var ST = Set<Set<String>>()
var tList = Set<String>()
var bListLen = 0

func chkId(_ uId: String, _ bId: String) -> Bool {
    let uArr = Array(uId)
    let bArr = Array(bId)
    let uLen = uArr.count
    let bLen = bArr.count
    if uLen != bLen { return false }
    for i in uArr.indices {
        if bArr[i] == "*" { continue }
        if uArr[i] != bArr[i] { return false }
    }
    return true
}

func DFS(_ idx: Int) {
    if idx >= bListLen {
        ST.insert(tList)
        return
    }
    
    for i in banList[idx].indices {
        let now = banList[idx][i]
        if dic[now] != nil { continue }
        dic[now] = true
        tList.insert(now)
        DFS(idx+1)
        dic[now] = nil
        tList.remove(now)
    }
}

func solution(_ user_id:[String], _ banned_id:[String]) -> Int {
    
    for i in banned_id.indices {
        var tId = [String]()
        for j in user_id.indices {
            if chkId(user_id[j], banned_id[i]) {
                tId.append(user_id[j])
            }
        }
        banList.append(tId)
    }
    
    bListLen = banList.count
    DFS(0)
    
    return ST.count
}
*/
