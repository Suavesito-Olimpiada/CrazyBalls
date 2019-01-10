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

#include <ncurses.h>

#include "nbnli.h"  // non-blocking, non-line-oriented input

#define DELAY 20000

int main(int argc, char const * argv [])
{
    bool tstt = true;
    char dir='\0';
    int x=0, y=0;
    int max_x=0, max_y=0;

    initscr ();
    noecho ();
    nocbreak ();
    curs_set (FALSE);

    while (true && dir != 'q') {
        if (getchnb (&dir) > 0) {
            switch (dir) {
                case 'w':
                    y+=max_y-1;
                    break;
                case 's':
                    ++y;
                    break;
                case 'd':
                    x+=2;
                    break;
                case 'a':
                    x+=max_x-2;
                    break;
                default:
                    break;
            }
            x = x%max_x; // Advance the ball to the right
            y = y%max_y; // Advance the ball to the right
        }

        erase (); // Clear the screen of all
        getmaxyx (stdscr, max_y, max_x);

        mvprintw (y, x, "o"); // Print our "ball" at the current xy position
        wnoutrefresh (stdscr);
        doupdate ();

        usleep (DELAY); // Shorter delay between movements
    }

    endwin (); // Restore normal terminal behavior

    return 0;
}
