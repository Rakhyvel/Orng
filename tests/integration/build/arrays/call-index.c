/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
    int64_t _2;
    int64_t _3;
} struct0;

typedef struct0*(*function1)(struct0*);

/* Function forward definitions */
int64_t _101_main(void);
struct0* _105_f(struct0* _105_x);

/* Function definitions */
int64_t _101_main(void) {
    int64_t _101_t1;
    int64_t _101_t2;
    int64_t _101_t3;
    int64_t _101_t4;
    struct0 _102_x;
    int64_t _101_t5;
    function1 _101_t6;
    struct0* _101_t8;
    struct0* _101_t7;
    int64_t _101_$retval;
    _101_t1 = 1;
    _101_t2 = 2;
    _101_t3 = 3;
    _101_t4 = 4;
    _102_x = (struct0) {_101_t1, _101_t2, _101_t3, _101_t4};
    _101_t5 = 3;
    _101_t6 = _105_f;
    _101_t8 = &_102_x;
    $lines[$line_idx++] = "tests/integration/arrays/call-index.orng:4:7:\n    f(&mut x)^[3]\n     ^";
    _101_t7 = _101_t6(_101_t8);
    $line_idx--;
    _101_$retval = *((int64_t*)_101_t7 + _101_t5);
    return _101_$retval;
}

struct0* _105_f(struct0* _105_x) {
    int64_t _105_t1;
    struct0* _105_$retval;
    _105_t1 = 3;
    *((int64_t*)_105_x + _105_t1) = 78;
    _105_$retval = _105_x;
    return _105_$retval;
}

int main(void) {
  printf("%ld",_101_main());
  return 0;
}
