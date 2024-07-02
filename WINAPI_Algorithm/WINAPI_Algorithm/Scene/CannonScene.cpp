#include "pch.h"
#include "CannonScene.h"
#include "Object/Cannon.h"
#include "Object/Bullet.h"

// ��缭
// ���� ��Ʈ����
// �� cannon�� �ϸ��� ���� ��Ʈ���� �޾Ƽ� ����
// cannon�� HP�� 5
// ������ hp - 1, hp�� 0�̸� cannon�� �����

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
	_cannon1->Update();
	_cannon2->Update();

	// Attack1
	//for (auto bullet : _cannon1->GetBullets())
	//{
	//	bullet->Attack_Cannon(_cannon2);
	//}

	if (!_cannon1->IsDead() || !_cannon2->IsDead())
	{
		if (_cannon1->isControlled)
		{
			if (_cannon1->GetBulletvs() >= 1)
			{
				_cannon1->isControlled = false;
				_cannon2->isControlled = true;
				_cannon1->ResetBulletvs();
			}
		}
		else
		{
			if (_cannon2->GetBulletvs() >= 1)
			{
				_cannon2->isControlled = false;
				_cannon1->isControlled = true;
				_cannon2->ResetBulletvs();
			}
		}
	}





}

void CannonScene::Render(HDC hdc)
{
	_cannon1->Render(hdc);
	_cannon2->Render(hdc);
}