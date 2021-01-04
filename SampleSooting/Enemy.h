#pragma once
#include<Siv3D.hpp>
#include "Shot.h"

class Enemy
{
	int64 speed;    //�ړ����x
	double shotInterval;	//�e�̔��ˊԊu
	Rect enemyRect;	//�G�̎���
	Vec2 enemyPos;    //�G�̈ʒu(x,y)
	Vec2 enemySize;    //�G�̃T�C�Y(width,height)
	Array<Shot> enemyShot;	//�e���i�[����z��
public:
	Enemy();	//�N���X�̃R���X�g���N�^
	void move();	//�v���C���[�̈ړ�
	void show();	//�v���C���[�̕\��
	void shot();	//�v���C���[���e��ł���
	void checkIntersect(Rect rect);	//�G�̒e���������Ă��邩�ǂ���
	Rect getEnemyRect();	//�G�̎��̂��擾
};

