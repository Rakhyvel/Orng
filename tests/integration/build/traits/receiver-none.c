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

/* Trait vtable type definitions */
/* Function forward definitions */
int64_t _1817_main(void);
int64_t _1815_d(int64_t _1815_x, int64_t _1815_y);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1817_main(void){
    int64_t _1817_t6;
    int64_t _1817_t7;
    function0 _1817_t8;
    int64_t _1817_t5;
    int64_t _1817_$retval;
    _1817_t6 = 200;
    _1817_t7 = 91;
    _1817_t8 = (function0) _1815_d;
    $lines[$line_idx++] = "tests/integration/traits/receiver-none.orng:17:13:\n    my_val.>d(200, 91)\n           ^";
    _1817_t5 = _1817_t8(_1817_t6, _1817_t7);
    $line_idx--;
    _1817_$retval = _1817_t5;
    return _1817_$retval;
}

int64_t _1815_d(int64_t _1815_x, int64_t _1815_y){
    int64_t _1815_$retval;
    _1815_$retval = $add_int64_t(_1815_x, _1815_y, "tests/integration/traits/receiver-none.orng:10:12:\n        x + y\n          ^");
    return _1815_$retval;
}


int main(void) {
  printf("%ld",_1817_main());
  return 0;
}
