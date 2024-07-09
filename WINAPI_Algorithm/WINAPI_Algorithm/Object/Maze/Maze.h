#pragma once

#include "Block.h"

class Block;

#define MAXCOUNT_X 25
#define MAXCOUNT_Y 25

class Maze
{
public:
	Maze();
	~Maze();

	void Update();
	void Render(HDC hdc);

	void CreateMaze();
	Block::BlockType GetBlockType(int y, int x);
	void SetBlockType(int y, int x, Block::BlockType type);

	void SetPlayerPos(Vector2 pos);

	Vector2 GetStartPos() { return Vector2(1, 1); }
	Vector2 GetEndPos() { return Vector2(MAXCOUNT_Y - 2, MAXCOUNT_X - 2); }

private:
	vector<vector<shared_ptr<Block>>> _blocks;
};

#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps[0].size();

    vector<pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

    queue<pair<int, int>> q;
    q.push({ 0, 0 });
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    visited[0][0] = true;

    int distance = 1;

    while (!q.empty())
    {
        int size = q.size();

        for (int i = 0; i < size; ++i)
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (auto& dir : directions)
            {
                int nr = r + dir.first;
                int nc = c + dir.second;
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc] && maps[nr][nc] == 1)
                {
                    if (nr == n - 1 && nc == m - 1)
                    {
                        return distance + 1;
                    }
                    q.push({ nr, nc });
                    visited[nr][nc] = true;
                }
            }
        }

        distance++;
    }

    return -1;
}
