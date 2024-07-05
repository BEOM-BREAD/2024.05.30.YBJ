#include "pch.h"
#include "ArkanoidScene.h"
#include "Object/Arkanoid/Arkanoid.h"
#include "Object/Arkanoid/Ball.h"
#include "Object/Arkanoid/Stick.h"
#include "Object/Arkanoid/ArkaRect.h"

ArkanoidScene::ArkanoidScene()
{
	Vector2 offset = { 200, 120 };

	_player = make_shared<Stick>();
	_blocks.reserve(MAXWIDTHCNT);

	for (int i = 0; i < MAXWIDTHCNT; i++)
	{
		vector<shared_ptr<Arkanoid>> blocks_x;
		blocks_x.reserve(MAXHIGHTCNT);

		for (int j = 0; j < MAXHIGHTCNT; j++)
		{
			Vector2 blockOffset = offset + Vector2(85.0f * i, 45.0f * j);

			shared_ptr<Arkanoid> block = make_shared<Arkanoid>();

			block->SetCenter(blockOffset);
			blocks_x.push_back(block);
		}
		_blocks.push_back(blocks_x);
	}
}

ArkanoidScene::~ArkanoidScene()
{
}

void ArkanoidScene::Update()
{
	_player->Update();

	for (auto blocks_x : _blocks) {
		for (auto block : blocks_x) {
			block->Update();
		}
	}
	for (auto blocks_x : _blocks) {
		for (auto block : blocks_x) {
			_player->GetBall()->BlockCrash(block);
		}
	}
}

void ArkanoidScene::Render(HDC hdc)
{
	_player->Render(hdc);
	for (auto blocks_x : _blocks) {
		for (auto block : blocks_x) {
			block->Render(hdc);
		}
	}
}
