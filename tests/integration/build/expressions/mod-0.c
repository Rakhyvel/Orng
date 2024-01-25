/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */

/* Struct, union, and function definitions */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _774_main(void);
uint8_t _779_f(int64_t _779_x);


/* Function definitions */
int64_t _774_main(void){
    function0 _774_t1;
    int64_t _774_t3;
    uint8_t _774_t2;
    int64_t _774_t0;
    int64_t _774_$retval;
    _774_t1 = _779_f;
    _774_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mod-0.orng:3:10:\n    if f(4) {\n        ^";
    _774_t2 = _774_t1(_774_t3);
    $line_idx--;
    if (_774_t2) {
        goto BB924;
    } else {
        goto BB928;
    }
BB924:
    _774_t0 = 191;
    goto BB927;
BB928:
    _774_t0 = 4;
    goto BB927;
BB927:
    _774_$retval = _774_t0;
    return _774_$retval;
}

uint8_t _779_f(int64_t _779_x){
    uint8_t _779_$retval;
    (void)_779_x;
    _779_$retval = 1;
    return _779_$retval;
}


int main(void) {
  printf("%ld",_774_main());
  return 0;
}
