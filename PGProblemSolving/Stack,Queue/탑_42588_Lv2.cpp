//
//  탑.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 07/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

// MARK: 스택(Stack) 미사용 통과답안 복습;  '19. 10. 11.

/*
#include <string>
#include <vector>

using namespace std;

vector<int> theTower(vector<int> heights) {
    vector<int> answer(heights.size(),0);
    bool flag;
    for(int i=0; i<heights.size(); i++) {
        flag=false;
        for(int j=i-1; j>=0; j--) {
            if(heights[i] < heights[j]) {
                answer[i]=j+1;
                flag=true;
                break;
            }
        }
        if(flag=false) answer[i]=0;
    }
    return answer;
}
 */

///// MARK: 스택(Stack) 미사용 통과답안
//#include <string>
//#include <vector>
//
//using namespace std;
//
//vector<int> towerWithoutStack(vector<int> heights) {
//    vector<int> Ans(heights.size(),0);
//
//    for(int i=heights.size()-1; i>=0; i--) {
//        for(int j=i-1; j>=0; j--) {
//            if(heights[i] < heights[j]) {
//                Ans[i] = j+1;
//                break;
//            }
//        }
//    }
//    return Ans;
//}

//#include <string>
//#include <vector>
//#include <stack>
//
//using namespace std;
//
///// MARK: 스택(Stack) 사용 통과답안
//vector<int> towerWithStack(vector<int> heights) {
//    vector<int> answer;
//    stack<int> stk;
//
//    for(int i=int(heights.size()-1); i>=0; i--){
//        for(int j=i-1; j>=0; j--){
//            if(heights[i]<heights[j]){ // 높은 탑이 발견되면,
//                stk.push(j+1); // 스택에 해당인덱스(0~ 인덱스므로 +1 해준다.)를 넣어주고 break
//                break;
//            }
//        }
//        if(stk.size() != heights.size()-i){ // 사이즈가 안맞으면, 0을 넣는다.
//            stk.push(0);
//        }
//    }
//
//    while(!stk.empty()){
//        answer.push_back(stk.top());
//        stk.pop();
//    }
//    return answer;
//}
