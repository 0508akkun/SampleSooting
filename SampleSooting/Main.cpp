# include <Siv3D.hpp> // OpenSiv3D v0.4.3
# include "Player.h"

void Main()
{
	Player p;	//コンストラクタの宣言
	while (System::Update())
	{
		p.move();	//プレイヤーの移動
		p.show();	//プレイヤーの表示
		p.shot();
	}
}
