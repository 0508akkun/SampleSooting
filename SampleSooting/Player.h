#pragma once
#include<Siv3D.hpp>
#include "Shot.h"

class Player
{
	int64 speed;    //�ړ����x
	Vec2 playerPos;    //�v���C���[�̈ʒu(x,y)
	Vec2 playerSize;    //�v���C���[�̃T�C�Y(width,height)
	Array<Shot> playerShot;
public:
	Player();	//�N���X�̃R���X�g���N�^
	void move();	//�v���C���[�̈ړ�
	void show();	//�v���C���[�̕\��
	void shot();
};

