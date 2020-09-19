
/*
 let arr = readLine()!.split(separator: " ").map { Int($0)! }
 let N = arr[0], M = arr[1]
 var G = [[Character]](repeating: [Character](), count: N)
 for i in 0..<N {
 G[i] = Array(readLine()!)
 }
 let K = Int(readLine()!)!
 var Ans = 0
 var C = [Int](repeating: 0, count: 51)

 func convertCol(_ X: Int) {
 for i in 0..<N {
     G[i][X] = G[i][X] == "0" ? "1" : "0"
 }
 }

 func checkRow() {
 var cnt = 0
 for i in G.indices {
     var flag = true
     for j in G[i].indices {
         if G[i][j] == "0" { flag=false; break }
     }
     if flag { cnt += 1 }
 }
 Ans = Ans < cnt ? cnt : Ans
 }

 func DFS(_ X: Int, _ K: Int) {
 if K == 0 {
     checkRow()
     return
 }
 for i in 0..<M {
     convertCol(i)
     if K % 2 == 0 { checkRow() }
     DFS(i,K-1)
     convertCol(i)
 }
 }

 DFS(0, K)
 print(Ans)
 */
