/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1691899681449729182
#define ORNG_1691899681449729182

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include<stdlib.h>

/* Debug information */
static const char* $lines[1024];
static uint16_t $line_idx = 0;

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
    int64_t _2;
    int64_t _3;
} struct0;
typedef struct {
    int64_t* _0;
    int64_t _1;
} struct1;

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();
int64_t _4_f(struct1 _4_x);

/* Function definitions */
int64_t _2_main() {
    int64_t _2_t1;
    int64_t _2_t2;
    int64_t _2_t3;
    int64_t _2_t4;
    struct0 _3_x;
    int64_t _2_t6;
    int64_t* _2_t12;
    int64_t _2_t13;
    struct1 _3_y;
    int64_t _2_t14;
    int64_t _2_$retval;
BB0:
    _2_t1 = 1;
    _2_t2 = 2;
    _2_t3 = 3;
    _2_t4 = 4;
    _3_x = (struct0) {_2_t1, _2_t2, _2_t3, _2_t4};
    _2_t6 = 0;
    _2_t12 = (((int64_t*)(&_3_x))+_2_t6);
    _2_t13 = 4;
    _3_y = (struct1) {_2_t12, _2_t13};
    $lines[$line_idx++] = "tests/integration/slices/fn-pass.orng:5:7:\n    f(y)\n     ^";
    _2_t14 = _4_f(_3_y);
    $line_idx--;
    _2_$retval = _2_t14;
    return _2_$retval;
}

int64_t _4_f(struct1 _4_x) {
    int64_t _4_t0;
    int64_t _4_t4;
    uint8_t _4_t5;
    int64_t _4_t1;
    int64_t _4_t6;
    int64_t _4_$retval;
BB0:
    _4_t0 = 1;
    _4_t4 = (&_4_x)->_1;
    _4_t5 = _4_t0 >= _4_t4;
    if (_4_t5) {
        goto BB3;
    } else {
        goto BB4;
    }
BB4:
    _4_t1 = *(((int64_t*)((&_4_x)->_0))+_4_t0);
    _4_t6 = 80;
    _4_$retval = _4_t1 + _4_t6;
    return _4_$retval;
BB3:
    $lines[$line_idx++] = "tests/integration/slices/fn-pass.orng:7:24:\nfn f(x: []Int)->Int {x[1] + 80}\n                      ^";
    fprintf(stderr, "panic: index is greater than length\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
    goto BB4;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
