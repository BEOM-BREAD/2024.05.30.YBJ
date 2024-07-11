#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

// Heap sort
// 힙트리에 하나씩 다 집어넣고 하나씩 꺼낸다.

// 평균 시간 복잡도 : N x logN
// 최악의 경우 : N^2

int Partition(vector<int>& v, int left, int right)
{
	int pivot = v[left];
	int lowIndex = left + 1;
	int highIndex = right;

	while (true)
	{
		if (lowIndex > highIndex)
			break;

		// lowIndex는 항상 pivot보다 작아야한다.
		// 작으며 다음 index를 확인한다.
		while (lowIndex <= right && pivot >= v[lowIndex])
		{
			lowIndex++;
		}


		// highIndex는 항상 pivot보다 커야한다.
		// 크면 이전 Index를 확인한다.
		while (highIndex >= left + 1 && pivot <= v[highIndex])
		{
			highIndex++;
		}

		if (lowIndex < highIndex)
			std::swap(v[lowIndex], v[highIndex]);
	}

	std::swap(v[highIndex], v[left]);

	return highIndex;
}

void QuickSort(vector<int>& v, int left, int right)
{
	// 기저사항
	if (left > right)
		return;

	int pivotIndex = Partition(v, left, right);
	cout << left << " ~ " << pivotIndex - 1 << endl;

	QuickSort(v, left, pivotIndex - 1);
	QuickSort(v, pivotIndex + 1, right);
}

int main()
{
	vector<int> v = { 55,30,12,100,1,5,70};
	QuickSort(v, 0, v.size() -1);

	return 0;
}