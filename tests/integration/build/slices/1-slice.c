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
int64_t _1231_main(void);
int64_t _1233_first(struct1 _1233_xs);

/* Function definitions */
int64_t _1231_main(void){
    function0 _1231_t0;
    int64_t _1231_t3;
    int64_t _1231_t5;
    struct2 _1231_t4;
    int64_t* _1231_t6;
    int64_t _1231_t7;
    struct1 _1231_t2;
    int64_t _1231_t1;
    int64_t _1231_$retval;
    _1231_t0 = _1233_first;
    _1231_t3 = 0;
    _1231_t5 = 233;
    _1231_t4 = (struct2) {_1231_t5};
    _1231_t6 = ((int64_t*)&_1231_t4 + _1231_t3);
    _1231_t7 = 1;
    _1231_t2 = (struct1) {_1231_t6, _1231_t7};
    $lines[$line_idx++] = "tests/integration/slices/1-slice.orng:3:11:\n    first([](233,))\n         ^";
    _1231_t1 = _1231_t0(_1231_t2);
    $line_idx--;
    _1231_$retval = _1231_t1;
    return _1231_$retval;
}

int64_t _1233_first(struct1 _1233_xs){
    int64_t _1233_t0;
    int64_t _1233_$retval;
    _1233_t0 = 0;
    _1233_$retval = *((int64_t*)_1233_xs._0 + _1233_t0);
    return _1233_$retval;
}

int main(void) {
  printf("%ld",_1231_main());
  return 0;
}
