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
struct0 _3_get_array(void);

/* Function definitions */
int64_t _1_main(void) {
    struct0 _2_x;
    struct0 _1_t4;
    int64_t _1_$retval;
    _2_x = (struct0) {0, 0, 0};
    $lines[$line_idx++] = "tests/integration/pattern/assign-array.orng:4:36:\n    (x[0], x[1], x[2]) = get_array()\n                                  ^";
    _1_t4 = _3_get_array();
    $line_idx--;
    *(int64_t*)&_2_x = _1_t4._0;
    *((int64_t*)&_2_x + 1) = _1_t4._1;
    *((int64_t*)&_2_x + 2) = _1_t4._2;
    _1_$retval = $add_int64_t($add_int64_t(*(int64_t*)&_2_x, *((int64_t*)&_2_x + 1), "tests/integration/pattern/assign-array.orng:5:11:\n    x[0] + x[1] + x[2]\n         ^"), *((int64_t*)&_2_x + 2), "tests/integration/pattern/assign-array.orng:2:3:\nfn main() -> Int {\n ^");
    return _1_$retval;
}

struct0 _3_get_array(void) {
    struct0 _3_$retval;
    _3_$retval = (struct0) {200, 3, 4};
    return _3_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
