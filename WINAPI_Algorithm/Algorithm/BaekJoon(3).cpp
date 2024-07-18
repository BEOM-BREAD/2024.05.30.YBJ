#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0;
vector<int> input;
vector<int> cache;

void Input()
{
	cin >> N;

	cache = vector<int>(N, -1001);
	
	for (int i = 0; i < N; i++)
	{
		int temp = 0;
		cin >> temp;

		input.push_back(temp);
	}
}

int  SequenceAdd(int index)
{
	// ��������
	if (index == N - 1)
		return input[index];

	// �޸������̼�
	int& ref = cache[index];
	if (ref != -1001)
		return ref;

	// ���ϱ�
	int result = input[index];
	result = max(result, result + SequenceAdd(index + 1));
	ref = result;

	return ref;
}

int main()
{
	Input();

	int result = -1001;

	for (int i = 0; i < N; i++)
	{
		result = max(result, SequenceAdd(i));
	}

	cout << result << endl;

	return 0;
}
