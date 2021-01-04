#include "Shot.h"

Shot::Shot(double sx,double sy)
	:shotPos(Vec2(sx, sy)), shotSpeed(8)
{

}

void Shot::shotMove()
{
	shotPos.y -= shotSpeed;
}

void Shot::shotShow()
{
	Rect(shotPos.x, shotPos.y, 10, 10).draw(Palette::Green);
}
