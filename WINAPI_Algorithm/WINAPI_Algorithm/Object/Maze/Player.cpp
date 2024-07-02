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
	FindPath();
}

void Player::FindPath()
{
	// �ǽ�
	// ������� �̿��ؼ� �̷θ� �������� ���� �ȴ�.
	// ã�� ���� _path���� �ִ´�.
	vector<Vector2> temp =
	{
	Vector2(2,1),
	Vector2(3,1),
	Vector2(4,1),
	Vector2(5,1),
	Vector2(6,1),
	Vector2(7,1),
	Vector2(8,1),
	Vector2(9,1),
	Vector2(10,1)
	};

	_path = temp;
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

	_time += 0.03f;
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
