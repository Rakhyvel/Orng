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
struct0 _3_get_array(int64_t _3_a,int64_t _3_b);

/* Function definitions */
int64_t _1_main(void) {
    struct0 _1_t0;
    int64_t _1_$retval;
    $lines[$line_idx++] = "tests/integration/arrays/index.orng:3:32:\n    let x: [4]Int  = get_array(15, 16)\n                              ^";
    _1_t0 = _3_get_array(15, 16);
    $line_idx--;
    _1_$retval = $add_int64_t($add_int64_t($add_int64_t(*(int64_t*)&_1_t0, *((int64_t*)&_1_t0 + 1), "tests/integration/arrays/index.orng:4:11:\n    x[0] + x[1] + x[2] + x[3]\n         ^"), *((int64_t*)&_1_t0 + 2), "tests/integration/arrays/index.orng:4:18:\n    x[0] + x[1] + x[2] + x[3]\n                ^"), *((int64_t*)&_1_t0 + 3), "tests/integration/arrays/index.orng:2:3:\nfn main() -> Int {\n ^");
    return _1_$retval;
}

struct0 _3_get_array(int64_t _3_a,int64_t _3_b) {
    struct0 _3_$retval;
    _3_$retval = (struct0) {_3_a, _3_b, _3_a, _3_b};
    return _3_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
