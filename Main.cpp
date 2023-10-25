# include <Siv3D.hpp> // OpenSiv3D v0.6.10
#include "Player.h"

void Main()
{
	// 背景の色を設定する | Set the background color
	Scene::SetBackground(Palette::Lightgreen);
	TextureAsset::Register(U"PLAYER", U"neko.png");

	Player *p = new Player();

	while (System::Update())
	{
		p->Update();
		p->Draw();
	}
}


