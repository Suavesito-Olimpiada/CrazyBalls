#include "nbnli.h"

int getchnb (char *ch){
    fcntl (STDIN_FILENO, F_SETFL, fcntl (0, F_GETFL) | O_NONBLOCK);
    struct termios oldattr, newattr;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    int st = read (STDIN_FILENO, ch, 4);
    fcntl (STDIN_FILENO, F_SETFL, fcntl (0, F_GETFL) | ~O_NONBLOCK);
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return st;
}
