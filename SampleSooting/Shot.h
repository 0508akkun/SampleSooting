#pragma once
#include<Siv3D.hpp>

class Shot
{
	int64 shotSpeed;	//�e�̃X�s�[�h
	int64 shotDire;		//�e�̏o�����
	Rect shotRect;	//�e�̎���
	Vec2 shotPos;	//�e�̈ʒu
	Vec2 shotSize;	//�e�̃T�C�Y
public:
	Shot(double sx, double sy, int64 dire);	//�R���X�g���N�^���`
	void shotMove();	//�e�̈ړ�
	void shotTraceMove(Rect rect, Vec2 size);	//�ǔ��e�̈ړ�
	void shotShow();	//�e�̕\��
	bool checkIntersectsShot(Rect rect);	//�e���������Ă��邩�ǂ���
};

