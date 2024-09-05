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
int64_t _1600_main(void);
int64_t _1598_d(int64_t _1598_x, int64_t _1598_y);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1600_main(void){
    int64_t _1600_t8;
    int64_t _1600_t9;
    function0 _1600_t10;
    int64_t _1600_t7;
    int64_t _1600_$retval;
    _1600_t8 = 200;
    _1600_t9 = 95;
    _1600_t10 = (function0) _1598_d;
    $lines[$line_idx++] = "tests/integration/traits/addr-receiver-none.orng:18:17:\n    my_val_ptr.>d(200, 95)\n               ^";
    _1600_t7 = _1600_t10(_1600_t8, _1600_t9);
    $line_idx--;
    _1600_$retval = _1600_t7;
    return _1600_$retval;
}

int64_t _1598_d(int64_t _1598_x, int64_t _1598_y){
    int64_t _1598_$retval;
    _1598_$retval = $add_int64_t(_1598_x, _1598_y, "tests/integration/traits/addr-receiver-none.orng:10:12:\n        x + y\n          ^");
    return _1598_$retval;
}


int main(void) {
  printf("%ld",_1600_main());
  return 0;
}
