#pragma once
#include <vector>
using namespace std;
#include "woolf.h"
#include "sheep.h"
// ����
class Game
{
    //static vector<Woolf> woolf; // �����
    //static vector<Sheep> sheep; // ����
public:
        static vector<Woolf> woolf; // �����
        static vector<Sheep> sheep; // ����
	static int **mas; // ������� ����
	static int isize; // ������� �������
	static int jsize;
        static int interval;
	Game( int i, int j); 
	~Game();
	void add_woolf();
	void add_woolf_S(int n);
	void add_sheep();
	void add_sheep_S(int n);
	static void kill_sheep( int i, int j);
	void kill_sheeps();
	void step_woolfS();
	void step_sheepS();
	bool check_free(int n);
	int check_end();
	static int free_mas(int n);
};
