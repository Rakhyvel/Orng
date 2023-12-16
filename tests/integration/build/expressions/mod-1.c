/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _715_main(void);
uint8_t _720_f(int64_t _720_x);

/* Function definitions */
int64_t _715_main(void){
    function0 _715_t1;
    int64_t _715_t3;
    uint8_t _715_t2;
    int64_t _715_t0;
    int64_t _715_$retval;
    _715_t1 = _720_f;
    _715_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mod-1.orng:3:10:\n    if f(4) {\n        ^";
    _715_t2 = _715_t1(_715_t3);
    $line_idx--;
    if (_715_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _715_t0 = 192;
    goto BB4;
BB5:
    _715_t0 = 4;
    goto BB4;
BB4:
    _715_$retval = _715_t0;
    return _715_$retval;
}

uint8_t _720_f(int64_t _720_x){
    uint8_t _720_$retval;
    (void)_720_x;
    _720_$retval = 1;
    return _720_$retval;
}

int main(void) {
  printf("%ld",_715_main());
  return 0;
}
