#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> sv;
    string temp = "";
    for(int i=0; i<s.length(); i++){
        if(s[i] != ' '){
            int num = 0;
            if(s[i] != '-'){
                temp = s.substr(i,s.length());
                num = atoi(temp.c_str());
            }else{
                temp = s.substr(i+1,s.length());
                num = (-1)*atoi(temp.c_str());
            }
            cout << num << " ";
            sv.push_back(num); i+=2;
        }
    }
    cout << endl;
    sort(sv.begin(), sv.end());
    for(int i=0; i<sv.size(); i++){
        cout << sv[i] << " ";
    }
    answer += to_string(sv[0]);
    answer += " ";
    answer += to_string(sv[sv.size()-1]);
    
    return answer;
}

int main(){
    solution("-2 -10 20 5");
    return 0;
}
//
//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//string solution(string s) {
//    string answer = "";
//    vector<int> sv;
//    string temp = "";
//    for(int i=0; i<s.length(); i++){
//        if(s[i] != ' '){
//            int num = 0;
//            if(s[i] != '-'){
//                temp = s.substr(i,s.length());
//                num = atoi(temp.c_str());
//            }else{
//                temp = s.substr(i+1,s.length());
//                num = (-1)*atoi(temp.c_str());
//            }
//            cout << num << " ";
//            sv.push_back(num); i++;
//        }
//    }
//    cout << endl;
//    sort(sv.begin(), sv.end());
//    
//    answer += to_string(sv[0]);
//    answer += " ";
//    answer += to_string(sv[sv.size()-1]);
//    // for(vector<int>::iterator iter = sv.begin(); iter!=sv.end();){
//    //     if(*iter == 0){
//    //         sv.erase(iter);
//    //     }else{
//    //         iter++;
//    //     }
//    // }
//    // for(int i=0; i<sv.size(); i++){
//    //     cout << sv[i] << " ";
//    // }
//    return answer;
//}
//
