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
} struct0;

typedef void(*function1)(struct0*);

/* Function forward definitions */
int64_t _66_main(void);
void _68_f(struct0* _68_x);

/* Function definitions */
int64_t _66_main(void) {
    int64_t _66_t1;
    int64_t _66_t2;
    int64_t _66_t3;
    struct0 _67_x;
    function1 _66_t4;
    struct0* _66_t6;
    int64_t _66_t7;
    int64_t _66_$retval;
    _66_t1 = 1;
    _66_t2 = 2;
    _66_t3 = 3;
    _67_x = (struct0) {_66_t1, _66_t2, _66_t3};
    _66_t4 = _68_f;
    _66_t6 = &_67_x;
    $lines[$line_idx++] = "tests/integration/arrays/in-out.orng:4:7:\n    f(&mut x)\n     ^";
    _66_t4(_66_t6);
    $line_idx--;
    _66_t7 = 1;
    _66_$retval = *((int64_t*)&_67_x + _66_t7);
    return _66_$retval;
}

void _68_f(struct0* _68_x) {
    int64_t _68_t1;
    _68_t1 = 1;
    *((int64_t*)_68_x + _68_t1) = 217;
    return;
}

int main(void) {
  printf("%ld",_66_main());
  return 0;
}
