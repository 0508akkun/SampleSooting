#include "Player.h"

Player::Player() 
    :speed(8),
     playerRect(Rect(playerPos.x, playerPos.y, playerSize.x, playerSize.y)),
     playerPos(Vec2(375, 500)),playerSize(Vec2(50, 50)),
     playerShot(Array<Shot>()),
     score(0) //Playerクラスの変数の初期化
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
    playerRect = Rect(playerPos.x, playerPos.y, playerSize.x, playerSize.y);    //現在のx,y座標、プレイヤーの幅,高さ
    playerRect.draw(Palette::Blue);   
    for (auto& shot : playerShot) {  //生成されている弾全ての
        shot.shotShow(); //弾の表示
    }
}

void Player::shot() {   //弾の発射処理
    if (KeySpace.down()) {  //Spaceを押すと
        playerShot << Shot(playerPos.x + playerSize.x/2, playerPos.y,-1); //弾を生成
    }
    for (auto& shot : playerShot) {  //生成されている弾全ての
        shot.shotMove(); //弾の動きを作成
    }
}

void Player::checkIntersect(Rect rect) {    //プレイヤーの弾が当たっているかどうか
    for (auto it = playerShot.begin(); it != playerShot.end();){    //生成されている弾全てのどれかが
        if (it->checkIntersectsShot(rect)) {    //敵に当たれば
            it = playerShot.erase(it);  //当たった弾を削除してイテレータを進める
            score += 100;   //スコアを加算
        }
        else {
            ++it;   //イテレータを進める
        }
    }
}

Rect Player::getPlayerRect()    //Playerの実体を取得
{
    return playerRect;
}

int Player::getScore() {
    return score;
}