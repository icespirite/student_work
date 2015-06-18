#pragma once

#include "player.h"
// овца
class Sheep : public Player
{
public:
        Sheep(int n, int ix=0, int jy=0) : Player(n, ix, jy) {}
	void step();
};
