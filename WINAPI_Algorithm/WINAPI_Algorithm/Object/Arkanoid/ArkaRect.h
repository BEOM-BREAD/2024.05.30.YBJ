#pragma once

#define GREEN_COLOR		 0
#define RED_COLOR	     1

using ColorNum = int;

class ArkaRect : public RectCollider
{
public:
	enum class BlockType
	{
		GAME,
		GAMEOVER
	};

	ArkaRect();
	~ArkaRect();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	void SetPosition(Vector2 pos);

	void SetBlockType(BlockType type);
	BlockType GetBlockType() { return _type; }


private:
	BlockType _type = BlockType::GAME;

	vector<HBRUSH> _brushes;
};

