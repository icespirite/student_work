#pragma once
#include "player.h"
// ����
class Woolf : public Player
{
public:
        Woolf(int n, int ix=0, int jy=0) : Player(n, ix, jy) {}
	int step();
};
