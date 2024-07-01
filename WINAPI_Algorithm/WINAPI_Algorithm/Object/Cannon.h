#pragma once
class Cannon
{
public:
	Cannon();
	~Cannon();

	void Update();
	void Render(HDC hdc);

	void Move();
	void Fire();
	void TakeDamage();

	bool isControlled = false;

	bool IsDestroyed() const { return _hp <= 0; }
	shared_ptr<Collider> GetCollider() { return _body; }
	vector<shared_ptr<class Bullet>>& GetBullets() { return _bullets; }

private:
	shared_ptr<Collider> _body;
	shared_ptr<class Barrel> _barrel;
	vector<shared_ptr<class Bullet>> _bullets;

	float _angle = 0.0f;
	int _hp = 5;
};


