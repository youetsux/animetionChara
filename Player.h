#pragma once
#include "GameChara.h"
#include <vector>

using std::vector;

const SizeF PLAYER_CHR_SIZE{ 221, 154 }; //がぞうさいず
const SizeF PLAYER_RECT_SIZE{ 221, 154 }; //当たり判定用のBBのサイズ
const double PLAYER_MOVE_SPEED{ PLAYER_CHR_SIZE.x * 1.5 }; //プレイヤーの動作スピード
const int MAX_FRAME_NUM{ 8 };//アニメのコマ数
const double ANIME_INTERVAL{ 60 / 20.0 };

enum direction
{
	UP, LEFT, DOWN, RIGHT, NONE
};


class Player :
    public GameChara
{
	int frameNum;//今のアニメフレームは何フレーム目？
	double CDTimer;
public:
	Player();
	~Player();//解放処理ここでやる？
	vector<RectF> frames_;
	void Initialize();
	void Release();//それともここでやる？
	direction GetDirection();
	void Update() override;
	void Draw() override;
};

