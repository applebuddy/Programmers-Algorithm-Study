////
////  오픈채팅방.cpp
////  ProgrammersAlgorithmPractice
////
////  Created by MinKyeongTae on 20/09/2019.
////  Copyright © 2019 Min Kyeong Tae. All rights reserved.
////
//
///// MARK: - 오픈채팅방
///// MARK: (2018년)KAKAO BLIND RECRUITMENT
//
///// 오픈채팅방 답안, '19. 09. 20.
//#include <iostream>
//#include <string>
//#include <vector>
//#include <sstream>
//#include <map>
//
//using namespace std;
//
//map<string,string> Map;
//
//void drawText(vector<vector<string>> & Ans) {
//    
//    for(int i=0; i<Ans.size(); i++) {
//        if(Ans[i][0]=="Enter") {
//            printf("%s님이 들어왔습니다.\n", Map[Ans[i][1]].c_str());
//        } else if(Ans[i][0]=="Leave") {
//            printf("%s님이 나갔습니다.\n", Map[Ans[i][1]].c_str());
//        }
//    }
//}
//
//
//vector<string> solution(vector<string> record) {
//    vector<string> answer;
//    vector<vector<string>> Ans(record.size(),vector<string>());
//    for(int i=0; i<record.size(); i++) {
//        string temp;
//        for(stringstream ss(record[i]); ss >> temp;) {
//            printf("%s ",temp.c_str());
//            Ans[i].push_back(temp);
//        }
//        printf("\n");
//    }
//    
//    for(int i=0; i<Ans.size(); i++) {
//        if(Ans[i][0]=="Enter") {
//            Map[Ans[i][1]] = Ans[i][2];
//        } else if(Ans[i][0]=="Leave") {
//            continue;
//        } else if(Ans[i][0]=="Change") {
//            Map[Ans[i][1]] = Ans[i][2];
//        }
//    }
//    
//    drawText(Ans);
//    return answer;
//}
//
//int main() {
//    solution({"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"});
//    return 0;
//}
