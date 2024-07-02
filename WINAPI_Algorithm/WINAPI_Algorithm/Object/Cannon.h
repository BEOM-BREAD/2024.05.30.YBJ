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

	bool IsActive = true;
	bool IsDead() { return _hp <= 0; }
	bool isControlled = false;
	bool CanControl = true;
	void TakeDamage();
	int GetBulletvs() { return _bulletvs; }
	void ResetBulletvs() { _bulletvs = 0; }

	shared_ptr<Collider> GetCollider() { return _body; }
	vector<shared_ptr<class Bullet>>& GetBullets() { return _bullets; }

private:
	int _hp = 5;
	shared_ptr<Collider> _body;
	shared_ptr<class Barrel> _barrel;
	vector<shared_ptr<class Bullet>> _bullets;

	int _bulletvs = 0;

	float _angle = 0.0f;
};

