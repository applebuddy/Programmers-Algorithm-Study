
// MARK: - 크레인인형뽑기게임 Kakao Lv1

// MARK: Stack swift 문제풀이

/*
 import Foundation

 func solution(_ board:[[Int]], _ moves:[Int]) -> Int {
 let len = board.count
 var SV = [[Int]](repeating: [Int](), count: len)
 var Ans = 0
 var basket = [Int]()
 for i in board.indices.reversed() {
     for j in board[i].indices {
         if board[i][j] != 0 { SV[j].append(board[i][j]) }
     }
 }

 for i in moves.indices {
     let idx = moves[i] - 1
     if !SV[idx].isEmpty {
         let doll = SV[idx].last!
         SV[idx].removeLast()
         if !basket.isEmpty {
             if doll == basket.last! { Ans += 2; basket.removeLast() }
             else { basket.append(doll) }
         } else { basket.append(doll) }
     }
 }
 return Ans
 }
 */
