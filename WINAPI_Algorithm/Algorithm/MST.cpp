#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>
#include <concurrent_priority_queue.h>

using namespace std;

class DisJointSet
{
public:
	DisJointSet(int n)
	{
		_parent = vector<int>(n, 0);
		_rank = vector<int>(n, 1);

		for (int i = 0; i < n; i++)
		{
			_parent[i] = i;
		}
	}

	int FindLeader(int u)
	{
		if (u == _parent[u])
			return u;

		int parent = _parent[u];
		return FindLeader(parent);
	}

	void Merge(int u, int v)
	{
		int uLeader = FindLeader(u);
		int vLeader = FindLeader(v);

		if (uLeader == vLeader)
			return;

		if (_rank[uLeader] > _rank[vLeader])
		{
			std::swap(uLeader, vLeader);
		}

		_parent[uLeader] = vLeader;

		if (_rank[uLeader] == _rank[vLeader])
			_rank[vLeader]++;
	}

private:
	vector<int> _parent;
	vector<int> _rank;
};

// MST : (Minimum Spanning Tree)
// DisJoint Set

struct Edge
{
	int u; // ������
	int v; // ����

	int length; // ����
};

vector<vector<int>> adjacent;
vector<Edge> edges;

void CreateGraph_AdjacentMatrix()
{
	//    0  1  2  3  4  5  6
	// 0  T  T  T  F  T  F  F
	// 1  T  T  F  F  F  F  F
	// 2  T  F  T  T  T  T  F
	// 3  F  F  T  T  F  F  F
	// 4  T  F  T  F  T  F  T
	// 5  F  F  T  F  F  T  F
	// 6  F  F  F  F  T  F  T

	adjacent = vector<vector<int>>(7, vector<int>(7, -1));

	adjacent[0][0] = 0;
	adjacent[0][1] = 3;
	adjacent[0][2] = 2;
	adjacent[0][4] = 10;

	adjacent[1][0] = 3;
	adjacent[1][1] = 0;

	adjacent[2][0] = 2;
	adjacent[2][2] = 0;
	adjacent[2][3] = 7;
	adjacent[2][4] = 3;
	adjacent[2][5] = 5;

	adjacent[3][2] = 7;
	adjacent[3][3] = 0;

	adjacent[4][0] = 10;
	adjacent[4][2] = 3;
	adjacent[4][4] = 0;
	adjacent[4][6] = 4;

	adjacent[5][2] = 5;
	adjacent[5][5] = 0;

	adjacent[6][4] = 4;
	adjacent[6][6] = 0;
}

void CreateEdges()
{
	for (int u = 0; u < adjacent.size(); u++)
	{
		for (int v = 0; v < adjacent.size(); v++)
		{
			if (u >= v) continue;

			if (adjacent[u][v] == -1)
				continue;

			Edge edge;
			edge.u = u;
			edge.v = v;
			edge.length = adjacent[u][v];

			edges.push_back(edge);
		}
	}
}

vector<Edge> Krustal()
{
	vector<Edge> result;

	std::sort(edges.begin(), edges.end(), [](const Edge& e1, const Edge& e2)-> bool
		{
			if (e1.length < e2.length)
				return true;
			return false;
		});

	DisJointSet set(adjacent.size());

	for (auto edge : edges)
	{
		int u = edge.u;
		int v = edge.v;

		if (set.FindLeader(u) == set.FindLeader(v))
			continue;

		set.Merge(u, v);
		result.push_back(edge);
	}
	return result;
}

int main()
{
	CreateGraph_AdjacentMatrix();
	CreateEdges();

	vector<Edge> mst = Krustal();

	for (auto& edge : mst)
	{
		cout << edge.u << " ~ " << edge.v << "...���̴� " << edge.length << endl;
	}

	return 0;
}