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
    int8_t _257_t3;
    uint8_t _257_t5;
    uint8_t _257_t7;
    int16_t _257_t6;
    uint8_t _257_t8;
    uint8_t _257_t2;
    int8_t _257_t9;
    uint8_t _257_t11;
    uint8_t _257_t10;
    uint8_t _257_t1;
    int64_t _257_$retval;
    _257_t3 = 50;
    _257_t5 = _257_x==_257_t3;
    if (_257_t5) {
        goto BB276;
    } else {
        goto BB292;
    }
BB276:
    _257_t6 = 200;
    _257_t8 = _257_y==_257_t6;
    if (_257_t8) {
        goto BB277;
    } else {
        goto BB291;
    }
BB292:
    _257_t2 = 0;
    goto BB290;
BB277:
    _257_t7 = 1;
    goto BB278;
BB291:
    _257_t7 = 0;
    goto BB278;
BB290:
    _257_t1 = 0;
    goto BB288;
BB278:
    _257_t2 = _257_t7;
    goto BB279;
BB288:
    $lines[$line_idx++] = "tests/integration/comptime/padding-local.orng:13:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
BB279:
    if (_257_t2) {
        goto BB280;
    } else {
        goto BB290;
    }
BB280:
    _257_t9 = 6;
    _257_t11 = _257_z==_257_t9;
    if (_257_t11) {
        goto BB281;
    } else {
        goto BB289;
    }
BB281:
    _257_t10 = 1;
    goto BB282;
BB289:
    _257_t10 = 0;
    goto BB282;
BB282:
    _257_t1 = _257_t10;
    goto BB283;
BB283:
    if (_257_t1) {
        goto BB284;
    } else {
        goto BB288;
    }
BB284:
    _257_$retval = 256;
    return _257_$retval;
}

int main(void) {
  printf("%ld",_255_main());
  return 0;
}
