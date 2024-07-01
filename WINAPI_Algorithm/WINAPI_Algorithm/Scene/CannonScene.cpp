#include "pch.h"
#include "CannonScene.h"
#include "Object/Cannon.h"
#include "Object/Bullet.h"

// 사양서
// 단체 포트리스
// 각 cannon을 턴마다 서로 컨트롤을 받아서 공격
// cannon의 HP는 5
// 맞으면 hp는 -1, hp가 0이면 cannon이 사라짐

CannonScene::CannonScene()
{
	_cannon1 = make_shared<Cannon>();
	_cannon2 = make_shared<Cannon>();

	_cannon1->isControlled = true;

	// Attack2
	for (auto bullet : _cannon1->GetBullets())
	{
		bullet->SetTarget(_cannon2);
	}

	for (auto bullet : _cannon2->GetBullets())
	{
		bullet->SetTarget(_cannon1);
	}
}

CannonScene::~CannonScene()
{
}

void CannonScene::Update()
{
	{
		_cannon1->Update();
		_cannon2->Update();

		if (_cannon1->isControlled && (GetAsyncKeyState(VK_SPACE) & 0x0001))
		{
			_cannon2->TakeDamage();
		}
		else if (_cannon2->isControlled && (GetAsyncKeyState(VK_SPACE) & 0x0001))
		{
			_cannon1->TakeDamage();
		}
	}

	// Attack1
	//for (auto bullet : _cannon1->GetBullets())
	//{
	//	bullet->Attack_Cannon(_cannon2);
	//}
}

void CannonScene::Render(HDC hdc)
{
	_cannon1->Render(hdc);
	_cannon2->Render(hdc);
}
