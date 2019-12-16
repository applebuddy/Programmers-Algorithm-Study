
// MARK: - 체육복 : Greedy Problem
// MARK: n명의 학생, 체육복은 기본적으로 한벌씩 있으나, lost, reserve 인덱스의 학생들은 여벌이 있거나 잃어버진 학생이 있다.
// * 체육복은 양 옆 번호의 학생들에게만 빌려줄 수 있다. (1번 학생은 2번에게만, 2번학생은 1/3번 학생으로부터 체육복을 빌릴 수 있다.)
// -> 최대한 많은 사람이 체육복을 입을 수 있도록 한 뒤 그 학생의 수를 출력해라!
// ∙ 19년 중순 풀이 및 공부한 문제

#include <string>
#include <vector>
using namespace std;
int gymSuitOld(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    // 0] 학생의 체육복 정보를 저장할 벡터를 초기화한다.(초기 값 1로 설정)
    vector<int> student(n,1);
    
    // 1] 학생 별 체육복의 갯수를 셋팅한다.
    for(int i : lost){
        student[i]--; // 잃어버린 학생의 체육복-- (0이 됨)
    }
    for(int i : reserve){
        student[i]++; // 여분이 있는 학생의 체육복++ (2가 됨)
    }
    
    // 2] 좌측학생 > 우측학생을 우선으로 체육복을 빌려줄지 판단한다.
    for(int i=0; i<student.size(); i++){
        if(i!=0 && student[i-1]==0){ // 맨 앞사람이 아닌 사람 중 앞사람이 옷이 부족하다면
            if(student[i] == 2){     // 여분이 있을경우 좌측사람++ 본인--
                student[i-1]++;
                student[i]--;
                continue;
            }
        }
        if(i!=student.size()-1 && student[i+1]==0){ // 맨끝사람이 아니고, 뒷사람이 옷이없으면,
            if(student[i]==2){    // 여분이 있을경우 우측사람++ 본인--
                student[i+1]++;
                student[i]--;
            }
        }
    }
    
    // 3] 1개이상 체육복을 소지중인 학생의 수를 답에 대입한다.
    for(int i=0; i<student.size(); i++){
        if(student[i]>0){
            answer++;
        }
    }
    
    return answer;
}
