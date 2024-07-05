#include "pch.h"
#include "Cannon.h"
#include "Object/Barrel.h"
#include "Object/Bullet.h"

Cannon::Cannon()
{
	_body = make_shared<CircleCollider>(CENTER, 50.0f);
	_barrel = make_shared<Barrel>();

	for (int i = 0;i < 3;i++)
	{
		shared_ptr<Bullet> bullet = make_shared<Bullet>();
		bullet->SetActive(false);
		_bullets.push_back(bullet);
	}

	Move();
}

Cannon::~Cannon()
{
}

void Cannon::Update()
{
	if (!IsActive)
	{
		return;
	}

	if (isControlled)
	{
		Move();
		Fire();
	}

	_body->Update();
	_barrel->Update();

	for (auto bullet : _bullets)
		bullet->Update();
}

void Cannon::Render(HDC hdc)
{
	if (!IsActive)
	{
		return;
	}

	_barrel->Render(hdc);
	_body->Render(hdc);

	for (auto bullet : _bullets)
		bullet->Render(hdc);
}


void Cannon::Move()
{
	if (!IsActive) return;
	if (GetAsyncKeyState(VK_RIGHT))
	{
		_body->_center._x += 1.0f;
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		_body->_center._x -= 1.0f;
	}
	if (GetAsyncKeyState(VK_UP))
	{
		_angle -= 0.01f;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		_angle += 0.01f;
	}

	_barrel->SetAngle(_angle);

	_barrel->SetStart(_body->_center);
}

void Cannon::Fire()
{
	if (!IsActive) return;
	// KEY DOWN
	if (GetAsyncKeyState(VK_SPACE) & 0x0001)
	{
		// _bullets... ���� ��(isActive == false)�� �ִ��� Ȯ���ϰ�
		// -> ���� �ָ� ã�Ƽ� Fire

		//_bullet->Fire(_barrel->GetEndPos(), _barrel->GetDirection());

		//for (auto bullet : _bullets)
		//{
		//	if (bullet->IsActive() == false)
		//	{
		//		bullet->Fire(_barrel->GetEndPos(), _barrel->GetDirection());
		//		break;
		//	}
		//}

		auto iter = std::find_if(_bullets.begin(), _bullets.end(),
			[](shared_ptr<Bullet> bullet)->bool
			{
				if (!bullet->IsActive()) return true;
				return false;
			});

		if (iter != _bullets.end())
		{
			(*iter)->Fire(_barrel->GetBarrelEnd(), _barrel->GetDirection());
			_bulletvs++;
		}
	}

}

void Cannon::TakeDamage()
{
	_hp--;

	if (IsDead())
	{
		IsActive = false;
	}
}
