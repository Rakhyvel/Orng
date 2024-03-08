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
int64_t _100_main(void);
int64_t _98_d(int64_t _98_x, int64_t _98_y);

/* Trait vtable implementations */

/* Function definitions */
int64_t _100_main(void){
    int64_t _100_t5;
    int64_t _100_t6;
    function0 _100_t7;
    int64_t _100_t4;
    int64_t _100_$retval;
    _100_t5 = 200;
    _100_t6 = 91;
    _100_t7 = (function0) _98_d;
    $lines[$line_idx++] = "tests/integration/traits/receiver-none.orng:17:13:\n    my_val.>d(200, 91)\n           ^";
    _100_t4 = _100_t7(_100_t5, _100_t6);
    $line_idx--;
    _100_$retval = _100_t4;
    return _100_$retval;
}

int64_t _98_d(int64_t _98_x, int64_t _98_y){
    int64_t _98_$retval;
    _98_$retval = $add_int64_t(_98_x, _98_y, "tests/integration/traits/receiver-none.orng:10:12:\n        x + y\n          ^");
    return _98_$retval;
}


int main(void) {
  printf("%ld",_100_main());
  return 0;
}
