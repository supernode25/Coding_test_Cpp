
/*

*문제조건

- 마라톤 경기에 참여한 선수의 수는 1명이상 100,000명 이하입니다.
- completion의 길이는 participant의 길이보다 1 작습니다.
- 참가자의 이름은 1개이상 20개 이하의 알파벳 소문자로 이루어져 있습니다.
- 참가자 중에는 동명이인이 있을 수 있습니다.

- 완주하지 못한 선수를 returnm으로 내세요

sol) participant에는 있고 completion에는 없는 그 한명을 찾아야함 -> Sorting / Loop 사용

1) Sorting -> 두 list를 soriting 한다
2) 비교 -> completion list의 length만큼 돌면서 participant에만 존재하는 한 명을 찾는다.
3) 마지막 주자 -> List를 전부 다 뒤져도 답이 없다면, participant의 마지막 주자가 완주하지 못한 선수임. (예외 처리)

*/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";
    // 1. 두 배열을 정렬한다.
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    // 2. 두 배열이 다를 때 까지 찾는다.
    int i = 0;
    for(; i<completion.size();  i++)
        if(participant[i] != completion[i])
            break;     

    // 3. completion 배열을 전부 찾아도 답이 없다면, 마지막 선수가 완주하지 못한 선수다.
        

    return participant[i]; //다 찾지 못하면 마지막 선수가 완주하지 못한걸로 간주하여 반환


}

int main(void)
{
    vector<string> part = {"kiki", "eden", "mimi"};
    vector<string> comp = {"eden", "kiki"};
    cout << solution(part, comp) << std::endl;
    return 0;
}


/*
응용문제
 
1. 완주하지 못한 사람이 여러명인 경우 풀어보기
2. 숫자형태로도 변형해서 두배열을의 정렬, 최소값, 최대값등으로 풀어보기

*/

