
// MARK: - 다트게임 Lv1 17682

// MARK: swift 문제풀이

/*
 func addValue(_ Ans: inout [Int], _ num: inout Int) {
 Ans.append(num)
 num = 0
 }

 func solution(_ dartResult:String) -> Int {
 var Ans = [Int]()
 let G = Array(dartResult)
 var num = 0

 for i in G.indices {
     let ascii = Int(G[i].asciiValue!) - 48
     if ascii >= 0 && ascii <= 9 {
         num = num * 10 + ascii
     } else if G[i] == "S" {
         addValue(&Ans, &num)
     } else if G[i] == "D" {
         addValue(&Ans, &num)
         Ans[Ans.count-1] *= Ans[Ans.count-1]
     } else if G[i] == "T" {
         addValue(&Ans, &num)
         Ans[Ans.count-1] *= (Ans[Ans.count-1] * Ans[Ans.count-1])
     } else if G[i] == "*" {
         let sIdx = Ans.count-2 > 0 ? Ans.count-2 : 0
         for j in sIdx..<Ans.count { Ans[j] *= 2 }
     } else if G[i] == "#" {
         Ans[Ans.count-1] *= -1
         print(Ans[Ans.count-1])
     }
 }
 return Ans.reduce(0, +)
 }
 */
