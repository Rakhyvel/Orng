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
int64_t _25_main(void);
int64_t _23_d(int64_t _23_x, int64_t _23_y);

/* Trait vtable implementations */

/* Function definitions */
int64_t _25_main(void){
    int64_t _25_t6;
    int64_t _25_t7;
    function0 _25_t8;
    int64_t _25_t5;
    int64_t _25_$retval;
    _25_t6 = 200;
    _25_t7 = 95;
    _25_t8 = (function0) _23_d;
    $lines[$line_idx++] = "tests/integration/traits/addr-receiver-none.orng:18:17:\n    my_val_ptr.>d(200, 95)\n               ^";
    _25_t5 = _25_t8(_25_t6, _25_t7);
    $line_idx--;
    _25_$retval = _25_t5;
    return _25_$retval;
}

int64_t _23_d(int64_t _23_x, int64_t _23_y){
    int64_t _23_$retval;
    _23_$retval = $add_int64_t(_23_x, _23_y, "tests/integration/traits/addr-receiver-none.orng:10:12:\n        x + y\n          ^");
    return _23_$retval;
}


int main(void) {
  printf("%ld",_25_main());
  return 0;
}
