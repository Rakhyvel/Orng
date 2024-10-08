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
int64_t _51_main(void);
int64_t _53_f(struct struct1 _53_x);


/* Function definitions */
int64_t _51_main(void){
    struct struct0 _51_t2;
    struct struct0 _51_t4;
    struct struct0 _51_t6;
    struct struct1 _52_x;
    function2 _51_t8;
    int64_t _51_t9;
    int64_t _51_$retval;
    _51_t2 = (struct struct0) {.tag=0};
    _51_t4 = (struct struct0) {.tag=1};
    _51_t6 = (struct struct0) {.tag=2};
    _52_x = (struct struct1) {_51_t2, _51_t4, _51_t6};
    _51_t8 = (function2) _53_f;
    $lines[$line_idx++] = "tests/integration/arrays/array-sum.orng:6:7:\n    f(x)\n     ^";
    _51_t9 = _51_t8(_52_x);
    $line_idx--;
    _51_$retval = _51_t9;
    return _51_$retval;
}

int64_t _53_f(struct struct1 _53_x){
    int64_t _53_t1;
    int64_t _53_t2;
    uint64_t _53_t7;
    uint64_t _53_t8;
    uint8_t _53_t6;
    int64_t _53_t0;
    int64_t _53_$retval;
    _53_t1 = 1;
    _53_t2 = 3;
    $bounds_check(_53_t1, _53_t2, "tests/integration/arrays/array-sum.orng:9:7:\nfn f(x: [3]My_Type) -> Int {\n     ^");
    _53_t7 = (*((struct struct0*)&_53_x + _53_t1)).tag;
    _53_t8 = 1;
    _53_t6 = _53_t7==_53_t8;
    if (_53_t6) {
        goto BB48;
    } else {
        goto BB52;
    }
BB48:
    _53_t0 = 215;
    goto BB51;
BB52:
    _53_t0 = 3;
    goto BB51;
BB51:
    _53_$retval = _53_t0;
    return _53_$retval;
}


int main(void) {
  printf("%ld",_51_main());
  return 0;
}
