#include "Player.h"

Player::Player() 
    :speed(8),playerPos(Vec2(375, 500)),playerSize(Vec2(50, 50)),playerShot(Array<Shot>()) //Player�N���X�̕ϐ��̏�����
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
    Rect(playerPos.x, playerPos.y, playerSize.x, playerSize.y).draw(Palette::Blue);   //���݂�x,y���W�A�v���C���[�̕�,����
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