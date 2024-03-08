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
int64_t _275_main(void);
int64_t _277_f(int8_t _277_x, int16_t _277_y, int8_t _277_z);


/* Function definitions */
int64_t _275_main(void){
    int8_t _276_x;
    int16_t _276_y;
    int8_t _276_z;
    function0 _275_t3;
    int64_t _275_t4;
    int64_t _275_$retval;
    _276_x = 50;
    _276_y = 200;
    _276_z = 6;
    _275_t3 = (function0) _277_f;
    $lines[$line_idx++] = "tests/integration/comptime/padding-local.orng:6:7:\n    f(x, y, z)\n     ^";
    _275_t4 = _275_t3(_276_x, _276_y, _276_z);
    $line_idx--;
    _275_$retval = _275_t4;
    return _275_$retval;
}

int64_t _277_f(int8_t _277_x, int16_t _277_y, int8_t _277_z){
    int8_t _277_t1;
    uint8_t _277_t3;
    int64_t _277_$retval;
    int16_t _277_t4;
    uint8_t _277_t6;
    int8_t _277_t7;
    uint8_t _277_t9;
    _277_t1 = 50;
    _277_t3 = _277_x==_277_t1;
    if (_277_t3) {
        goto BB281;
    } else {
        goto BB291;
    }
BB281:
    _277_t4 = 200;
    _277_t6 = _277_y==_277_t4;
    if (_277_t6) {
        goto BB284;
    } else {
        goto BB291;
    }
BB291:
    $lines[$line_idx++] = "tests/integration/comptime/padding-local.orng:13:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
BB284:
    _277_t7 = 6;
    _277_t9 = _277_z==_277_t7;
    if (_277_t9) {
        goto BB287;
    } else {
        goto BB291;
    }
BB287:
    _277_$retval = 256;
    return _277_$retval;
}


int main(void) {
  printf("%ld",_275_main());
  return 0;
}
