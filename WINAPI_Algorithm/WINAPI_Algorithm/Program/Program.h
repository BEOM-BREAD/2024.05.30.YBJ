#pragma once
class Program
{
public:
	Program();
	~Program();

	void Update();
	// �׸���
	void Render(HDC hdc);

	static HDC backBuffer;
	// Buffer : �ӽ������ (�� ���������� �����ϰų�, ���޹�����)
	// backBuffer : ȭ�鿡 ��������� ������ �ӽ������� �׸��� �׸��� ��

private:
	shared_ptr<class Scene> _scene;

	HBITMAP _hbitMap;
};

