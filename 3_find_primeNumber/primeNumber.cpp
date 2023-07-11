/*

- 숫자를 조합해서 소수를 만들기
- 소수의 개수를 반환하는 함수 만들기

sol) 모든 숫자 조합을 만들고, 그 중 소수의 개수를 반환하기

Set 함수 : 중복되는 요소들 전부 제거

*/

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

set<int> numberSet;

bool isPrime(int number)
{
    // 1. 0과 1은 소수가 아니다
    if(number == 0 || number == 1)
        return false;
    
    // 2. 에라토스테네스의 채
    int lim = sqrt(number);
    for (int i = 2; i<=lim; i++)
        if(number % i == 0)
            return false;

    return true;   // loop를 다돌면 해당 숫자가 소수라는 것이기 대문에 true반환
}

void recursive(string comb, string others)  // comb : 현재까지 만들어진 숫자의 조합, ohters : 현재까지 사용되지 않은 string
{
    // 1. 현 조합을 numberSet에 추가한다.
    if(comb != ""){                                  // 예외처리, comb가 빈 string이 아닐 때 처리
        numberSet.insert(stoi(comb));                // stoi : string to into 
    //    cout << comb << '\n';                       
    }
      // 2. 현 조합 + ohters[i] 조합하여 새로운 조합을 만들어본다.
    for(int i = 0; i<others.size(); i++)
        recursive(comb + others[i], others.substr(0,i) + others.substr(i+1));
        // comb에 others[i]를 더해줌, 다음번에 들어왔을 때는 others의 숫자를 썻을 것이기 때문에 others에서 others[i] 뺀 것을 옮겨 줌
}

int solution(string numbers) {
    // 1. 모든 숫자 조합을 만든다.
    recursive("", numbers);

    // 2. 소수의 개수를 센다.
    int answer = 0;
    for(int number : numberSet)
        if (isPrime(number))
            answer++;

    // 3. 소수의 개수를 반환한다.

    return answer;
}

int main(void)
{
    cout << solution("011");
}


