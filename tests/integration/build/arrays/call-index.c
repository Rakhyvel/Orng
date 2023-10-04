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

/* Function forward definitions */
int64_t _1_main(void);
struct0* _3_f(struct0* _3_x);

/* Function definitions */
int64_t _1_main(void) {
    struct0 _2_x;
    struct0* _1_t6;
    struct0* _1_t5;
    int64_t _1_$retval;
    _2_x = (struct0) {1, 2, 3, 4};
    _1_t6 = &_2_x;
    $lines[$line_idx++] = "tests/integration/arrays/call-index.orng:4:7:\n    f(&mut x)^[3]\n     ^";
    _1_t5 = _3_f(_1_t6);
    $line_idx--;
    _1_$retval = *((int64_t*)_1_t5 + 3);
    return _1_$retval;
}

struct0* _3_f(struct0* _3_x) {
    struct0* _3_$retval;
    *((int64_t*)_3_x + 3) = 78;
    _3_$retval = _3_x;
    return _3_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
