#include "pch.h"
#include "ArkaRect.h"

ArkaRect::ArkaRect()
	: RectCollider(Vector2(), Vector2(10, 20))
{
	_brushes.push_back(CreateSolidBrush(GREEN));
	_brushes.push_back(CreateSolidBrush(RED));
	_brushes.push_back(CreateSolidBrush(SKYCOLOR));

	_pens.push_back(CreatePen(PS_SOLID, 3, SKYCOLOR));

	SetRed();
}

ArkaRect::~ArkaRect()
{
	for (auto brush : _brushes)
		DeleteObject(brush);
}

void ArkaRect::Update()
{
	RectCollider::Update();
}

void ArkaRect::Render(HDC hdc)
{
	SelectObject(hdc, _brushes[static_cast<int>(_type)]);
	RectCollider::Render(hdc);
}

void ArkaRect::SetPosition(Vector2 pos)
{
	_center = pos;
}

void ArkaRect::SetBlockType(BlockType type)
{
	_type = type;
	_curPen = _pens[static_cast<int>(_type)];
}
