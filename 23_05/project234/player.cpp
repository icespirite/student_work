#include <iostream>
using namespace std;
#include "game.h"
#include "player.h"

// ����c�� ������ �� ���� (n=1 - ����, n=2 - ����)
Player::Player(int n, int ix, int jy)
{
	int i,j;
        count_steps = 0;
        fstep = 0;
        if (n<0) {
            ii = ix; jj = jy;
            return;
        }
	while(1)
	{
		i=rand()%Game::isize; 
		j=rand()%Game::jsize;
		if( Game::mas[i][j] == 0 )
		{
			Game::mas[i][j] = n;
			ii = i; jj = j;
			break;
		}
	}
}
