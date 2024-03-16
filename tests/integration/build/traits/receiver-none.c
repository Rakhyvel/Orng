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
int64_t _136_main(void);
int64_t _134_d(int64_t _134_x, int64_t _134_y);

/* Trait vtable implementations */

/* Function definitions */
int64_t _136_main(void){
    int64_t _136_t6;
    int64_t _136_t7;
    function0 _136_t8;
    int64_t _136_t5;
    int64_t _136_$retval;
    _136_t6 = 200;
    _136_t7 = 91;
    _136_t8 = (function0) _134_d;
    $lines[$line_idx++] = "tests/integration/traits/receiver-none.orng:17:13:\n    my_val.>d(200, 91)\n           ^";
    _136_t5 = _136_t8(_136_t6, _136_t7);
    $line_idx--;
    _136_$retval = _136_t5;
    return _136_$retval;
}

int64_t _134_d(int64_t _134_x, int64_t _134_y){
    int64_t _134_$retval;
    _134_$retval = $add_int64_t(_134_x, _134_y, "tests/integration/traits/receiver-none.orng:10:12:\n        x + y\n          ^");
    return _134_$retval;
}


int main(void) {
  printf("%ld",_136_main());
  return 0;
}
