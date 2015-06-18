#define S_INTERVAL 200
#define W_LIVE 12 // ����� ������
#define S_LIVE 10 // �������� ����

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
// �������  ������� ������� ��������� is x js
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
void Game::add_woolf() // ���������� �����
{
        woolf.push_back(Woolf(1));
}
void Game::add_woolf_S(int n) // ���������� n ������
{
	for(int i=0;i<n;i++)
		add_woolf();
}
void Game::add_sheep() // ���������� ����
{
        sheep.push_back(Sheep(2));
}
void Game::add_sheep_S(int n) // ���������� n ����
{
	for(int i=0;i<n;i++)
		add_sheep();
}
void Game::kill_sheep( int i, int j) // �������� ���� � ������������ i j
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
void Game::step_woolfS() // ��� ������
{
        int live = W_LIVE;
	vector<Woolf>::iterator it;
        int ret=0, a=0;
        for( it = woolf.begin(); it!=woolf.end(); ++it, a++)
	{

                if( it->get_fstep() == 0 ) // ���� ���� ��� �� �����
                {
                        ret = it->step(); // ��� �������� �����
                        break;
                }
	}

        if (a==woolf.size()) {
            for( it = woolf.begin(); it!=woolf.end(); ++it) it->clear_fstep();
            it = woolf.begin();
            ret = it->step(); // ��� ������� �����
        }

        if( it->get_count_steps() >= live ) // ���� ������ live  � ����� ��� - ������� ���
        {
                Game::mas[it->get_ii()][it->get_jj()] = 0;
                woolf.erase(it);
        }
        if( ret == 1 ) add_woolf();

}

void Game::step_sheepS() // ��� ����
{
        int a = 0;
	vector<Sheep>::iterator it;
        for( it = sheep.begin(); it!=sheep.end(); ++it)
	{
                a++;
		if( it->get_fstep() == 0 ) // ���� ���� ��� �� ������
		{
			it->step(); // ��� ������� ����
                        break;
		}
	}

        if (a==sheep.size()){
                for( it = sheep.begin(); it!=sheep.end(); ++it) it->clear_fstep();
                it = sheep.begin();
                it->step(); // ��� ������ ����
        }

        if( it->get_count_steps() >= S_LIVE ) // ���� ������� 5  � ����� ��� - �������� ��� ����
        {
                it->set_count_steps(0);
                add_sheep();
        }
}

// �������� �� ����� ����
int Game::check_end()
{
        // ��� ��������� ����
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

        // ��� ������
        if( woolf.empty() )
                return 1;
        // ��� ����
        if( sheep.empty() )
                return 2;
        // ���
        if( f == false )
                return 3;

        // ��� ����� ������
        return 0;
}
