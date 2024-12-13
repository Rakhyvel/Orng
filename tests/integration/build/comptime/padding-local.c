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
    int8_t _0;
    int16_t _1;
    int8_t _2;
};

typedef int64_t(*function0)(int8_t, int16_t, int8_t);

/* Function forward definitions */
int64_t _284_main(void);
int64_t _286_f(int8_t _286_x, int16_t _286_y, int8_t _286_z);


/* Function definitions */
int64_t _284_main(void){
    int8_t _285_x;
    int16_t _285_y;
    int8_t _285_z;
    function0 _284_t6;
    int64_t _284_t7;
    int64_t _284_$retval;
    _285_x = 50;
    _285_y = 200;
    _285_z = 6;
    _284_t6 = (function0) _286_f;
    $lines[$line_idx++] = "tests/integration/comptime/padding-local.orng:6:7:\n    f(x, y, z)\n     ^";
    _284_t7 = _284_t6(_285_x, _285_y, _285_z);
    $line_idx--;
    _284_$retval = _284_t7;
    return _284_$retval;
}

int64_t _286_f(int8_t _286_x, int16_t _286_y, int8_t _286_z){
    int8_t _286_t1;
    uint8_t _286_t3;
    int64_t _286_$retval;
    int16_t _286_t4;
    uint8_t _286_t6;
    int8_t _286_t7;
    uint8_t _286_t9;
    _286_t1 = 50;
    _286_t3 = _286_x==_286_t1;
    if (_286_t3) {
        goto BB281;
    } else {
        goto BB291;
    }
BB281:
    _286_t4 = 200;
    _286_t6 = _286_y==_286_t4;
    if (_286_t6) {
        goto BB284;
    } else {
        goto BB291;
    }
BB291:
    $lines[$line_idx++] = "tests/integration/comptime/padding-local.orng:13:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
BB284:
    _286_t7 = 6;
    _286_t9 = _286_z==_286_t7;
    if (_286_t9) {
        goto BB287;
    } else {
        goto BB291;
    }
BB287:
    _286_$retval = 256;
    return _286_$retval;
}


int main(void) {
  printf("%ld",_284_main());
  return 0;
}
