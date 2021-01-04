#pragma once
#include<Siv3D.hpp>

class Shot
{
	int64 shotSpeed;	//弾のスピード
	int64 shotDire;		//弾の出る方向
	Rect shotRect;	//弾の実体
	Vec2 shotPos;	//弾の位置
	Vec2 shotSize;	//弾のサイズ
public:
	Shot(double sx, double sy, int64 dire);	//コンストラクタを定義
	void shotMove();	//弾の移動
	void shotShow();	//弾の表示
	bool checkIntersectsShot(Rect rect);	//弾が当たっているかどうか
};

