#pragma once
class CollisionScene : public Scene
{
public:
	CollisionScene();
	~CollisionScene();

	// Scene��(��) ���� ��ӵ�
	void Update() override;
	void Render(HDC hdc) override;

public:
	shared_ptr<CircleCollider> _circle1;
	shared_ptr<CircleCollider> _moveCircle;
	shared_ptr<RectCollider> _rect1;
	shared_ptr<RectCollider> _moveRect;
};


