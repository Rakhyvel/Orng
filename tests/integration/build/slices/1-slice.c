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
int64_t _1266_main(void);
int64_t _1268_first(struct1 _1268_xs);

/* Function definitions */
int64_t _1266_main(void){
    function0 _1266_t0;
    int64_t _1266_t4;
    struct2 _1266_t3;
    int64_t _1266_t5;
    int64_t _1266_t6;
    int64_t* _1266_t7;
    int64_t _1266_t8;
    struct1 _1266_t2;
    int64_t _1266_t1;
    int64_t _1266_$retval;
    _1266_t0 = _1268_first;
    _1266_t4 = 233;
    _1266_t3 = (struct2) {_1266_t4};
    _1266_t5 = 0;
    _1266_t6 = 1;
    $bounds_check(_1266_t5, _1266_t6, "tests/integration/slices/1-slice.orng:3:18:\n    first([](233,))\n                ^");
    _1266_t7 = ((int64_t*)&_1266_t3 + _1266_t5);
    _1266_t8 = 1;
    _1266_t2 = (struct1) {_1266_t7, _1266_t8};
    $lines[$line_idx++] = "tests/integration/slices/1-slice.orng:3:11:\n    first([](233,))\n         ^";
    _1266_t1 = _1266_t0(_1266_t2);
    $line_idx--;
    _1266_$retval = _1266_t1;
    return _1266_$retval;
}

int64_t _1268_first(struct1 _1268_xs){
    int64_t _1268_t0;
    int64_t _1268_$retval;
    _1268_t0 = 0;
    $bounds_check(_1268_t0, _1268_xs._1, "tests/integration/slices/1-slice.orng:6:3:\nfn first(xs: []Int) -> Int {\n ^");
    _1268_$retval = *((int64_t*)_1268_xs._0 + _1268_t0);
    return _1268_$retval;
}

int main(void) {
  printf("%ld",_1266_main());
  return 0;
}
