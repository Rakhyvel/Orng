/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct1;

/* Typedefs */
struct struct1 {
    int8_t _0;
    int16_t _1;
    int8_t _2;
};

typedef int64_t(*function0)(int8_t, int16_t, int8_t);

/* Function forward definitions */
int64_t _256_main(void);
int64_t _258_f(int8_t _258_x, int16_t _258_y, int8_t _258_z);

/* Function definitions */
int64_t _256_main(void){
    int8_t _257_x;
    int16_t _257_y;
    int8_t _257_z;
    function0 _256_t3;
    int64_t _256_t4;
    int64_t _256_$retval;
    _257_x = 50;
    _257_y = 200;
    _257_z = 6;
    _256_t3 = _258_f;
    $lines[$line_idx++] = "tests/integration/comptime/padding-local.orng:6:7:\n    f(x, y, z)\n     ^";
    _256_t4 = _256_t3(_257_x, _257_y, _257_z);
    $line_idx--;
    _256_$retval = _256_t4;
    return _256_$retval;
}

int64_t _258_f(int8_t _258_x, int16_t _258_y, int8_t _258_z){
    int8_t _258_t1;
    uint8_t _258_t3;
    int64_t _258_$retval;
    int16_t _258_t4;
    uint8_t _258_t6;
    int8_t _258_t7;
    uint8_t _258_t9;
    _258_t1 = 50;
    _258_t3 = _258_x==_258_t1;
    if (_258_t3) {
        goto BB274;
    } else {
        goto BB284;
    }
BB274:
    _258_t4 = 200;
    _258_t6 = _258_y==_258_t4;
    if (_258_t6) {
        goto BB277;
    } else {
        goto BB284;
    }
BB284:
    $lines[$line_idx++] = "tests/integration/comptime/padding-local.orng:13:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
BB277:
    _258_t7 = 6;
    _258_t9 = _258_z==_258_t7;
    if (_258_t9) {
        goto BB280;
    } else {
        goto BB284;
    }
BB280:
    _258_$retval = 256;
    return _258_$retval;
}

int main(void) {
  printf("%ld",_256_main());
  return 0;
}
