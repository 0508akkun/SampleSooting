#pragma once
#include<Siv3D.hpp>

class Shot
{
	int64 shotSpeed;
	Vec2 shotPos;
public:
	Shot() = default;
	Shot(double sx, double sy);
	void shotMove();
	void shotShow();
};

