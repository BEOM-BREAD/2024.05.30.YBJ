#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

// Enchant
// N��ŭ ��ȭ
// ��ȭ�� 100���� �����ϸ� ��ȭ�� �� �ö󰡴� ��ġ�� +1, +2, +3 �� �������� ������ �Ѵ�.
// �̶� N��ŭ ��ȭ�϶� ������ ����� ���� ���϶�.
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
	// ��������
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

	// ���� ������
	// %c : �ϳ��� ����
	// %s : string
	// %d : ��ȣ �ִ� 10�� ����
	// %f : float
	int temp = 1;
	printf("Hello World! %d .... temp : %d ", result, temp);
	

	return 0;
}