#pragma once
#include<Siv3D.hpp>
#include "Shot.h"

class Player
{
	int64 speed;    //移動速度
	Vec2 playerPos;    //プレイヤーの位置(x,y)
	Vec2 playerSize;    //プレイヤーのサイズ(width,height)
	Array<Shot> playerShot;
public:
	Player();	//クラスのコンストラクタ
	void move();	//プレイヤーの移動
	void show();	//プレイヤーの表示
	void shot();
};

