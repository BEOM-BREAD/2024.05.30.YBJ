#include "pch.h"
#include "CircleCollider.h"

#define GREEN_COLOR		 0
#define RED_COLOR	     1

CircleCollider::CircleCollider(Vector2 center, float radius)
	: _center(center), _radius(radius)
{
	_pens.push_back(CreatePen(PS_SOLID, 3, GREEN));
	_pens.push_back(CreatePen(PS_SOLID, 3, RED));

	SetColor(GREEN_COLOR);
}

CircleCollider::~CircleCollider()
{
	for (auto pen : _pens)
		DeleteObject(pen);
}

void CircleCollider::Update()
{
}

void CircleCollider::Render(HDC hdc)
{
	SelectObject(hdc, _curPen);

	int left = _center._x - _radius;
	int top = _center._y - _radius;
	int right = _center._x + _radius;
	int bottom = _center._y + _radius;

	Ellipse(hdc, left, top, right, bottom);
}

bool CircleCollider::IsCollision(Vector2 point)
{
	float distance = _center.Distance(point);

	return distance < _radius;
}

bool CircleCollider::IsCollision(shared_ptr<CircleCollider> other)
{
	float distance = _center.Distance(other->_center);

	return distance < _radius + other->_radius;
}

bool CircleCollider::IsCollision(shared_ptr<RectCollider> other)
{
	// 과제....사각형...
	// 충돌 방법 2가지
	// AABB (회전하지 않는다는 조건), OBB(회전이 가능하다(directX에서나 회전됨..))
	//Vector2 circleCenter = _center;
	//float radius = _radius;

	//Vector2 rectCenter = other->_center;
	//Vector2 rectHalfSize = other->_halfSize;

	// 위 아래 충돌
	//if (circleCenter._x < other->Right() && circleCenter._x > other->Left())
	//{
	//	if (circleCenter._y < other->Bottom() && circleCenter._y > other->Top())
	//	{
	//		Vector2 newHalfSize = Vector2(rectHalfSize._x, rectHalfSize._y + radius);
	//		RectCollider newRect = RectCollider(other->_center, newHalfSize);

	//		if (newRect.IsCollision(circleCenter))
	//			return true;
	//	}
	//	// 좌우 충돌
	//	else if (circleCenter._y < other->Bottom() && circleCenter._y > other->Top())
	//	{
	//		Vector2 newHalfSize = Vector2(rectHalfSize._x + radius, rectHalfSize._y);
	//		RectCollider newRect = RectCollider(other->_center, newHalfSize);

	//		if (newRect.IsCollision(circleCenter))
	//			return true;
	//	}

	//	else
	//	{
	//		bool check1 = IsCollision(Vector2(other->Left(), other->Top()));
	//		bool check2 = IsCollision(Vector2(other->Left(), other->Bottom()));
	//		bool check3 = IsCollision(Vector2(other->Right(), other->Top()));
	//		bool check4 = IsCollision(Vector2(other->Right(), other->Bottom()));

	//		return check1 || check2 || check3 || check4;
	//	}

	//	return false;
	//}

	float rectLeft = other->Left();
	float rectRight = other->Right();
	float rectTop = other->Top();
	float rectBottom = other->Bottom();

	float nearX;
	if (_center._x < rectLeft)
		nearX = rectLeft;
	else if (_center._x > rectRight)
		nearX = rectRight;
	else
		nearX = _center._x;

	float nearY;
	if (_center._y < rectTop)
		nearY = rectTop;
	else if (_center._y > rectBottom)
		nearY = rectBottom;
	else
		nearY = _center._y;

	float distanceX = _center._x - nearX;
	float distanceY = _center._y - nearY;

	float distance = (distanceX * distanceX) + (distanceY * distanceY);

	return distance < (_radius * _radius);
}

void CircleCollider::SetColor(ColorNum num)
{
	_curPen = _pens[num];
}