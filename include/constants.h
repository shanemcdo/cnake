#ifndef CONSTANTS_H
#define CONSTANTS_H

#define BOARD_SIZE 40

// piece representations
#define R_EMPTY "  "
#define R_HEAD "\033[42m  "
#define R_TAIL "\033[102m\033[36mXX"
#define R_FRUIT "\033[31m▝▘"
#define RESET "\033[0;0m"

// box surround pieces
#define R_DR_CORNER "╔"
#define R_DL_CORNER "╗"
#define R_UR_CORNER "╚"
#define R_UL_CORNER "╝"
#define R_VERT_LINE "║"
#define R_HORIZ_LINE "═"

#endif // ifndef CONSTANTS_H

