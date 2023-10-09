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

/* Function forward definitions */
int64_t _1_main(void);
void _3_f(struct0* _3_x);

/* Function definitions */
int64_t _1_main(void) {
    struct0 _2_x;
    struct0* _1_t5;
    int64_t _1_$retval;
    _2_x = (struct0) {1, 2, 3};
    _1_t5 = &_2_x;
    $lines[$line_idx++] = "tests/integration/arrays/in-out.orng:4:7:\n    f(&mut x)\n     ^";
    _3_f(_1_t5);
    $line_idx--;
    _1_$retval = *((int64_t*)&_2_x + 1);
    return _1_$retval;
}

void _3_f(struct0* _3_x) {
    *((int64_t*)_3_x + 1) = 217;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
