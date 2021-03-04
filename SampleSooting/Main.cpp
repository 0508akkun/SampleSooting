# include <Siv3D.hpp> // OpenSiv3D v0.4.3
# include "Scene.h"

void Main()
{
	FontAsset::Register(U"MainFont", 50, Typeface::Heavy);	//メインフォントの生成
	FontAsset::Register(U"SubFont", 20, Typeface::Heavy);	//サブフォントの生成
	App manager;	//アプリのシーンマネージャーの宣言
	manager.add<Title>(U"Title");	//Titleというシーンを追加
	manager.add<Game>(U"Game");	//Gameというシーンを追加
	manager.add<Ending>(U"Ending");	//Endingというシーンを追加	

	while (System::Update())
	{
		// 現在のシーンを実行
		if (!manager.update())
		{
			break;	//終了の条件を満たすと終了(escキーなど)
		}
	}
}
