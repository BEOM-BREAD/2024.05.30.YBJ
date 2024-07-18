#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

// Enchant
// N만큼 강화
// 강화는 100프로 성공하며 강화할 떄 올라가는 수치는 +1, +2, +3 이 랜덤으로 나오게 한다.
// 이때 N만큼 강화일때 나오는 경우의 수를 구하라.
// (1 <= N <= 100000)

// +1 +1 +1
// +1 +2
// +2 +1
// +3

// 4

// N = 1
// 1

// N = 2
// 2

// N = 3
// 4

// N = 4
// 7

vector<int> cache = vector<int>(100001, -1);

int Enchant(int num) 
{
	// 기저사항
	if (num == 0)
		return 1;

	if (num < 0)
		return 0;

	int& ref = cache[num];
	if (ref != -1)
		return ref;

	return ref = Enchant(num - 1) + Enchant(num - 2) + Enchant(num - 3);
}

int main()
{
	int result = Enchant(0);

	// 서식 지정자
	// %c : 하나의 문자
	// %s : string
	// %d : 부호 있는 10진 정수
	// %f : float
	int temp = 1;
	printf("Hello World! %d .... temp : %d ", result, temp);
	

	return 0;
}