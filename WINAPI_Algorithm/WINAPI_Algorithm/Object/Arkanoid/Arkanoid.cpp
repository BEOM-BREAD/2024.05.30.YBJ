#include "pch.h"
#include "Arkanoid.h"

Arkanoid::Arkanoid()
{
	_col = make_shared<RectCollider>(CENTER, Vector2(40, 20));
}

Arkanoid::~Arkanoid()
{
}

void Arkanoid::Update()
{
}

void Arkanoid::Render(HDC hdc)
{
	if (_isBreak) return;

	_col->Render(hdc);
}

void Arkanoid::SetCenter(Vector2 position)
{
	_col->_center = position;
}

void Arkanoid::Hit()
{
	SetBrake(true);
}

