#pragma once
#include "koord.h"
// �����
class Player
{
protected:
	int ii,jj; // ��� ���������� � ������� ����
	int count_steps; // ���������� �������� �����
	int fstep; // 0 - ��� �� ����� (� ������), 1 - ��� �����
public:
        Player(int n, int ix = 0, int jy = 0);
	int is_step();
	int get_ii() { return ii; }
	int get_jj() { return jj; }
	void set_ii(int i) { ii = i; }
	void set_jj(int j ) { jj = j; }
	int get_count_steps() { return count_steps; }
	void set_count_steps(int n) { count_steps = n; }
	int get_fstep() { return fstep; }
        void clear_fstep() { fstep = 0;}
};
