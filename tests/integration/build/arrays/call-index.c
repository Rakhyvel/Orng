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
int64_t _59_main(void);
struct0* _61_f(struct0* _61_x);

/* Function definitions */
int64_t _59_main(void) {
    int64_t _59_t1;
    int64_t _59_t2;
    int64_t _59_t3;
    int64_t _59_t4;
    struct0 _60_x;
    int64_t _59_t5;
    function1 _59_t6;
    struct0* _59_t8;
    struct0* _59_t7;
    int64_t _59_$retval;
    _59_t1 = 1;
    _59_t2 = 2;
    _59_t3 = 3;
    _59_t4 = 4;
    _60_x = (struct0) {_59_t1, _59_t2, _59_t3, _59_t4};
    _59_t5 = 3;
    _59_t6 = _61_f;
    _59_t8 = &_60_x;
    $lines[$line_idx++] = "tests/integration/arrays/call-index.orng:4:7:\n    f(&mut x)^[3]\n     ^";
    _59_t7 = _59_t6(_59_t8);
    $line_idx--;
    _59_$retval = *((int64_t*)_59_t7 + _59_t5);
    return _59_$retval;
}

struct0* _61_f(struct0* _61_x) {
    int64_t _61_t1;
    struct0* _61_$retval;
    _61_t1 = 3;
    *((int64_t*)_61_x + _61_t1) = 78;
    _61_$retval = _61_x;
    return _61_$retval;
}

int main(void) {
  printf("%ld",_59_main());
  return 0;
}
