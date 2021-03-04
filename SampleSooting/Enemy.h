#pragma once
#include<Siv3D.hpp>
#include "Shot.h"

class Enemy
{
	int64 speed;    //�ړ����x
	double shotInterval;	//�e�̔��ˊԊu
	double shotTraceInterval;	//�e�̔��ˊԊu
	Rect enemyRect;	//�G�̎���
	Vec2 enemyPos;    //�G�̈ʒu(x,y)
	Vec2 enemySize;    //�G�̃T�C�Y(width,height)
	Array<Shot> enemyShot;	//�e���i�[����z��
	Array<Shot> enemyTraceShot;	//�e���i�[����z��
public:
	Enemy();	//�N���X�̃R���X�g���N�^
	void move();	//�v���C���[�̈ړ�
	void show();	//�v���C���[�̕\��
	void shot(Rect rect, Vec2 vec);	//�v���C���[���e��ł���
	bool checkIntersect(Rect rect);	//�G�̒e���������Ă��邩�ǂ���
	Rect getEnemyRect();	//�G�̎��̂��擾
	Vec2 getEnemySize();
};

