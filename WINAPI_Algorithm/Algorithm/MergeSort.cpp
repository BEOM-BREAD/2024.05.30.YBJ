#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

void MergeResult(vector<int>& v, int left, int mid, int right)
{
	// ó�������� ���� ���� �۰� �ɰ����ִ� ����
	int leftIndex = left;
	int rightIndex = mid + 1;
	// [55] / [30]
	// left = 0;
	// right = 1
	// 
	// leftIndex = 0;
	// rightIndex = 1;
	// mid = 0;

	vector<int> temp;

	while (true)
	{
		if (leftIndex > mid || rightIndex > right)
			break;

		if (v[leftIndex] <= v[rightIndex])
		{
			temp.push_back(v[leftIndex]);
			leftIndex++;
		}
		else
		{
			temp.push_back(v[rightIndex]);
			rightIndex++;
			// temp : 30
			// leftIndex : 0
			// rightIndex : 2
		}
	}

	// ���ʿ� �ִ� ���ҵ��� temp�� �� ���簡 �Ǿ���.
	// right �迭�� �����־���.
	if (leftIndex > mid)
	{
		while (rightIndex <= right)
		{
			temp.push_back(v[rightIndex]);
			rightIndex++;
		}
	}
	// �����ʿ� �ִ� temp�� �� ���簡 �Ǿ���.
	// left �迭�� �����ִ�.
	else
	{
		while (leftIndex <= mid)
		{
			temp.push_back(v[leftIndex]);
			leftIndex++;
		}
	}

	for (int i = 0; i < temp.size(); i++)
	{
		v[left + i] = temp[i];
	}
}


void MergeSort(vector<int>& v, int left, int right)
{
	if (left >= right)
		return;

	int mid = (left + right) / 2;

	// Divide
	MergeSort(v, left, mid);
	MergeSort(v, mid + 1, right);

	// Conquer
	MergeResult(v, left, mid, right);
}

int main()
{
	vector<int> v = { 55,30,12,100,1,5,70, 30 };

    // MergeSort(v, 0, v.size() - 1);
	// N x logN ��ŭ�� �ð����⵵�� ������ ���� 3�ι�
 	// std::sort(v.begin(), v.end());
	// std::partial_sort(v.begin(), v.end(), v.end());
	std::stable_sort(v.begin(), v.end());

	return 0;
}