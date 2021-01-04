#include "Scene.h"

Title::Title(const InitData& init)
    : IScene(init)
{
}

void Title::update()
{
	if (KeySpace.down())	//Spaceを押したら
	{
		// ゲームシーンに遷移
		changeScene(U"Game");
	}
}

void Title::draw() const
{
	FontAsset(U"MainFont")(U"シューティングゲーム").drawAt(400, 300);
	FontAsset(U"SubFont")(U"スペースキーで開始").drawAt(400, 350);
}

Game::Game(const InitData& init)
    : IScene(init)
{
    
}

void Game::update()
{
	player.move();	//プレイヤーの移動
	player.shot();	//プレイヤーの弾を撃つ処理
	player.show();	//プレイヤーの表示
	player.checkIntersect(enemy.getEnemyRect());
	enemy.move();	//敵の移動
	enemy.shot();	//敵の弾を発射
	enemy.show();	//敵の表示
	getData().score = player.getScore();
	if (enemy.checkIntersect(player.getPlayerRect())) {
		changeScene(U"Ending");
	}
}

void Game::draw() const 
{
	FontAsset(U"SubFont")(U"Score: {}"_fmt(getData().score)).draw(0, 0);
	FontAsset(U"SubFont")(U"HIghScore: {}"_fmt(getData().highScore)).draw(0, 20);
}

Ending::Ending(const InitData& init)
    : IScene(init), highScore(0)
{
}

void Ending::update()
{
	highScore = getData().highScore;
	if (getData().score > highScore) {
		highScore = getData().score;
		getData().highScore = highScore;
	}
	if (KeySpace.down())	//Spaceを押したら
	{
		// ゲームオーバーシーンに遷移
		changeScene(U"Game");
	}
}

void Ending::draw() const
{
	FontAsset(U"MainFont")(U"ゲームオーバー").drawAt(400, 200);
	FontAsset(U"SubFont")(U"スペースキーでRetry").drawAt(400, 250);
	FontAsset(U"SubFont")(U"Escで終了").drawAt(400, 300);
	FontAsset(U"SubFont")(U"今回のScore: {}"_fmt(getData().score)).drawAt(400, 350);
	FontAsset(U"SubFont")(U"HIghScore: {}"_fmt(highScore)).drawAt(400, 400);
}
