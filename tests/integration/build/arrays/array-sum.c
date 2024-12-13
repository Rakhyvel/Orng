/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;
struct struct1;

/* Struct, union, and function definitions */
struct struct0 {
    uint64_t tag;
};

struct struct1 {
    struct struct0 _0;
    struct struct0 _1;
    struct struct0 _2;
};

typedef int64_t(*function2)(struct struct1);

/* Function forward definitions */
int64_t _60_main(void);
int64_t _62_f(struct struct1 _62_x);


/* Function definitions */
int64_t _60_main(void){
    struct struct0 _60_t2;
    struct struct0 _60_t4;
    struct struct0 _60_t6;
    struct struct1 _61_x;
    function2 _60_t8;
    int64_t _60_t9;
    int64_t _60_$retval;
    _60_t2 = (struct struct0) {.tag=0};
    _60_t4 = (struct struct0) {.tag=1};
    _60_t6 = (struct struct0) {.tag=2};
    _61_x = (struct struct1) {_60_t2, _60_t4, _60_t6};
    _60_t8 = (function2) _62_f;
    $lines[$line_idx++] = "tests/integration/arrays/array-sum.orng:6:7:\n    f(x)\n     ^";
    _60_t9 = _60_t8(_61_x);
    $line_idx--;
    _60_$retval = _60_t9;
    return _60_$retval;
}

int64_t _62_f(struct struct1 _62_x){
    int64_t _62_t1;
    int64_t _62_t2;
    uint64_t _62_t7;
    uint64_t _62_t8;
    uint8_t _62_t6;
    int64_t _62_t0;
    int64_t _62_$retval;
    _62_t1 = 1;
    _62_t2 = 3;
    $bounds_check(_62_t1, _62_t2, "tests/integration/arrays/array-sum.orng:9:7:\nfn f(x: [3]My_Type) -> Int {\n     ^");
    _62_t7 = (*((struct struct0*)&_62_x + _62_t1)).tag;
    _62_t8 = 1;
    _62_t6 = _62_t7==_62_t8;
    if (_62_t6) {
        goto BB55;
    } else {
        goto BB59;
    }
BB55:
    _62_t0 = 215;
    goto BB58;
BB59:
    _62_t0 = 3;
    goto BB58;
BB58:
    _62_$retval = _62_t0;
    return _62_$retval;
}


int main(void) {
  printf("%ld",_60_main());
  return 0;
}
