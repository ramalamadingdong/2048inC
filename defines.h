const float FPS = 60;
const int SCREEN_W = 432;
const int SCREEN_H = 432;
const int BOUNCER_SIZE = 100;
ALLEGRO_DISPLAY *display = NULL;

ALLEGRO_TIMER *timer = NULL;
int ran = 0;

#include <stdlib.h>   /* rand, srand */
#include <stdio.h>    /* printf */
#include <sys/time.h> /* gettimeofday */

int a[4][4] = {  
   {0, 0, 0, 0} ,   /*  initializers for row indexed by 0 */
   {0, 0, 0, 0} ,   /*  initializers for row indexed by 1 */
   {0, 0, 0, 0} ,   /*  initializers for row indexed by 2 */
   {0, 0, 0, 0}     /*  initializers for row indexed by 3 */
};

enum MYKEYS {
   KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};

int l_c;
int errs;