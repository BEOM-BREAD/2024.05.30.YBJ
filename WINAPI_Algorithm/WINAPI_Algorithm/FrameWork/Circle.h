#pragma once
class Circle 
{
public:
	Circle();
	virtual ~Circle();

	void Update();
	void Render(HDC hdc);

private:
	shared_ptr<Circle> _circle;
};

