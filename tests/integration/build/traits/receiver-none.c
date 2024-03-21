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
int64_t _1661_main(void);
int64_t _1659_d(int64_t _1659_x, int64_t _1659_y);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1661_main(void){
    int64_t _1661_t6;
    int64_t _1661_t7;
    function0 _1661_t8;
    int64_t _1661_t5;
    int64_t _1661_$retval;
    _1661_t6 = 200;
    _1661_t7 = 91;
    _1661_t8 = (function0) _1659_d;
    $lines[$line_idx++] = "tests/integration/traits/receiver-none.orng:17:13:\n    my_val.>d(200, 91)\n           ^";
    _1661_t5 = _1661_t8(_1661_t6, _1661_t7);
    $line_idx--;
    _1661_$retval = _1661_t5;
    return _1661_$retval;
}

int64_t _1659_d(int64_t _1659_x, int64_t _1659_y){
    int64_t _1659_$retval;
    _1659_$retval = $add_int64_t(_1659_x, _1659_y, "tests/integration/traits/receiver-none.orng:10:12:\n        x + y\n          ^");
    return _1659_$retval;
}


int main(void) {
  printf("%ld",_1661_main());
  return 0;
}
