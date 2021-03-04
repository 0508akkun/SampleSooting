#pragma once
#include<Siv3D.hpp>
#include "Shot.h"

class Player
{
	int64 speed;    //移動速度
	int64 score;	//スコアの保存
	Rect playerRect;	//プレイヤーの実体
	Vec2 playerPos;    //プレイヤーの位置(x,y)
	Vec2 playerSize;    //プレイヤーのサイズ(width,height)
	Array<Shot> playerShot;	//弾を格納する配列
public:
	Player();	//クラスのコンストラクタ
	void move();	//プレイヤーの移動
	void show();	//プレイヤーの表示
	void shot();	//プレイヤーが弾を打つ処理
	void checkIntersect(Rect rect);	//プレイヤーの弾が当たっているかどうか
	Rect getPlayerRect();	//プレイヤーの実体を取得
	int getScore();	//スコアの取得
};

