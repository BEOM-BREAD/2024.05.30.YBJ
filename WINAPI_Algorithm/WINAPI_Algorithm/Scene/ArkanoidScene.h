#pragma once
#define MAXWIDTHCNT 10
#define MAXHIGHTCNT 4


class ArkanoidScene : public Scene
{
public:
	ArkanoidScene();
	~ArkanoidScene();

	void Update() override;
	void Render(HDC hdc) override;

private:
	shared_ptr<class Stick> _player;
	vector<vector<shared_ptr<class Arkanoid>>> _blocks;
};

