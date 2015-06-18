#define S_INTERVAL 200
#define W_LIVE 12 // жизнь волков
#define S_LIVE 10 // рождение овец

#include <iostream>
#include <time.h>
using namespace std;
#include "game.h"


int **Game::mas=0;
int Game::isize=0;
int Game::jsize=0;
int Game::interval=S_INTERVAL;
vector<Woolf> Game::woolf;
vector<Sheep> Game::sheep;
// создаем  нулевую матрицу размерами is x js
Game::Game( int is, int js)
{
	srand( (unsigned)time( NULL ) );

	isize = is;
	jsize = js;
	mas=new int *[is];
	for( int i=0; i<is; i++)
            mas[i] = new int[js]();


}
Game::~Game()
{
	if(mas)
	{
            for( int i=0; i<isize; i++)
                delete mas[i];
            delete mas;
            mas=0;
	}
        woolf.clear();
        sheep.clear();
}
void Game::add_woolf() // добавление волка
{
        woolf.push_back(Woolf(1));
}
void Game::add_woolf_S(int n) // добавление n волков
{
	for(int i=0;i<n;i++)
		add_woolf();
}
void Game::add_sheep() // добавление овцы
{
        sheep.push_back(Sheep(2));
}
void Game::add_sheep_S(int n) // добавление n овец
{
	for(int i=0;i<n;i++)
		add_sheep();
}
void Game::kill_sheep( int i, int j) // удаление овцы с координатами i j
{
	vector<Sheep>::iterator it;
	for( it = sheep.begin(); it!=sheep.end(); ++it)
	{
		if( it->get_ii() == i && it->get_jj() == j )
		{
			sheep.erase(it);
			return;
		}
	}
}
void Game::step_woolfS() // ход волков
{
        int live = W_LIVE;
	vector<Woolf>::iterator it;
        int ret=0, a=0;
        for( it = woolf.begin(); it!=woolf.end(); ++it, a++)
	{

                if( it->get_fstep() == 0 ) // если волк еще не ходил
                {
                        ret = it->step(); // ход текущего волка
                        break;
                }
	}

        if (a==woolf.size()) {
            for( it = woolf.begin(); it!=woolf.end(); ++it) it->clear_fstep();
            it = woolf.begin();
            ret = it->step(); // ход первого волка
        }

        if( it->get_count_steps() >= live ) // волк сходил live  и более раз - удаляем его
        {
                Game::mas[it->get_ii()][it->get_jj()] = 0;
                woolf.erase(it);
        }
        if( ret == 1 ) add_woolf();

}

void Game::step_sheepS() // ход овец
{
        int a = 0;
	vector<Sheep>::iterator it;
        for( it = sheep.begin(); it!=sheep.end(); ++it)
	{
                a++;
		if( it->get_fstep() == 0 ) // если овца еще не ходила
		{
			it->step(); // ход текущей овцы
                        break;
		}
	}

        if (a==sheep.size()){
                for( it = sheep.begin(); it!=sheep.end(); ++it) it->clear_fstep();
                it = sheep.begin();
                it->step(); // ход первой овцы
        }

        if( it->get_count_steps() >= S_LIVE ) // овца сходила 5  и более раз - добавлям еще одну
        {
                it->set_count_steps(0);
                add_sheep();
        }
}

// проверка на конец игры
int Game::check_end()
{
        // нет свободных мест
        bool f = false;
        for(int i=0; i<isize; i++)
        {
                for( int j = 0;j<jsize; j++)
                {
                        if(mas[i][j] == 0)
                        {
                                f=true;
                                j=jsize;
                                i=jsize;
                        }

                }
        }

        // нет волков
        if( woolf.empty() )
                return 1;
        // нет овец
        if( sheep.empty() )
                return 2;
        // пат
        if( f == false )
                return 3;

        // еще можно играть
        return 0;
}
