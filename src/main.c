#include<stdio.h>
#include"snake.h"
#include"term.h"

int main(){
    set_raw(); // unbuffering io
    start();
    set_cooked(); // buffering io
    return 0;
}
