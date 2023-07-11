/*

* 전화번호부

문제조건

- phone_book의 길이는 1이상 1,000,000 이하입니다.
- 각 전화번호의 길이는 1 이상 20 이하 입니다.
- 같은 전화번호가 중복해서 들어 있지 않습니다.

Q. 전화번호가 접두어 인가?

전화번호부에 적힌 전화번호 중, 한 번호가 다른 번호의 접두어인 경우가 있는지 확인하려 합니다.

접두어이면 False, 아니면 True 를 반환하게 하세요


*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    // 1. phone_book 배열을 정렬한다
    sort(phone_book.begin(), phone_book.end());

    // 2. 1중 loop를 돌면서 앞 번호가 뒷번호의 접두어인지 확인한다. 
    for(int i = 0; i<phone_book.size() - 1; i++) // 폰북 전체사이즈를 비교하게 되면 끝에 배열에서 비교할때 죽게됨
        if(phone_book[i+1].find(phone_book[i])  == 0) // 폰북[i]가 폰북[i+1]의 존재한다는 것과 제일 앞에 있다는 것을 의미함
            return false;

    // 3. 여기까지 왔다면 접두어가 없다는 것이다. -> true 리턴
    
    return true;
}

int main(void)
{
    vector<string> phone_book = {"119", "97674223", "1195524421"};
    cout << solution(phone_book);
}