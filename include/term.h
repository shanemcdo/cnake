#ifndef TERM_T
#define TERM_T

#include"Coord.h"

void move_to(int x, int y);
void set_raw(); // unbuffered input
void set_cooked(); // buffered input
void clear(); // clear the screen
// screen coord -> game coord
//       x, y   ->  2 * x - 1, y
void put_block(Coord pos, const char* color, const char* representation); // print a block in game coordinates

#endif // ifndef TERM_T
