
// MARK: - 가장 먼 노드 49189

// MARK: BFS swift 복습 문제풀이

/*
 import Foundation

 var Q = [Int]()
 var MX = 0

 func BFS(_ G: inout [[Int]], _ C: inout [Int], _ CC: inout [Int]) {
 C[1] = 1
 var cur = 0
 Q.append(1)
 while cur < Q.count {
     let now = Q[cur]
     cur += 1
     for i in G[now].indices {
         let next = G[now][i]
         if C[next] == 0 {
             C[next] = C[now] + 1
             CC[C[next]] += 1
             MX = MX < C[next] ? C[next] : MX
             Q.append(next)
         }
     }
 }
 }

 func solution(_ n:Int, _ edge:[[Int]]) -> Int {
 var G = [[Int]](repeating: [Int](), count: n+1)
 var C = [Int](repeating: 0, count: n+1)
 var CC = [Int](repeating: 0, count: n+1)
 for i in edge.indices {
     G[edge[i][0]].append(edge[i][1])
     G[edge[i][1]].append(edge[i][0])
 }

 BFS(&G, &C, &CC)
 return CC[MX]
 }
 */
