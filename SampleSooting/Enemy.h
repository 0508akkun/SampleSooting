#pragma once
#include<Siv3D.hpp>
#include "Shot.h"

class Enemy
{
	int64 speed;    //移動速度
	double shotInterval;	//弾の発射間隔
	Rect enemyRect;	//敵の実体
	Vec2 enemyPos;    //敵の位置(x,y)
	Vec2 enemySize;    //敵のサイズ(width,height)
	Array<Shot> enemyShot;	//弾を格納する配列
public:
	Enemy();	//クラスのコンストラクタ
	void move();	//プレイヤーの移動
	void show();	//プレイヤーの表示
	void shot();	//プレイヤーが弾を打つ処理
	bool checkIntersect(Rect rect);	//敵の弾が当たっているかどうか
	Rect getEnemyRect();	//敵の実体を取得
};

