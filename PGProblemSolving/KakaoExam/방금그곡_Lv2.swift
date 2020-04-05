//
//  방금그곡_Lv2.swift
//  PGProblemSolving
//
//  Created by MinKyeongTae on 2020/02/05.
//  Copyright © 2020 MinKyeongTae. All rights reserved.
//

// MARK: 방금그곡 Lv2

// MARK: - 정렬 + 문자열처리 문제풀이

/*
import Foundation

struct Music {
    var id: Int
    var title: String
    var song: String
    var length: Int
    init(_ id: Int, _ title: String, _ song: String, _ length: Int) {
        self.id = id
        self.title = title
        self.song = song
        self.length = length
    }
}

func checkMusicList(_ music: Music, _ key: String) -> Bool {
    return music.song.contains(key)
}

func solution(_ m: String, _ musicinfos: [String]) -> String {
    var musicList = [Music]()
    var newM = ""
    let mArr = Array(m).map { String($0) }
    for i in mArr.indices {
        if mArr[i] == "#" { continue }
        if i + 1 < mArr.count, mArr[i + 1] == "#" {
            newM += "\(mArr[i])#"
        } else {
            newM += "\(mArr[i])0"
        }
    }

    for i in musicinfos.indices {
        var title = ""
        var song = "", originSong = ""
        var arr = Array(musicinfos[i]).map { String($0) }
        var originSongArr = [String]()
        var startTime = (0, 0), endTime = (0, 0)
        startTime = (Int(arr[0 ... 1].joined())!, Int(arr[3 ... 4].joined())!)
        endTime = (Int(arr[6 ... 7].joined())!, Int(arr[9 ... 10].joined())!)

        var len = 0, originLen = 0
        if endTime.1 < startTime.1 {
            endTime.0 -= 1
            endTime.1 += 60
        }
        len += endTime.1 - startTime.1
        len += 60 * (endTime.0 - startTime.0)

        for j in 12 ..< arr.count {
            if arr[j] == "," {
                title = arr[12 ..< j].joined()
                originSongArr = Array(arr[j + 1 ..< arr.count])
                break
            }
        }

        for j in originSongArr.indices {
            if originSongArr[j] == "#" { continue }
            originLen += 1
        }

        var newSong = ""
        for j in originSongArr.indices {
            if originSongArr[j] == "#" { continue }
            if j + 1 < originSongArr.count, originSongArr[j + 1] == "#" {
                newSong += "\(originSongArr[j])#"
            } else {
                newSong += "\(originSongArr[j])0"
            }
        }

        let share = len / originLen
        for _ in 0 ..< share {
            song += newSong
        }

        var idx = 0
        for j in originSongArr.indices {
            if idx >= len % originLen { break }
            if originSongArr[j] == "#" { continue }
            if j + 1 < originSongArr.count, originSongArr[j + 1] == "#" {
                song += "\(originSongArr[j])#"
            } else {
                song += "\(originSongArr[j])0"
            }
            idx += 1
        }

        let nowMusic = Music(i, title, song, len)
        musicList.append(nowMusic)
    }

    print(musicList)

    musicList.sort {
        $0.length > $1.length || ($0.length == $1.length && $0.id < $1.id)
    }

    for i in musicList.indices {
        if checkMusicList(musicList[i], newM) {
            return musicList[i].title
        }
    }

    return "(None)"
}
*/

