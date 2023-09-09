/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* Debug information */
static const char* $lines[1024];
static uint16_t $line_idx = 0;

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
    int64_t _2;
} struct0;
typedef struct {
    int64_t _0;
    int64_t _1;
} struct1;

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
    int64_t _2_t1;
    int64_t _2_t2;
    int64_t _2_t3;
    struct0 _3_x;
    int64_t _2_t5;
    int64_t _2_t6;
    int64_t _2_t11;
    int64_t _2_t12;
    struct1 _2_t4;
    int64_t _2_t23;
    int64_t _2_t24;
    int64_t _2_t35;
    int64_t _2_t36;
    int64_t _2_t43;
    int64_t _2_t44;
    int64_t _2_t49;
    int64_t _2_t50;
    uint8_t _2_t42;
    int64_t _2_t41;
    int64_t _2_$retval;
BB0:
    _2_t1 = 0;
    _2_t2 = 1;
    _2_t3 = 2;
    _3_x = (struct0) {_2_t1, _2_t2, _2_t3};
    _2_t5 = 1;
    _2_t6 = *(((int64_t*)(&_3_x))+_2_t5);
    _2_t11 = 0;
    _2_t12 = *(((int64_t*)(&_3_x))+_2_t11);
    _2_t4 = (struct1) {_2_t6, _2_t12};
    _2_t23 = (&_2_t4)->_0;
    _2_t24 = 0;
    *(((int64_t*)(&_3_x))+_2_t24) = _2_t23;
    _2_t35 = (&_2_t4)->_1;
    _2_t36 = 1;
    *(((int64_t*)(&_3_x))+_2_t36) = _2_t35;
    _2_t43 = 0;
    _2_t44 = *(((int64_t*)(&_3_x))+_2_t43);
    _2_t49 = 1;
    _2_t50 = *(((int64_t*)(&_3_x))+_2_t49);
    _2_t42 = _2_t44 > _2_t50;
    if (_2_t42) {
        goto BB33;
    } else {
        goto BB41;
    }
BB41:
    $lines[$line_idx++] = "tests/integration/pattern/assign-index-product.orng:8:20:\n        unreachable\n                  ^";
    fprintf(stderr, "panic: reached unreachable code\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
    goto BB38;
BB38:
    _2_$retval = _2_t41;
    return _2_$retval;
BB33:
    _2_t41 = 162;
    goto BB38;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

