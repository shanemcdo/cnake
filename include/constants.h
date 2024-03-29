#ifndef CONSTANTS_H
#define CONSTANTS_H

#define BOARD_SIZE_MIN 10
#define TAIL_INC 3
#define SLEEP_INTERVAL 100000 // 0.1 seconds

// piece representations
#define R_EMPTY "  "
#define R_HEAD "\033[42m  "
#define R_TAIL "\033[102m\033[36mXX"
#define R_FRUIT "\033[31m▝▘"
#define RESET "\033[0;0m"

#define PAUSE_MENU_TEXT "PAUSED"
#define PAUSE_MENU_EMPTY "      "

#endif // ifndef CONSTANTS_H

