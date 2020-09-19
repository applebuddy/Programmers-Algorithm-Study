
// MARK: - 오픈채팅방_42888 Lv3

// MARK: - Hash swift 문제풀이

/*
 func solution(_ record: [String]) -> [String] {
 var reqList: [(Bool, String)] = []
 var reqDic: [String: String] = [:]
 var Ans: [String] = []

 for req in record {
     let arr = req.split(separator: " ").map { String($0) }

     if arr[0] == "Enter" {
         reqList.append((true, arr[1]))
     } else if arr[0] == "Leave" {
         reqList.append((false, arr[1]))
         continue
     }
     reqDic[arr[1]] = arr[2]
 }

 for req in reqList {
     if req.0 {
         Ans.append("\(reqDic[req.1]!)님이 들어왔습니다.")
     } else {
         Ans.append("\(reqDic[req.1]!)님이 나갔습니다.")
     }
 }
 return Ans
 }
 */
