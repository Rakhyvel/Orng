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
int64_t _1781_main(void);
int64_t _1779_d(int64_t _1779_x, int64_t _1779_y);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1781_main(void){
    int64_t _1781_t6;
    int64_t _1781_t7;
    function0 _1781_t8;
    int64_t _1781_t5;
    int64_t _1781_$retval;
    _1781_t6 = 200;
    _1781_t7 = 91;
    _1781_t8 = (function0) _1779_d;
    $lines[$line_idx++] = "tests/integration/traits/receiver-none.orng:17:13:\n    my_val.>d(200, 91)\n           ^";
    _1781_t5 = _1781_t8(_1781_t6, _1781_t7);
    $line_idx--;
    _1781_$retval = _1781_t5;
    return _1781_$retval;
}

int64_t _1779_d(int64_t _1779_x, int64_t _1779_y){
    int64_t _1779_$retval;
    _1779_$retval = $add_int64_t(_1779_x, _1779_y, "tests/integration/traits/receiver-none.orng:10:12:\n        x + y\n          ^");
    return _1779_$retval;
}


int main(void) {
  printf("%ld",_1781_main());
  return 0;
}
