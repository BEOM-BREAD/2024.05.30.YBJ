#pragma once
class Program
{
public:
	Program();
	~Program();

	void Update();
	// ±×¸®±â
	void Render(HDC hdc);

private:
	shared_ptr<class Scene> _scene;
};

