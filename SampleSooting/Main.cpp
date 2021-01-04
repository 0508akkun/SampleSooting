# include <Siv3D.hpp> // OpenSiv3D v0.4.3
# include "Scene.h"

void Main()
{
	FontAsset::Register(U"MainFont", 50, Typeface::Heavy);
	FontAsset::Register(U"SubFont", 20, Typeface::Heavy);
	App manager;
	manager.add<Title>(U"Title");
	manager.add<Game>(U"Game");
	manager.add<Ending>(U"Ending");

	while (System::Update())
	{
		// 現在のシーンを実行
		if (!manager.update())
		{
			break;
		}
	}
}
