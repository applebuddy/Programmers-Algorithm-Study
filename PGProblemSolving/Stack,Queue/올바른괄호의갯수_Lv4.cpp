//
//  올바른괄호의갯수.cpp
//  ProgrammersAlgorithmPractice
//
//  Created by MinKyeongTae on 19/09/2019.
//  Copyright © 2019 Min Kyeong Tae. All rights reserved.
//

/// MARK: - 올바른 괄호의 갯수 : 카탈린 알고리즘
/// '{', '}' 각각 n개를 갖고 있는 올바른 괄호의 갯수 경우의 수를 출력하라!!

//// * 경우의 수 + 괄호내용 출력 버전)
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int Ans = 0;
//char str[30];
//void getBrace(int idx, int open, int close) {
//    if(open == 0) {
//        while(close--) str[idx++] = '}';
//        Ans++;
//        printf("%s\n",str);
//        return;
//    }
//    
//    str[idx] = '{';
//    getBrace(idx+1, open-1, close);
//    
//    if(open < close) {
//        str[idx] = '}';
//        getBrace(idx+1, open, close-1);
//    }
//}

//int main() {
//    /// 괄호쌍의 갯수 입력
//    int n = 3;
//    getBrace(0,n,n);
//    return Ans;
//}


///// * 경우의 수만 출력 버전)
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int Ans = 0;
//
//void getBrace(int idx, int open, int close) {
//    if(open == 0) {
//        Ans++;
//        return;
//    }
//
//    getBrace(idx+1, open-1, close);
//
//    if(open < close) {
//        getBrace(idx+1, open, close-1);
//    }
//}


//#include <string>
//#include <vector>
//
//using namespace std;
//
//// {{{}}} {{}{}} {{}}{} {}{}{}
//// ★ () 괄호닫기 경우의 수 출력하기
//
//int Ans = 0;
//
//char s[1000];
//void go(int idx, int o, int c){
//
//    /// open brace가 0이 되면, close brace도 동등하게 존재해야 하므로, close brace를 메꿔준다.
//    if(o==0){
//        while(c--){
//            s[idx++]='}';
//        }
//        Ans++;
//        printf("%s\n",s);
//        return;
//    }
//
//    // 맨 처음에는 '{'가 기본적으로 들어가야 한다.
//    s[idx]='{';
//    // '{'브레이스 하나 사용했으므로 open Brace 하나 제거
//    go(idx+1,o-1,c);
//
//    // '{'브레이스가 적으면 close Brace를 씌우는 경우의 수도 고려한다.
//    if(o<c){
//        s[idx]='}';
//        go(idx+1,o,c-1);
//    }
//}
//
//int main() {
//    int n;
//    memset(s,0,sizeof(s));
//    scanf("%d", &n);
//
//    // open Brace, close Brace Equal == n
//    go(0, n, n);
//    printf("%d\n",Ans);
//    return 0;
//}

