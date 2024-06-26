#pragma once
class Rect
{
public:
	Rect(Vector2 center, Vector2 halfsize);
	~Rect() {}

	void Update();
	void Render(HDC hdc);

public:
	Vector2 _center;
	Vector2 _halfsize;
};

