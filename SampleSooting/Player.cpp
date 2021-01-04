#include "Player.h"

Player::Player() 
    :speed(8),
     playerRect(Rect(playerPos.x, playerPos.y, playerSize.x, playerSize.y)),
     playerPos(Vec2(375, 500)),playerSize(Vec2(50, 50)),
     playerShot(Array<Shot>()),
     score(0) //Player�N���X�̕ϐ��̏�����
{
}

void Player::move() {   //�v���C���[�̈ړ�
    if (KeyLeft.pressed())  //���L�[����������
    {
        playerPos.x -= speed;   //���Ɉړ�
    }
    if (KeyRight.pressed()) //���L�[����������
    {
        playerPos.x += speed;   //�E�Ɉړ�
    }
    if (playerPos.x < 0) {  //���[�Ɉړ�������
        playerPos.x = 0;    //����ȏ�͍��Ɉړ����Ȃ�
    }
    if (playerPos.x > Scene::Width() - playerSize.x) {  //�E�[�Ɉړ�������
        playerPos.x = Scene::Width() - playerSize.x;    //����ȏ�͉E�Ɉړ����Ȃ�
    }
}

void Player::show() {   //  �v���C���[�̕\��
    playerRect = Rect(playerPos.x, playerPos.y, playerSize.x, playerSize.y);    //���݂�x,y���W�A�v���C���[�̕�,����
    playerRect.draw(Palette::Blue);   
    for (auto& shot : playerShot) {  //��������Ă���e�S�Ă�
        shot.shotShow(); //�e�̕\��
    }
}

void Player::shot() {   //�e�̔��ˏ���
    if (KeySpace.down()) {  //Space��������
        playerShot << Shot(playerPos.x + playerSize.x/2, playerPos.y,-1); //�e�𐶐�
    }
    for (auto& shot : playerShot) {  //��������Ă���e�S�Ă�
        shot.shotMove(); //�e�̓������쐬
    }
}

void Player::checkIntersect(Rect rect) {    //�v���C���[�̒e���������Ă��邩�ǂ���
    for (auto it = playerShot.begin(); it != playerShot.end();){    //��������Ă���e�S�Ă̂ǂꂩ��
        if (it->checkIntersectsShot(rect)) {    //�G�ɓ������
            it = playerShot.erase(it);  //���������e���폜���ăC�e���[�^��i�߂�
            score += 100;   //�X�R�A�����Z
        }
        else {
            ++it;   //�C�e���[�^��i�߂�
        }
    }
}

Rect Player::getPlayerRect()    //Player�̎��̂��擾
{
    return playerRect;
}
