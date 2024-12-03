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
int64_t _29_main(void);
int64_t _27_d(int64_t _27_x, int64_t _27_y);

/* Trait vtable implementations */

/* Function definitions */
int64_t _29_main(void){
    int64_t _29_t8;
    int64_t _29_t9;
    function0 _29_t10;
    int64_t _29_t7;
    int64_t _29_$retval;
    _29_t8 = 200;
    _29_t9 = 95;
    _29_t10 = (function0) _27_d;
    $lines[$line_idx++] = "tests/integration/traits/addr-receiver-none.orng:18:17:\n    my_val_ptr.>d(200, 95)\n               ^";
    _29_t7 = _29_t10(_29_t8, _29_t9);
    $line_idx--;
    _29_$retval = _29_t7;
    return _29_$retval;
}

int64_t _27_d(int64_t _27_x, int64_t _27_y){
    int64_t _27_$retval;
    _27_$retval = $add_int64_t(_27_x, _27_y, "tests/integration/traits/addr-receiver-none.orng:10:12:\n        x + y\n          ^");
    return _27_$retval;
}


int main(void) {
  printf("%ld",_29_main());
  return 0;
}
