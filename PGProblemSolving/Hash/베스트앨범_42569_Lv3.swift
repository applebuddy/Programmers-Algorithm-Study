//
//  베스트앨범_42569_Lv3.swift
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2020/03/11.
//  Copyright © 2020 MinKyeongTae. All rights reserved.
//

// MARK: - 베스트앨범 42569

// MARK: Hash swift 문제풀이

/*
 import Foundation

 struct Album {
 var index = 0
 var play = 0
 init(_ index: Int, _ play: Int) {
     self.index = index
     self.play = play
 }
 }

 func solution(_ genres:[String], _ plays:[Int]) -> [Int] {
 var dic = [String: [Album]]()
 var tot = [String: Int]()

 for i in genres.indices {
     let genre = genres[i]
     let play = plays[i]
     let nowAlbum = Album(i, play)
     var genreArr = dic[genre]==nil ? [Album]() : dic[genre]!
     genreArr.append(nowAlbum)
     dic[genre] = genreArr
     tot[genre] = (tot[genre] ?? 0) + play
 }

 var genreCArr = [(String,Int)]()
 for (key,value) in tot {
     genreCArr.append((key, value))
 }

 genreCArr.sort { $0.1 > $1.1 }
 var Ans = [Int]()
 for i in genreCArr.indices {
     var nowGenre = dic[genreCArr[i].0]!
     nowGenre.sort { $0.play > $1.play || ($0.play == $1.play && $0.index < $1.index) }
     for j in 0..<min(nowGenre.count, 2) {
         Ans.append(nowGenre[j].index)
     }
 }

 return Ans
 }
 */
