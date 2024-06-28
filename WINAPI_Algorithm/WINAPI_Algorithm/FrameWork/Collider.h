#pragma once
class Collider
{
public:
	Collider();
	virtual ~Collider();

	virtual void Update()abstract;
	virtual void Render(HDC hdc)abstract;

	virtual bool IsCollision(Vector2 point)abstract;
	virtual bool IsCollision(shared_ptr<CircleCollider> other)abstract;
	virtual bool IsCollision(shared_ptr<RectCollider> other)abstract;

	void SetGreen() { SetColor(GREEN_COLOR); }
	void SetRed() { SetColor(RED_COLOR); }

private:
	void SetColor(ColorNum num);

	vector<HPEN> _pens;
	HPEN _curPen;

	Vector2 _center;
	float _radius;
};

