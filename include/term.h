#ifndef TERM_T
#define TERM_T

void move_to(int x, int y);
void set_raw(); // unbuffered input
void set_cooked(); // buffered input
void clear(); // clear the screen

#endif // ifndef TERM_T