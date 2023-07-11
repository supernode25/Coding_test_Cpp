/*

- 여러가지 종류의 옷이 있는데 이걸로 몇개의 조합이 가능한지 구하기
- 아무것도 입지않는경우는 있을 수 없음

*/

#include <iostream>
#include <string>
#include <vector>
#include <undorderd_map> // Hash

using namespace std;

int solution(vector<vector<string>> clothes)
{
    // 1. 옷을 종류별로 구분한다.

    unordered_map<string, int> map;
    for(vector<string> clothe : clothes)
        map[clothe[1]]++;


    // 2. 입지 않는 경우를 고려해서 모든 조합을 계산한다.

    int answer = 0; // 곱셈의 누적값활용을 위해 1로 초기화
    for(auto it = map.begin(); it !=map.end(); it++)
        answer *= it->second + 1;

    // 3. 아무 종류의 옷도 입지 않는 경우 제외한다.
    return answer - 1; 
    
  }

int main(void)
{
    vector<vector<string>> clothes = {{"yellowhat", "headgear"}, {"bludsynglasses", "eyewear"}, {"green_turban", "headgear"}};

    cout << solution(clothes);
}