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
int64_t _193_main(void);
int64_t _195_f(int8_t _195_x, int16_t _195_y, int8_t _195_z);


/* Function definitions */
int64_t _193_main(void){
    int8_t _194_x;
    int16_t _194_y;
    int8_t _194_z;
    function0 _193_t6;
    int64_t _193_t7;
    int64_t _193_$retval;
    _194_x = 50;
    _194_y = 200;
    _194_z = 6;
    _193_t6 = (function0) _195_f;
    $lines[$line_idx++] = "tests/integration/comptime/padding-local.orng:6:7:\n    f(x, y, z)\n     ^";
    _193_t7 = _193_t6(_194_x, _194_y, _194_z);
    $line_idx--;
    _193_$retval = _193_t7;
    return _193_$retval;
}

int64_t _195_f(int8_t _195_x, int16_t _195_y, int8_t _195_z){
    int8_t _195_t1;
    uint8_t _195_t3;
    int64_t _195_$retval;
    int16_t _195_t4;
    uint8_t _195_t6;
    int8_t _195_t7;
    uint8_t _195_t9;
    _195_t1 = 50;
    _195_t3 = _195_x==_195_t1;
    if (_195_t3) {
        goto BB194;
    } else {
        goto BB204;
    }
BB194:
    _195_t4 = 200;
    _195_t6 = _195_y==_195_t4;
    if (_195_t6) {
        goto BB197;
    } else {
        goto BB204;
    }
BB204:
    $lines[$line_idx++] = "tests/integration/comptime/padding-local.orng:13:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
BB197:
    _195_t7 = 6;
    _195_t9 = _195_z==_195_t7;
    if (_195_t9) {
        goto BB200;
    } else {
        goto BB204;
    }
BB200:
    _195_$retval = 256;
    return _195_$retval;
}


int main(void) {
  printf("%ld",_193_main());
  return 0;
}
