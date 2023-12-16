/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t* _0;
    int64_t _1;
} struct1;

typedef int64_t(*function0)(struct1);

typedef struct {
    int64_t _0;
} struct2;

/* Function forward definitions */
int64_t _1302_main(void);
int64_t _1304_first(struct1 _1304_xs);

/* Function definitions */
int64_t _1302_main(void){
    function0 _1302_t0;
    int64_t _1302_t3;
    int64_t _1302_t5;
    struct2 _1302_t4;
    int64_t* _1302_t6;
    int64_t _1302_t7;
    struct1 _1302_t2;
    int64_t _1302_t1;
    int64_t _1302_$retval;
    _1302_t0 = _1304_first;
    _1302_t3 = 0;
    _1302_t5 = 233;
    _1302_t4 = (struct2) {_1302_t5};
    _1302_t6 = ((int64_t*)&_1302_t4 + _1302_t3);
    _1302_t7 = 1;
    _1302_t2 = (struct1) {_1302_t6, _1302_t7};
    $lines[$line_idx++] = "tests/integration/slices/1-slice.orng:3:11:\n    first([](233,))\n         ^";
    _1302_t1 = _1302_t0(_1302_t2);
    $line_idx--;
    _1302_$retval = _1302_t1;
    return _1302_$retval;
}

int64_t _1304_first(struct1 _1304_xs){
    int64_t _1304_t0;
    int64_t _1304_$retval;
    _1304_t0 = 0;
    _1304_$retval = *((int64_t*)_1304_xs._0 + _1304_t0);
    return _1304_$retval;
}

int main(void) {
  printf("%ld",_1302_main());
  return 0;
}
