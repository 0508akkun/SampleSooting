#include "Enemy.h"

Enemy::Enemy()
    :speed(8),
     shotInterval(0),
     enemyRect(Rect(enemyPos.x, enemyPos.y, enemySize.x, enemySize.y)),
     enemyPos(Vec2(375, 50)),
     enemySize(Vec2(50, 50)),
     enemyShot(Array<Shot>())   //Enemy�N���X�̕ϐ��̏�����
{
}

void Enemy::move() {   //�G�̈ړ�
    if (enemyPos.x < 0 || enemyPos.x > Scene::Width() - enemySize.x) {  //�[�Ɉړ�������
        speed *= -1;//������ς���
    }
    enemyPos.x += speed;    //�ړ�����
}

void Enemy::show() {   //�G�̕\��
    enemyRect = Rect(enemyPos.x, enemyPos.y, enemySize.x, enemySize.y); //���݂�x,y���W�A�G�̕�,����
    enemyRect.draw(Palette::Red);   
    for (auto& shot : enemyShot) {  //��������Ă���e�S�Ă�
        shot.shotShow(); //�e�̕\��
    }
}

void Enemy::shot() {   //�e�̔��ˏ���
    shotInterval += Scene::DeltaTime(); //�������ԑ���
    if (shotInterval > 1) {  //1�b�o��
        enemyShot << Shot(enemyPos.x + enemySize.x / 2, enemyPos.y + enemySize.y ,1); //�e�𐶐�
        shotInterval = 0;   //�^�C�}�[��0��
    }
    for (auto& shot : enemyShot) {  //��������Ă���e�S�Ă�
        shot.shotMove(); //�e�̓������쐬
    }
}

bool Enemy::checkIntersect(Rect rect) { //�G�̒e���������Ă��邩�ǂ���
    for (auto& shot : enemyShot) {  //��������Ă���e�S�Ă̂ǂꂩ��
        if (shot.checkIntersectsShot(rect)) {   //�v���C���[�ɓ������
            return true;
        }
    }
    return false;
}

Rect Enemy::getEnemyRect()  //�G�̎��̂��擾
{
    return enemyRect;
}