#include "sheep.h"
#include "game.h"
#include <iostream>
#include <conio.h>
#include <time.h>
using namespace std;

// Xод овцы
void Sheep::step()
{
    int rX;
    int rY;
    while (1) {
        while (1) {
            rX = (rand()%3)-1;
            rY = (rand()%3)-1;
            if ((ii+rX<Game::isize && ii+rX>=0) && (jj+rY<Game::jsize && jj+rY>=0)) break;
        }
        if (Game::mas[ii+rX][jj+rY] == 0 || (rX==0 && rY==0)) {
            Game::mas[ii][jj] = 0;
            Game::mas[ii+rX][jj+rY] = 2;
            Koord::i = ii+rX;
            Koord::j = jj+rY;
            fstep=1;
            set_ii(Koord::i);
            set_jj(Koord::j);
            count_steps++;
            return;
        }

       }

}
