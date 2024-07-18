#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> input;
int N;

void Input()
{
	while (true)
	{
		int a = 0;
		int b = 0;
		int c = 0;
		cin >> a;
		cin >> b;
		cin >> c;

		if (a == -1 && b == -1 && c == -1)
			break;

		vector<int> temp = { a,b,c };
		input.push_back(temp);
	}

	N = input.size();
}

int cache[100][100][100];

int w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	if (a > 20 || b > 20 || c > 20)
		return w(20, 20, 20);

	int& ref = cache[a][b][c];
	if (ref != -1)
		return ref;

	if (a < b && b < c)
		return ref = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	else
		return ref = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main()
{
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			for (int k = 0; k < 100; k++)
				cache[i][j][k] = -1;
		}
	}

	Input();

	for (auto v : input)
	{
		printf("w(%d, %d, %d) = %d \n", v[0], v[1], v[2], w(v[0], v[1], v[2]));
	}

	return 0;
}