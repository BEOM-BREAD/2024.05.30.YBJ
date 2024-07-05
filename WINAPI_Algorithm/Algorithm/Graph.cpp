#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

// �׷���
// �����ϸ�Ʈ ���Ϸ�(�Ѻ� �׸��� ���ؼ� �׷������ �ڷᱸ���� ����)

// ����(Node, Vertex)�� ����(Edge)���� �̷���� �ڷᱸ��

// 1. ��������Ʈ
vector<vector<int>> adjacent_List;

void CreateGraph_AdjacentList()
{
	adjacent_List = vector<vector<int>>(7, vector<int>());

	adjacent_List[0].push_back(1);
	adjacent_List[0].push_back(2);
	adjacent_List[0].push_back(4);

	adjacent_List[1].push_back(0);

	adjacent_List[2].push_back(0);
	adjacent_List[2].push_back(3);
	adjacent_List[2].push_back(5);

	adjacent_List[3].push_back(2);

	adjacent_List[4].push_back(0);
	adjacent_List[4].push_back(6);

	adjacent_List[5].push_back(2);

	adjacent_List[6].push_back(4);
}

// 2. �������
vector<vector<bool>> adjacent;

void CreateGraph_AdjacentMatrix()
{
	//     0   1   2   3   4   5   6
	// 0   T   T   T   F   T   F   F	
	// 1   T   T   F   F   F   F   F
	// 2   
	// 3
	// 4
	// 5
	// 6

	adjacent = vector<vector<bool>>(7, vector<bool>(7, false));

	adjacent[0][0] = true;
	adjacent[0][1] = true;
	adjacent[0][2] = true;
	adjacent[0][4] = true;

	adjacent[1][0] = true;
	adjacent[1][1] = true;

	adjacent[2][0] = true;
	adjacent[2][2] = true;
	adjacent[2][3] = true;
	adjacent[2][5] = true;

	adjacent[3][2] = true;
	adjacent[3][3] = true;

	adjacent[4][0] = true;
	adjacent[4][4] = true;
	adjacent[4][6] = true;

	adjacent[5][2] = true;
	adjacent[5][5] = true;

	adjacent[6][4] = true;
	adjacent[6][6] = true;
}

int main()
{
	CreateGraph_AdjacentList();
	CreateGraph_AdjacentMatrix();
	
	// 0�� 2�� ������ ������ �Ǿ��ֽ��ϱ�? ��������Ʈ
	for (auto vertex : adjacent_List[0])
	{
		if (vertex == 2)
			cout << "0�� 2�� �̾����ֽ��ϴ�." << endl;
	}

	//auto iter = std::find(adjacent_List[0].begin(), adjacent_List[0].end(), 2);

	//if (iter != adjacent_List[0].end())
	//	cout << "0�� 2�� �̾����ֽ��ϴ�." << endl;

	// 0�� 2�� ������ ������ �Ǿ��ֽ��ϱ�? �������
	if(adjacent[0][2])
		cout << "0�� 2�� �̾����ֽ��ϴ�." << endl;

	// 5�� 4�� ����Ǿ��ֽ��ϱ�?
	for (auto vertex : adjacent_List[5])
	{
		if (vertex == 4)
		{
			cout << "5�� 4�� ����Ǿ� �ֽ��ϴ�." << endl;
		}
		else
		{
			cout << "5�� 4�� ����Ǿ� ���� �ʽ��ϴ�." << endl;
		}
	}

	return 0;
}