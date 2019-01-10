/*  CrazyBalls Game - Introducción a la Computación
 *  autor       : José Joaquín Zubieta Rico
 *  date        : 12-05-2018
 *  subject     : Is it for some subject?
 *  description : Juego en terminal que trata de evadir pelotas que se mueven de forma aleatoria.
 #  license     : GPL v3 (https://www.gnu.org/licenses/gpl-3.0.en.html)
 */


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <ncurses.h>

#include "game.h"
#include "nbnli.h"  // non-blocking, non-line-oriented input
#include "particle.h"
#include "screen.h"

#define DELAY 20000

int main(int argc, char const * argv [])
{
    bool gstt = false;
    char dir[4]="\0\0\0", *aux;
    int x=0, y=0;
    int max_x=40, max_y=40;
    int _xmax=0, _ymax=0;
    int turn=0;
    unsigned speed=10;
    int a=0, b=0;

    initscr ();
    noecho ();
    nocbreak ();
    curs_set (FALSE);

    init_game (max_y, max_x);

    while (true && dir[0] != 'q' && !gstt) {
        x = stdgame.ply.x;
        y = stdgame.ply.y;

        a = getchnb (dir);
        if (a > 0) {
            if (a == 1) {
                switch (dir[0]) {
                    case 'w':
                        y+=max_y-1;
                        break;
                    case 's':
                        ++y;
                        break;
                    case 'd':
                        x+=1;
                        break;
                    case 'a':
                        x+=max_x-1;
                        break;
                    case '-':
                        ++speed;
                        break;
                    case '+':
                        if (speed>1) --speed;
                        break;
                    case 'n':
                        if (stdgame.level < 10) next_level ();
                        break;
                    default:
                        break;
                }
            }
            if (a > 1) {
                aux = (char*)(&b);
                int i = 0;
                for (i=0; i<a; ++i)
                    aux [i] = dir [i];
                for (i=a; i<4; ++i)
                    aux [i] = 0;
            }
            if (a == 3) {
                switch (b) {
                    case 4283163:   // up
                        y+=max_y-1;
                        break;
                    case 4348699:   // down
                        ++y;
                        break;
                    case 4414235:   // right
                        x+=1;
                        break;
                    case 4479771:   // left
                        x+=max_x-1;
                        break;
                    default:
                        break;
                }
            }
            x = x%max_x; // Advance the ball to the right
            y = y%max_y; // Advance the ball to the right
            update_particle_position (&(stdgame.ply), y, x);
        }

        erase (); // Clear the screen of all
        getmaxyx (stdscr, _ymax, _xmax);
        turn = (turn+1)%speed;

        clear_screen (stdgame.scr);
        if (!turn) next ();
        update_screen_player (stdgame.scr, stdgame.ply);
        update_screen_particles (stdgame.scr, stdgame.pls, level_settings [stdgame.level]);
        print_screen (stdgame.scr);
        gstt = collision_check ();

        mvprintw (0, 0, "SP:%u\tLV:%d\tKY:%d", speed, stdgame.level, b);
        wnoutrefresh (stdscr);
        doupdate ();

        usleep (DELAY); // Shorter delay between movements
    }

    del_game ();

    erase ();
    getmaxyx (stdscr, _ymax, _xmax);
    mvprintw (((_ymax>max_y)?max_y:_ymax)/2, ((_xmax>max_x)?max_x:_xmax)/2, "Perdiste!"); // Print our "ball" at the current xy position
    refresh();

    sleep (1);

    endwin (); // Restore normal terminal behavior

    return 0;
}
