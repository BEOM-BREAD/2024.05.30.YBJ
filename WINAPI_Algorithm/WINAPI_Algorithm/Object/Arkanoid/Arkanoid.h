#pragma once
class Arkanoid
{
public:
	Arkanoid();
	~Arkanoid();

	void Update();
	void Render(HDC hdc);

	void SetCenter(Vector2 position);

	bool IsBreaked() { return _isBreak; }
	void SetBrake(bool isBreak) { _isBreak = isBreak; }
	void Hit();

	shared_ptr<Collider> GetCollider() { return _col; }

private:

	shared_ptr<Collider> _col;

	bool _isBreak = false;
};
