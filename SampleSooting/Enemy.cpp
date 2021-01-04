#include "Enemy.h"

Enemy::Enemy()
    :speed(8),
     shotInterval(0),
     enemyRect(Rect(enemyPos.x, enemyPos.y, enemySize.x, enemySize.y)),
     enemyPos(Vec2(375, 50)),
     enemySize(Vec2(50, 50)),
     enemyShot(Array<Shot>())   //Enemyクラスの変数の初期化
{
}

void Enemy::move() {   //敵の移動
    if (enemyPos.x < 0 || enemyPos.x > Scene::Width() - enemySize.x) {  //端に移動したら
        speed *= -1;//方向を変えて
    }
    enemyPos.x += speed;    //移動する
}

void Enemy::show() {   //敵の表示
    enemyRect = Rect(enemyPos.x, enemyPos.y, enemySize.x, enemySize.y); //現在のx,y座標、敵の幅,高さ
    enemyRect.draw(Palette::Red);   
    for (auto& shot : enemyShot) {  //生成されている弾全ての
        shot.shotShow(); //弾の表示
    }
}

void Enemy::shot() {   //弾の発射処理
    shotInterval += Scene::DeltaTime(); //微小時間足す
    if (shotInterval > 1) {  //1秒経つと
        enemyShot << Shot(enemyPos.x + enemySize.x / 2, enemyPos.y + enemySize.y ,1); //弾を生成
        shotInterval = 0;   //タイマーを0に
    }
    for (auto& shot : enemyShot) {  //生成されている弾全ての
        shot.shotMove(); //弾の動きを作成
    }
}

void Enemy::checkIntersect(Rect rect) { //敵の弾が当たっているかどうか
    for (auto& shot : enemyShot) {  //生成されている弾全てのどれかが
        if (shot.checkIntersectsShot(rect)) {   //プレイヤーに当たれば
            //ゲームオーバー処理
        }
    }
}

Rect Enemy::getEnemyRect()  //敵の実体を取得
{
    return enemyRect;
}