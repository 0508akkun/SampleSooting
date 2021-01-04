#pragma once
#include<Siv3D.hpp>
#include "Shot.h"

class Player
{
	int64 speed;    //�ړ����x
	Rect playerRect;	//�v���C���[�̎���
	Vec2 playerPos;    //�v���C���[�̈ʒu(x,y)
	Vec2 playerSize;    //�v���C���[�̃T�C�Y(width,height)
	Array<Shot> playerShot;	//�e���i�[����z��
public:
	int64 score;	//�X�R�A�̕ۑ�
	Player();	//�N���X�̃R���X�g���N�^
	void move();	//�v���C���[�̈ړ�
	void show();	//�v���C���[�̕\��
	void shot();	//�v���C���[���e��ł���
	void checkIntersect(Rect rect);	//�v���C���[�̒e���������Ă��邩�ǂ���
	Rect getPlayerRect();	//�v���C���[�̎��̂��擾
};

