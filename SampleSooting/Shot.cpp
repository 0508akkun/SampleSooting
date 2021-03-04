#include "Shot.h"

Shot::Shot(double sx,double sy, int64 dire)
	:shotSpeed(8),
	 shotDire(1),
	 shotRect(Rect(shotPos.x, shotPos.y, shotSize.x, shotSize.y)),
	 shotPos(Vec2(sx, sy)), 
	 shotSize(Vec2(10,10))	//Shotの各変数の初期化
{
	shotPos.x -= shotSize.x / 2;	//弾の大きさだけ場所を補正
	shotSpeed *= dire; //弾の方向を決める
}

void Shot::shotMove()	//弾の動き
{
	shotPos.y += shotSpeed;	//弾をshotSpeedだけ上に移動させる
}

void Shot::shotTraceMove(Rect rect, Vec2 size) {
	shotPos.y += shotSpeed;
	shotPos.x -= (shotPos.x - (rect.x + size.x / 2)) * 0.03;
}

void Shot::shotShow()	//弾の表示
{
	shotRect = Rect(shotPos.x, shotPos.y, shotSize.x, shotSize.y);	//弾のx,y座標、弾の幅,高さ
	if (shotSpeed < 0) {	//speedが0より少なければプレイヤーの弾
		shotRect.draw(Palette::Green);	//プレイヤーの弾の実体
	}
	else {	//speedが0より大きければ敵の弾
		shotRect.draw(Palette::Yellow);	//敵の弾の実体
	}
}

bool Shot::checkIntersectsShot(Rect rect) {	//弾が当たっているかどうか
	return shotRect.intersects(rect);	//当たっていたらtrueを返す
}