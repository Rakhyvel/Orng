/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    uint64_t tag;
} struct0;

typedef struct {
        struct0 _0;
        struct0 _1;
        struct0 _2;
} struct1;

typedef int64_t(*function2)(struct1);

/* Function forward definitions */
int64_t _51_main(void);
int64_t _53_f(struct1 _53_x);

/* Function definitions */
int64_t _51_main(void){
    struct0 _51_t1;
    struct0 _51_t2;
    struct0 _51_t3;
    struct1 _52_x;
    function2 _51_t4;
    int64_t _51_t5;
    int64_t _51_$retval;
    _51_t1 = (struct0) {.tag=0};
    _51_t2 = (struct0) {.tag=1};
    _51_t3 = (struct0) {.tag=2};
    _52_x = (struct1) {_51_t1, _51_t2, _51_t3};
    _51_t4 = _53_f;
    $lines[$line_idx++] = "tests/integration/arrays/array-sum.orng:6:7:\n    f(x)\n     ^";
    _51_t5 = _51_t4(_52_x);
    $line_idx--;
    _51_$retval = _51_t5;
    return _51_$retval;
}

int64_t _53_f(struct1 _53_x){
    int64_t _53_t1;
    int64_t _53_t2;
    uint64_t _53_t6;
    uint64_t _53_t7;
    uint8_t _53_t5;
    int64_t _53_t0;
    int64_t _53_$retval;
    _53_t1 = 1;
    _53_t2 = 3;
    $bounds_check(_53_t1, _53_t2, "tests/integration/arrays/array-sum.orng:9:7:\nfn f(x: [3]My_Type) -> Int {\n     ^");
    _53_t6 = (*((struct0*)&_53_x + _53_t1)).tag;
    _53_t7 = 1;
    _53_t5 = _53_t6==_53_t7;
    if (_53_t5) {
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
