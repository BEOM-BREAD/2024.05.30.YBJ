#include "pch.h"
#include "Collider.h"

Collider::Collider()
:_center(Vector2())
{
	_pens.push_back(CreatePen(PS_SOLID, 3, GREEN));
	_pens.push_back(CreatePen(PS_SOLID, 3, RED));

	SetColor(GREEN_COLOR);
}

void Collider::SetColor(ColorNum num)
{
	_curPen = _pens[num];
}
