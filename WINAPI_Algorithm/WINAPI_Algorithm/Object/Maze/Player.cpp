#include "pch.h"
#include "Player.h"

#include "Maze.h"
#include "Block.h"

Player::Player(shared_ptr<Maze> maze)
{
	_maze = maze;
}

Player::~Player()
{
	_maze = nullptr;
}

void Player::BeginPlay()
{
	_maze->SetPlayerPos(_pos);
	RightHand();
}

void Player::RightHand()
{
	// �ǽ�
	// ������� �̿��ؼ� �̷θ� �������� ���� �ȴ�.
	// ã�� ���� _path���� �ִ´�.

	enum Direction
	{
		UP,
		LEFT,
		BOTTOM,
		RIGHT,

		DIR_COUNT = 4
	};

	Vector2 pos = _pos;
	_path.push_back(pos);
	Vector2 endPos = Vector2(23, 23);

	Direction dir = Direction::BOTTOM;

	Vector2 frontPos[4] =
	{
		Vector2(0,-1), // UP
		Vector2(-1,0), // left
		Vector2(0,1),  // BOTTOM
		Vector2(1,0),  // RIGHT
	};

	while (true)
	{
		if (pos == endPos)
			break;
		//........(2   + 1 +   4) % 4 = 3
		// % : �˰��򿡼� ��ȯ�������� ���� ���δ�.
		int newDir = (dir - 1 + DIR_COUNT) % DIR_COUNT;
		Vector2 oldDirVector2 = frontPos[dir];
		Vector2 newDirVector2 = frontPos[newDir];

		Vector2 newPos = pos + newDirVector2; // �� ������ ����
		Vector2 oldPos = pos + oldDirVector2; // �� �չ���

		// ���������� �� �� ������ ������ �ٲٰ� ���������� ����
		if (CanGo(newPos._y, newPos._x))
		{
			dir = static_cast<Direction>(newDir);
			pos += newDirVector2;
			_path.push_back(pos);
		}
		// �������� �����ְ� �������� �� �� ������ ���� �״�� ������ ����
		else if (CanGo(oldPos._y, oldPos._x))
		{
			pos += oldDirVector2;
			_path.push_back(pos);
		}
		// ������, ���� �� �� ���������� ���Ƽ� ����
		else
		{
			dir = static_cast<Direction>((dir + 1 + DIR_COUNT) % DIR_COUNT);
		}
	}

	stack<Vector2> s;

	for (int i = 0; i < _path.size() - 1; i++)
	{
		if (s.empty() == false && s.top() == _path[i + 1])
		{
			s.pop();
		}
		else
			s.push(_path[i]);
	}

	s.push(_path.back());

	_path.clear();

	while (true)
	{
		if (s.empty() == true)
			break;

		_path.push_back(s.top());
		s.pop();
	}

	std::reverse(_path.begin(), _path.end());
}

bool Player::CanGo(int y, int x)
{
	Block::BlockType blockType = _maze->GetBlockType(y, x);
	if (blockType == Block::BlockType::ABLE)
		return true;

	return false;
}

void Player::Update()
{
	if (_pathIndex >= _path.size())
	{
		_pathIndex = 0;
		_path.clear();

		return;
	}

	_time += 0.9f;
	if (_time > 1.0f)
	{
		_time = 0.0f;
		_pos = _path[_pathIndex];

		if (_pathIndex != 0)
		{
			_maze->SetPlayerPos(_pos);
			// ������
		}

		_pathIndex++;
	}
}
