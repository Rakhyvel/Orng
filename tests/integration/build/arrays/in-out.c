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
int64_t _116_main(void);
void _120_f(struct0* _120_x);

/* Function definitions */
int64_t _116_main(void) {
    int64_t _116_t1;
    int64_t _116_t2;
    int64_t _116_t3;
    struct0 _117_x;
    function1 _116_t4;
    struct0* _116_t6;
    int64_t _116_t7;
    int64_t _116_$retval;
    _116_t1 = 1;
    _116_t2 = 2;
    _116_t3 = 3;
    _117_x = (struct0) {_116_t1, _116_t2, _116_t3};
    _116_t4 = _120_f;
    _116_t6 = &_117_x;
    $lines[$line_idx++] = "tests/integration/arrays/in-out.orng:4:7:\n    f(&mut x)\n     ^";
    _116_t4(_116_t6);
    $line_idx--;
    _116_t7 = 1;
    _116_$retval = *((int64_t*)&_117_x + _116_t7);
    return _116_$retval;
}

void _120_f(struct0* _120_x) {
    int64_t _120_t1;
    _120_t1 = 1;
    *((int64_t*)_120_x + _120_t1) = 217;
}

int main(void) {
  printf("%ld",_116_main());
  return 0;
}
