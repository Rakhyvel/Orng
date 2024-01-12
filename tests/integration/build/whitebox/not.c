/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */

/* Typedefs */
typedef int64_t(*function0)(uint8_t);

/* Function forward definitions */
int64_t _1639_main(void);
int64_t _1641_f(uint8_t _1641_b);

/* Function definitions */
int64_t _1639_main(void){
    int64_t _1640_x;
    int64_t* _1640_y;
    function0 _1639_t2;
    int64_t _1639_t4;
    uint8_t _1639_t6;
    uint8_t _1639_t5;
    uint8_t _1639_t7;
    int64_t _1639_t3;
    int64_t _1639_$retval;
    _1640_x = 0;
    _1640_y = &_1640_x;
    _1639_t2 = _1641_f;
    _1639_t4 = 1;
    _1639_t6 = *_1640_y==_1639_t4;
    if (_1639_t6) {
        goto BB1941;
    } else {
        goto BB1944;
    }
BB1941:
    _1639_t5 = 1;
    goto BB1942;
BB1944:
    _1639_t5 = 0;
    goto BB1942;
BB1942:
    _1639_t7 = !_1639_t5;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _1639_t3 = _1639_t2(_1639_t7);
    $line_idx--;
    _1639_$retval = _1639_t3;
    return _1639_$retval;
}

int64_t _1641_f(uint8_t _1641_b){
    uint8_t _1641_t0;
    uint8_t _1641_t1;
    int64_t _1641_t2;
    int64_t _1641_$retval;
    _1641_t0 = !_1641_b;
    _1641_b = _1641_t0;
    _1641_t1 = !_1641_t0;
    _1641_b = _1641_t1;
    if (_1641_t0) {
        goto BB1938;
    } else {
        goto BB1934;
    }
BB1938:
    _1641_t2 = 10;
    goto BB1937;
BB1934:
    _1641_t2 = 31;
    goto BB1937;
BB1937:
    _1641_$retval = _1641_t2;
    return _1641_$retval;
}

int main(void) {
  printf("%ld",_1639_main());
  return 0;
}
