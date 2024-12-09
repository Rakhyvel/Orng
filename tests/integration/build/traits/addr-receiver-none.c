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
int64_t _1646_main(void);
int64_t _1644_d(int64_t _1644_x, int64_t _1644_y);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1646_main(void){
    int64_t _1646_t8;
    int64_t _1646_t9;
    function0 _1646_t10;
    int64_t _1646_t7;
    int64_t _1646_$retval;
    _1646_t8 = 200;
    _1646_t9 = 95;
    _1646_t10 = (function0) _1644_d;
    $lines[$line_idx++] = "tests/integration/traits/addr-receiver-none.orng:18:17:\n    my_val_ptr.>d(200, 95)\n               ^";
    _1646_t7 = _1646_t10(_1646_t8, _1646_t9);
    $line_idx--;
    _1646_$retval = _1646_t7;
    return _1646_$retval;
}

int64_t _1644_d(int64_t _1644_x, int64_t _1644_y){
    int64_t _1644_$retval;
    _1644_$retval = $add_int64_t(_1644_x, _1644_y, "tests/integration/traits/addr-receiver-none.orng:10:12:\n        x + y\n          ^");
    return _1644_$retval;
}


int main(void) {
  printf("%ld",_1646_main());
  return 0;
}
