/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;

/* Struct, union, and function definitions */
struct struct1 {
    int64_t _0;
    int64_t _1;
};

typedef int64_t(*function0)(int64_t, int64_t);

/* Function forward definitions */
int64_t _993_main(void);
int64_t _995_div(int64_t _995_x, int64_t _995_y);


/* Function definitions */
int64_t _993_main(void){
    function0 _993_t0;
    int64_t _993_t2;
    int64_t _993_t3;
    int64_t _993_t1;
    int64_t _993_$retval;
    _993_t0 = (function0) _995_div;
    _993_t2 = 510;
    _993_t3 = 10;
    $lines[$line_idx++] = "tests/integration/functions/named-arg.orng:3:9:\n    div(.x = 510, .y = 10)\n       ^";
    _993_t1 = _993_t0(_993_t2, _993_t3);
    $line_idx--;
    _993_$retval = _993_t1;
    return _993_$retval;
}

int64_t _995_div(int64_t _995_x, int64_t _995_y){
    int64_t _995_$retval;
    _995_$retval = $div_int64_t(_995_x, _995_y, "tests/integration/functions/named-arg.orng:6:35:\nfn div(x: Int, y: Int) -> Int {x / y}\n                                 ^");
    return _995_$retval;
}


int main(void) {
  printf("%ld",_993_main());
  return 0;
}
