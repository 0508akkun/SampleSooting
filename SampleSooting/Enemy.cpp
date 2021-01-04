#include "Enemy.h"

Enemy::Enemy()
    :speed(8),
     shotInterval(0),
     enemyRect(Rect(enemyPos.x, enemyPos.y, enemySize.x, enemySize.y)),
     enemyPos(Vec2(375, 50)),
     enemySize(Vec2(50, 50)),
     enemyShot(Array<Shot>())   //EnemyƒNƒ‰ƒX‚Ì•Ï”‚Ì‰Šú‰»
{
}

void Enemy::move() {   //“G‚ÌˆÚ“®
    if (enemyPos.x < 0 || enemyPos.x > Scene::Width() - enemySize.x) {  //’[‚ÉˆÚ“®‚µ‚½‚ç
        speed *= -1;//•ûŒü‚ğ•Ï‚¦‚Ä
    }
    enemyPos.x += speed;    //ˆÚ“®‚·‚é
}

void Enemy::show() {   //“G‚Ì•\¦
    enemyRect = Rect(enemyPos.x, enemyPos.y, enemySize.x, enemySize.y); //Œ»İ‚Ìx,yÀ•WA“G‚Ì•,‚‚³
    enemyRect.draw(Palette::Red);   
    for (auto& shot : enemyShot) {  //¶¬‚³‚ê‚Ä‚¢‚é’e‘S‚Ä‚Ì
        shot.shotShow(); //’e‚Ì•\¦
    }
}

void Enemy::shot() {   //’e‚Ì”­Ëˆ—
    shotInterval += Scene::DeltaTime(); //”÷¬ŠÔ‘«‚·
    if (shotInterval > 1) {  //1•bŒo‚Â‚Æ
        enemyShot << Shot(enemyPos.x + enemySize.x / 2, enemyPos.y + enemySize.y ,1); //’e‚ğ¶¬
        shotInterval = 0;   //ƒ^ƒCƒ}[‚ğ0‚É
    }
    for (auto& shot : enemyShot) {  //¶¬‚³‚ê‚Ä‚¢‚é’e‘S‚Ä‚Ì
        shot.shotMove(); //’e‚Ì“®‚«‚ğì¬
    }
}

bool Enemy::checkIntersect(Rect rect) { //“G‚Ì’e‚ª“–‚½‚Á‚Ä‚¢‚é‚©‚Ç‚¤‚©
    for (auto& shot : enemyShot) {  //¶¬‚³‚ê‚Ä‚¢‚é’e‘S‚Ä‚Ì‚Ç‚ê‚©‚ª
        if (shot.checkIntersectsShot(rect)) {   //ƒvƒŒƒCƒ„[‚É“–‚½‚ê‚Î
            return true;
        }
    }
    return false;
}

Rect Enemy::getEnemyRect()  //“G‚ÌÀ‘Ì‚ğæ“¾
{
    return enemyRect;
}