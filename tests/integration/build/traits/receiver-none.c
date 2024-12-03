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
int64_t _177_main(void);
int64_t _175_d(int64_t _175_x, int64_t _175_y);

/* Trait vtable implementations */

/* Function definitions */
int64_t _177_main(void){
    int64_t _177_t6;
    int64_t _177_t7;
    function0 _177_t8;
    int64_t _177_t5;
    int64_t _177_$retval;
    _177_t6 = 200;
    _177_t7 = 91;
    _177_t8 = (function0) _175_d;
    $lines[$line_idx++] = "tests/integration/traits/receiver-none.orng:17:13:\n    my_val.>d(200, 91)\n           ^";
    _177_t5 = _177_t8(_177_t6, _177_t7);
    $line_idx--;
    _177_$retval = _177_t5;
    return _177_$retval;
}

int64_t _175_d(int64_t _175_x, int64_t _175_y){
    int64_t _175_$retval;
    _175_$retval = $add_int64_t(_175_x, _175_y, "tests/integration/traits/receiver-none.orng:10:12:\n        x + y\n          ^");
    return _175_$retval;
}


int main(void) {
  printf("%ld",_177_main());
  return 0;
}
