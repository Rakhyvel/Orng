/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
        int8_t _0;
        int16_t _1;
        int8_t _2;
} struct1;

typedef int64_t(*function0)(int8_t, int16_t, int8_t);

/* Function forward definitions */
int64_t _255_main(void);
int64_t _257_f(int8_t _257_x,int16_t _257_y,int8_t _257_z);

/* Function definitions */
int64_t _255_main(void){
    int8_t _256_x;
    int16_t _256_y;
    int8_t _256_z;
    function0 _255_t3;
    int64_t _255_t4;
    int64_t _255_$retval;
    _256_x = 50;
    _256_y = 200;
    _256_z = 6;
    _255_t3 = _257_f;
    $lines[$line_idx++] = "tests/integration/comptime/padding-local.orng:6:7:\n    f(x, y, z)\n     ^";
    _255_t4 = _255_t3(_256_x, _256_y, _256_z);
    $line_idx--;
    _255_$retval = _255_t4;
    return _255_$retval;
}

int64_t _257_f(int8_t _257_x,int16_t _257_y,int8_t _257_z){
    int8_t _257_t1;
    uint8_t _257_t3;
    int64_t _257_$retval;
    int16_t _257_t4;
    uint8_t _257_t6;
    int8_t _257_t7;
    uint8_t _257_t9;
    _257_t1 = 50;
    _257_t3 = _257_x==_257_t1;
    if (_257_t3) {
        goto BB274;
    } else {
        goto BB284;
    }
BB274:
    _257_t4 = 200;
    _257_t6 = _257_y==_257_t4;
    if (_257_t6) {
        goto BB277;
    } else {
        goto BB284;
    }
BB284:
    $lines[$line_idx++] = "tests/integration/comptime/padding-local.orng:13:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
BB277:
    _257_t7 = 6;
    _257_t9 = _257_z==_257_t7;
    if (_257_t9) {
        goto BB280;
    } else {
        goto BB284;
    }
BB280:
    _257_$retval = 256;
    return _257_$retval;
}

int main(void) {
  printf("%ld",_255_main());
  return 0;
}
