# include <Siv3D.hpp> // OpenSiv3D v0.4.3
# include "Player.h"
# include "Enemy.h"
#include "Main.h"

void Main()
{
	const Font font(20);	//フォントのサイズを指定
	Player p;	//コンストラクタの宣言
	Enemy e;
	while (System::Update())
	{
		p.move();	//プレイヤーの移動
		p.show();	//プレイヤーの表示
		p.shot();	//プレイヤーの弾を撃つ処理
		p.checkIntersect(e.getEnemyRect());
		e.move();	//敵の移動
		e.show();	//敵の表示
		e.shot();	//敵の弾を発射
		e.checkIntersect(p.getPlayerRect());
		font(p.score).draw(0, 0);	//スコアの表示
	}
}
