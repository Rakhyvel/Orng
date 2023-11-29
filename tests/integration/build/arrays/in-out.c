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
int64_t _85_main(void);
void _88_f(struct0* _88_x);

/* Function definitions */
int64_t _85_main(void) {
    int64_t _85_t1;
    int64_t _85_t2;
    int64_t _85_t3;
    struct0 _86_x;
    function1 _85_t4;
    struct0* _85_t6;
    int64_t _85_t7;
    int64_t _85_$retval;
    _85_t1 = 1;
    _85_t2 = 2;
    _85_t3 = 3;
    _86_x = (struct0) {_85_t1, _85_t2, _85_t3};
    _85_t4 = _88_f;
    _85_t6 = &_86_x;
    $lines[$line_idx++] = "tests/integration/arrays/in-out.orng:4:7:\n    f(&mut x)\n     ^";
    _85_t4(_85_t6);
    $line_idx--;
    _85_t7 = 1;
    _85_$retval = *((int64_t*)&_86_x + _85_t7);
    return _85_$retval;
}

void _88_f(struct0* _88_x) {
    int64_t _88_t1;
    _88_t1 = 1;
    *((int64_t*)_88_x + _88_t1) = 217;
}

int main(void) {
  printf("%ld",_85_main());
  return 0;
}
