#include "Shot.h"

Shot::Shot(double sx,double sy, int64 dire)
	:shotSpeed(8),
	 shotDire(1),
	 shotRect(Rect(shotPos.x, shotPos.y, shotSize.x, shotSize.y)),
	 shotPos(Vec2(sx, sy)), 
	 shotSize(Vec2(10,10))	//Shot�̊e�ϐ��̏�����
{
	shotPos.x -= shotSize.x / 2;	//�e�̑傫�������ꏊ��␳
	shotSpeed *= dire; //�e�̕��������߂�
}

void Shot::shotMove()	//�e�̓���
{
	shotPos.y += shotSpeed;	//�e��shotSpeed������Ɉړ�������
}

void Shot::shotShow()	//�e�̕\��
{
	shotRect = Rect(shotPos.x, shotPos.y, shotSize.x, shotSize.y);	//�e��x,y���W�A�e�̕�,����
	if (shotSpeed < 0) {	//speed��0��菭�Ȃ���΃v���C���[�̒e
		shotRect.draw(Palette::Green);	//�v���C���[�̒e�̎���
	}
	else {	//speed��0���傫����ΓG�̒e
		shotRect.draw(Palette::Yellow);	//�G�̒e�̎���
	}
}

bool Shot::checkIntersectsShot(Rect rect) {	//�e���������Ă��邩�ǂ���
	return shotRect.intersects(rect);	//�������Ă�����true��Ԃ�
}