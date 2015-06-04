#pragma once
#include <vector>
using namespace std;
#include "woolf.h"
#include "sheep.h"
// Игра
class Game
{
    //static vector<Woolf> woolf; // волки
    //static vector<Sheep> sheep; // овцы
public:
        static vector<Woolf> woolf; // волки
        static vector<Sheep> sheep; // овцы
	static int **mas; // матрица поля
	static int isize; // размеры матрицы
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
