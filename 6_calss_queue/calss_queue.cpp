/*

중요도를 고려한 프린터

- 중요도가 높은 문서를 먼저 프린트
- 인쇄 대기목록에 가장 앞에 있는 문서J를 대기목록에서 꺼냄
- 나머지 인쇄 대기목록에서 J보다 중요도가 높은 문서가 한 개라도 존재하면 J를 대기목록의 가장 마지막에 넣습니다.
- 그렇지 않으면 J를 인쇄합니다.

- 인쇄 작업 중요도는 1~9로 숫자가 클수록 중요하다는 뜻
- location은 0이상(현재 대기목록에 있는 작업 수 - 1)이하의 값을 가지며 대기목록의 가장 앞에 있으면, 0
   두 번째에 있으면 1로 표현합니다.
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue> 
#include <algorithm>

using namespace std;

struct PrintJob{
    int priority;
    int location;
};

int solution(vector<int> priorities, int location) {
    // 1. Queue를 만든다.
    queue<PrintJob> printer;
    for (int i = 0; i < priorities.size(); i++)  {  // priorites에서 하나씩 돌면서 꺼내올 것
     
        PrintJob job;
        job.location = i;
        job.priority = priorities[i];
        printer.push(job);     
        
    }
     // 2. 0번을 꺼내서 max priority 아니면 다시 끝에 넣는다.
    int turn = 0;
    while(!printer.empty()) {                          // printer에 출력할 잡이 있을 때 까지 while loop를 돌 것
        PrintJob job = printer.front();                // loop를 돌면서 printer의 내용을 하나씩 꺼내올 것
        printer.pop();                                 // queu에서 front 가져온 녀석을 빼냄

        if (job.priority < *max_element(priorities.begin(),priorities.end()))       // job을 pop으로 꺼내왔다면 job의 priorrity가 가장 큰 녀석인지 봐야함
        {    
            printer.push(job); // 제일 큰 값이 ,job p 보다 크다면 다시 push로 뒤로 넣어줌
        }
    // 3. max priority가 맞다면 내가 찾는 job인지 확인한다.
        else
        {
            turn++; // 가장 중요한 job이기 때문에 turn 증가
            if(job.location == location)  // 현재 수행하는 애가 찾고자 하는 애라면 break -> while loop를 빠져나와 turn값 반환
                break;
            priorities[job.location] = 0; // 한번 수행한 애는 더이상 고려하고 싶지 않기 때문에 0으로 설정 -> max비교에서 제외될 것 
        }
    }
    return turn;

}

int main(void){
    vector<int> priorities = {2, 1, 3, 2};
    cout << solution(priorities, 1); // 2번 인덱스(3) 이라는 우선순위가 언제 수행이 되는지 알고싶음
    return 0;
}