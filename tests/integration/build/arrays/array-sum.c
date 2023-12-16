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
int64_t _83_main(void);
int64_t _87_f(struct1 _87_x);

/* Function definitions */
int64_t _83_main(void){
    struct0 _83_t1;
    struct0 _83_t2;
    struct0 _83_t3;
    struct1 _84_x;
    function2 _83_t4;
    int64_t _83_t5;
    int64_t _83_$retval;
    _83_t1 = (struct0) {.tag=0};
    _83_t2 = (struct0) {.tag=1};
    _83_t3 = (struct0) {.tag=2};
    _84_x = (struct1) {_83_t1, _83_t2, _83_t3};
    _83_t4 = _87_f;
    $lines[$line_idx++] = "tests/integration/arrays/array-sum.orng:6:7:\n    f(x)\n     ^";
    _83_t5 = _83_t4(_84_x);
    $line_idx--;
    _83_$retval = _83_t5;
    return _83_$retval;
}

int64_t _87_f(struct1 _87_x){
    int64_t _87_t1;
    uint64_t _87_t5;
    uint64_t _87_t6;
    uint8_t _87_t4;
    int64_t _87_t0;
    int64_t _87_$retval;
    _87_t1 = 1;
    _87_t5 = (*((struct0*)&_87_x + _87_t1)).tag;
    _87_t6 = 1;
    _87_t4 = _87_t5 == _87_t6;
    if (_87_t4) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _87_t0 = 215;
    goto BB6;
BB7:
    _87_t0 = 3;
    goto BB6;
BB6:
    _87_$retval = _87_t0;
    return _87_$retval;
}

int main(void) {
  printf("%ld",_83_main());
  return 0;
}
