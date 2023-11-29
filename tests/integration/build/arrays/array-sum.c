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
int64_t _63_main(void);
int64_t _66_f(struct1 _66_x);

/* Function definitions */
int64_t _63_main(void) {
    struct0 _63_t1;
    struct0 _63_t2;
    struct0 _63_t3;
    struct1 _64_x;
    function2 _63_t4;
    int64_t _63_t5;
    int64_t _63_$retval;
    _63_t1 = (struct0) {.tag=0};
    _63_t2 = (struct0) {.tag=1};
    _63_t3 = (struct0) {.tag=2};
    _64_x = (struct1) {_63_t1, _63_t2, _63_t3};
    _63_t4 = _66_f;
    $lines[$line_idx++] = "tests/integration/arrays/array-sum.orng:6:7:\n    f(x)\n     ^";
    _63_t5 = _63_t4(_64_x);
    $line_idx--;
    _63_$retval = _63_t5;
    return _63_$retval;
}

int64_t _66_f(struct1 _66_x) {
    int64_t _66_t1;
    uint64_t _66_t5;
    uint64_t _66_t6;
    uint8_t _66_t4;
    int64_t _66_t0;
    int64_t _66_$retval;
    _66_t1 = 1;
    _66_t5 = (*((struct0*)&_66_x + _66_t1)).tag;
    _66_t6 = 1;
    _66_t4 = _66_t5 == _66_t6;
    if (_66_t4) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _66_t0 = 215;
    goto BB6;
BB7:
    _66_t0 = 3;
    goto BB6;
BB6:
    _66_$retval = _66_t0;
    return _66_$retval;
}

int main(void) {
  printf("%ld",_63_main());
  return 0;
}
