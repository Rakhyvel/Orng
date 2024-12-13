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
int64_t _1663_main(void);
int64_t _1661_d(int64_t _1661_x, int64_t _1661_y);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1663_main(void){
    int64_t _1663_t8;
    int64_t _1663_t9;
    function0 _1663_t10;
    int64_t _1663_t7;
    int64_t _1663_$retval;
    _1663_t8 = 200;
    _1663_t9 = 95;
    _1663_t10 = (function0) _1661_d;
    $lines[$line_idx++] = "tests/integration/traits/addr-receiver-none.orng:18:17:\n    my_val_ptr.>d(200, 95)\n               ^";
    _1663_t7 = _1663_t10(_1663_t8, _1663_t9);
    $line_idx--;
    _1663_$retval = _1663_t7;
    return _1663_$retval;
}

int64_t _1661_d(int64_t _1661_x, int64_t _1661_y){
    int64_t _1661_$retval;
    _1661_$retval = $add_int64_t(_1661_x, _1661_y, "tests/integration/traits/addr-receiver-none.orng:10:12:\n        x + y\n          ^");
    return _1661_$retval;
}


int main(void) {
  printf("%ld",_1663_main());
  return 0;
}
