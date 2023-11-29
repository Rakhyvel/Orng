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
int64_t _73_main(void);
struct0* _76_f(struct0* _76_x);

/* Function definitions */
int64_t _73_main(void) {
    int64_t _73_t1;
    int64_t _73_t2;
    int64_t _73_t3;
    int64_t _73_t4;
    struct0 _74_x;
    int64_t _73_t5;
    function1 _73_t6;
    struct0* _73_t8;
    struct0* _73_t7;
    int64_t _73_$retval;
    _73_t1 = 1;
    _73_t2 = 2;
    _73_t3 = 3;
    _73_t4 = 4;
    _74_x = (struct0) {_73_t1, _73_t2, _73_t3, _73_t4};
    _73_t5 = 3;
    _73_t6 = _76_f;
    _73_t8 = &_74_x;
    $lines[$line_idx++] = "tests/integration/arrays/call-index.orng:4:7:\n    f(&mut x)^[3]\n     ^";
    _73_t7 = _73_t6(_73_t8);
    $line_idx--;
    _73_$retval = *((int64_t*)_73_t7 + _73_t5);
    return _73_$retval;
}

struct0* _76_f(struct0* _76_x) {
    int64_t _76_t1;
    struct0* _76_$retval;
    _76_t1 = 3;
    *((int64_t*)_76_x + _76_t1) = 78;
    _76_$retval = _76_x;
    return _76_$retval;
}

int main(void) {
  printf("%ld",_73_main());
  return 0;
}
