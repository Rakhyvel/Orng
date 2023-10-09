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

/* Function definitions */
int64_t _1_main(void) {
    struct0 _2_x;
    int64_t* _2_a;
    int64_t* _2_b;
    int64_t* _2_c;
    int64_t _1_$retval;
    _2_x = (struct0) {0, 0, 0};
    _2_a = (int64_t*)&_2_x;
    _2_b = ((int64_t*)&_2_x + 1);
    _2_c = ((int64_t*)&_2_x + 2);
    **&_2_a = 100;
    **&_2_b = 30;
    **&_2_c = 30;
    _1_$retval = $add_int64_t($add_int64_t(*_2_a, *_2_b, "tests/integration/pattern/assign-deref-product.orng:8:9:\n    a^ + b^ + c^\n       ^"), *_2_c, "tests/integration/pattern/assign-deref-product.orng:8:14:\n    a^ + b^ + c^\n            ^");
    return _1_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
