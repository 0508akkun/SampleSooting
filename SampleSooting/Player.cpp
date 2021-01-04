#include "Player.h"

Player::Player() 
    :speed(8),playerPos(Vec2(375, 500)),playerSize(Vec2(50, 50)),playerShot(Array<Shot>()) //Playerクラスの変数の初期化
{
}

void Player::move() {   //プレイヤーの移動
    if (KeyLeft.pressed())  //←キーを押したら
    {
        playerPos.x -= speed;   //左に移動
    }
    if (KeyRight.pressed()) //→キーを押したら
    {
        playerPos.x += speed;   //右に移動
    }
    if (playerPos.x < 0) {  //左端に移動したら
        playerPos.x = 0;    //それ以上は左に移動しない
    }
    if (playerPos.x > Scene::Width() - playerSize.x) {  //右端に移動したら
        playerPos.x = Scene::Width() - playerSize.x;    //それ以上は右に移動しない
    }
}

void Player::show() {   //  プレイヤーの表示
    Rect(playerPos.x, playerPos.y, playerSize.x, playerSize.y).draw(Palette::Blue);   //現在のx,y座標、プレイヤーの幅,高さ
    for (auto& shotPos : playerShot) {
        shotPos.shotMove();
        shotPos.shotShow();
    }
}

void Player::shot() {
    
    if (KeySpace.down()) {
        playerShot.emplace_back(playerPos.x, playerPos.y);
    }
}