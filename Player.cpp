#include "stdafx.h"
#include "Player.h"



Player::Player()
	:GameChara(),frameNum(0),CDTimer(ANIME_INTERVAL)
{
	RectF temp[]{ {0,0,PLAYER_RECT_SIZE},{221,0,PLAYER_RECT_SIZE}, {442,0,PLAYER_RECT_SIZE},{663,0,PLAYER_RECT_SIZE}, {884,0,PLAYER_RECT_SIZE},
				 {0,154,PLAYER_RECT_SIZE},{221,154,PLAYER_RECT_SIZE},{442,154,PLAYER_RECT_SIZE} };
	for (int i = 0; i < 8; i++)
	{
		frames_.push_back(temp[i]);
	}
	Vec2 chrMargin{ 0, Scene::Height() / 2 - PLAYER_CHR_SIZE.x * 2 };
	pos_ = Scene::Center() + chrMargin;
	speed_ = PLAYER_MOVE_SPEED;
	tex_ = TextureAsset(U"PLAYER");
	SetCharaRect(PLAYER_RECT_SIZE);
	moveDir_ = { 1, 0 };
	isAlive_ = true;
}

void Player::Initialize()//とりあえず空
{
}

direction Player::GetDirection()
{
	if ((KeyUp | KeyW).pressed())
	{
		return UP;
	}
	else if ((KeyLeft | KeyA).pressed())
	{
		return LEFT;
	}
	else if ((KeyDown | KeyS).pressed())
	{
		return DOWN;
	}
	else if ((KeyRight | KeyD).pressed())
	{
		return RIGHT;
	}
	else
		return NONE;
}

void Player::Update()
{
	//CDTimerが<0になったら、フレームナムを１増加させ、CDTimerをリセット（ANIME_INTERVALにもどす）
	frameNum = (frameNum + 1)%8;

	direction d = GetDirection();
	switch (d)
	{
	case LEFT:
		moveDir_ = { -1.0, 0 };
		break;
	case RIGHT:
		moveDir_ = { 1.0, 0 };
		break;
	default:
		return;
	}
	pos_ = pos_ + speed_ * Scene::DeltaTime() * moveDir_;
	SetCharaRect(PLAYER_RECT_SIZE);


}

void Player::Draw()
{
	if (isAlive_) {
		tex_(frames_[frameNum]).resized(PLAYER_CHR_SIZE).drawAt(pos_);
		rect_.drawFrame(1, 1, Palette::Red);
	}
}

