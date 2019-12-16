#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// ★우선순위ㅣ 큐를 사용한 경우

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    
    for(auto v : scoville)
        q.push(v);
    
    while(q.top()<K){
        if(q.size()==1) return -1;
        
        int first = q.top();
        q.pop();
        int second = q.top();
        q.pop();
        q.push(first+second*2);
        answer++;
    }
    return answer;
}

//// ☆우선순위 큐(힙)을 사용하지 않은 경우... 효율성테스트에서 떨어질 수 있다.
//bool check(vector<int>& test, int& k){
//    for(int i=0; i<test.size(); i++){
//        if(test[i] < k){
//            return false;
//        }
//    }
//    return true;
//}
//
//int solution(vector<int> scoville, int K) {
//    int answer = 0;
//    vector<int> &s = scoville;
//
//    while(check(s,K)==false){
//        sort(s.begin(), s.end());
//
//        if(s.size() >= 2){
//            s[0] = s[0] + s[1]*2;
//            s.erase(s.begin()+1);
//        }else{
//            return -1;
//        }
//        answer++;
//    }
//    cout << "answer : " << answer << endl;
//    return answer;
//}
//
//int mainc(){
//    int s,K;
//    vector<int> scoville;
//    cin>>s;
//    for(int i=0; i<s; i++){
//        int n;
//        cin >> n;
//        scoville.push_back(n);
//    }
//    cin >> K;
//    solution(scoville,K);
//
//    return 0;
//}
