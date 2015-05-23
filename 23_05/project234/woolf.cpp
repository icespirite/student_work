#include "woolf.h"
#include "game.h"
#include "koord.h"
#include <iostream>
#include <conio.h>
#include <time.h>
using namespace std;

// Xод волка
// return 0 - нового волка добавлять не надо
// 1 - надо добавить нового волка
int Woolf::step()
{
        if (ii+1<Game::isize && !fstep)
            if (Game::mas[ii+1][jj] == 2) {
                Game::kill_sheep(ii+1, jj);
                Game::mas[ii][jj] = 0;
                Game::mas[ii+1][jj] = 1;
                Koord::i = ii+1;
                Koord::j = jj;
                fstep=1;
            }
        if (ii-1>=0 && !fstep)
            if (Game::mas[ii-1][jj] == 2) {
                Game::kill_sheep(ii-1, jj);
                Game::mas[ii][jj] = 0;
                Game::mas[ii-1][jj] = 1;
                Koord::i = ii-1;
                Koord::j = jj;
                fstep=1;
            }
        if (jj-1>=0 && !fstep)
            if (Game::mas[ii][jj-1] == 2) {
                Game::kill_sheep(ii, jj-1);
                Game::mas[ii][jj] = 0;
                Game::mas[ii][jj-1] = 1;
                Koord::i = ii;
                Koord::j = jj-1;
                fstep=1;
            }
        if (jj+1<Game::jsize && !fstep)
            if (Game::mas[ii][jj+1] == 2) {
                Game::kill_sheep(ii, jj+1);
                Game::mas[ii][jj] = 0;
                Game::mas[ii][jj+1] = 1;
                Koord::i = ii;
                Koord::j = jj+1;
                fstep=1;
            }

        if (fstep) {
            set_ii(Koord::i);
            set_jj(Koord::j);
            count_steps++;
            return 1;
        }

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
                Game::mas[ii+rX][jj+rY] = 1;
                Koord::i = ii+rX;
                Koord::j = jj+rY;
                fstep=1;
                set_ii(Koord::i);
                set_jj(Koord::j);
                count_steps++;
                return 0;
            }

        }

        return 0;

}
