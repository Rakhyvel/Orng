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
int64_t _89_main(void);
int64_t _93_f(struct1 _93_x);

/* Function definitions */
int64_t _89_main(void) {
    struct0 _89_t1;
    struct0 _89_t2;
    struct0 _89_t3;
    struct1 _90_x;
    function2 _89_t4;
    int64_t _89_t5;
    int64_t _89_$retval;
    _89_t1 = (struct0) {.tag=0};
    _89_t2 = (struct0) {.tag=1};
    _89_t3 = (struct0) {.tag=2};
    _90_x = (struct1) {_89_t1, _89_t2, _89_t3};
    _89_t4 = _93_f;
    $lines[$line_idx++] = "tests/integration/arrays/array-sum.orng:6:7:\n    f(x)\n     ^";
    _89_t5 = _89_t4(_90_x);
    $line_idx--;
    _89_$retval = _89_t5;
    return _89_$retval;
}

int64_t _93_f(struct1 _93_x) {
    int64_t _93_t1;
    uint64_t _93_t5;
    uint64_t _93_t6;
    uint8_t _93_t4;
    int64_t _93_t0;
    int64_t _93_$retval;
    _93_t1 = 1;
    _93_t5 = (*((struct0*)&_93_x + _93_t1)).tag;
    _93_t6 = 1;
    _93_t4 = _93_t5 == _93_t6;
    if (_93_t4) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _93_t0 = 215;
    goto BB6;
BB7:
    _93_t0 = 3;
    goto BB6;
BB6:
    _93_$retval = _93_t0;
    return _93_$retval;
}

int main(void) {
  printf("%ld",_89_main());
  return 0;
}
