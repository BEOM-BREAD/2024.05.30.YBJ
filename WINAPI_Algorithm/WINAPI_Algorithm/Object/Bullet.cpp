#include "pch.h"
#include "Bullet.h"
#include "Object/Cannon.h"

Bullet::Bullet()
{
	_col = make_shared<CircleCollider>(Vector2(CENTER), 7);
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	if (_isActive == false) return;

	Attack_cannon();

	_col->Update();
	_col->_center += _direction * _speed;

	// TODO(����) : �߷� ����
	_col->_center += _downVector;
	_downVector += Vector2(0, 1) * GRAVITY;

	// TODO(����) : ȭ�� ������ ������ �� ������� �ڵ�
	// OutControll�� �ݻ縦 ���� �Լ�
	// bool isout = IsOut();
	//OutControll();
	bool isout = IsOut();
	if (_lifeTime > _delayTime || isout)
	{
		_lifeTime = 0.0f;
		_isActive = false;
	}
	_lifeTime += 0.01f;
}

void Bullet::Render(HDC hdc)
{
	if (_isActive == false) return;

	_col->Render(hdc);
}

void Bullet::Fire(Vector2 startPos, Vector2 direction)
{
	_isActive = true;
	_col->_center = startPos;
	_direction = direction;
	_direction.Normalize();
	_downVector = Vector2();
}

void Bullet::SetActive(bool IsActive)
{
	_downVector = Vector2();
	_isActive = IsActive;
}

bool Bullet::IsOut()
{
	if (_col->_center._x > WIN_WIDTH || _col->_center._x < 0)
		return true;

	if (_col->_center._y > WIN_HEIGHT || _col->_center._y < 0)
		return true;

	return false;
}

//void Bullet::OutControll()
//{
//	Vector2 center = _col->_center;
//	// ȭ�� �¿�� ������?
//	if (center._x > WIN_WIDTH || center._x < 0)
//	{
//		_direction._x *= -1.0f;
//	}
//
//	if (center._y > WIN_HEIGHT || center._y < 0)
//	{
//		_direction._y *= -1.0f;
//	}
//}

void Bullet::Attack_Cannon(shared_ptr<class Cannon> cannon)
{
	if (IsActive() == false)
		return;
	// cannon�� ��� ������ ���ΰ�
	// -> cannon�� body
	if (cannon->GetCollider()->IsCollision(_col))
	{
		SetActive(false);
	}
}

void Bullet::Attack_cannon()
{
	if (_target.expired() == false)
	{
		shared_ptr<Cannon> targetCannon = _target.lock();
		shared_ptr<Collider> targetCannonCol = targetCannon->GetCollider();
		if(targetCannonCol->IsCollision(_col))
		{
			SetActive(false);
		}
	}
}
