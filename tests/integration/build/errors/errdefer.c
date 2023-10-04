/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    uint64_t tag;
} struct0;

/* Function forward definitions */
int64_t _1_main();
struct0 _3_f(int64_t* _3_x,uint8_t _3_fail);

/* Function definitions */
int64_t _1_main() {
    int64_t _2_x;
    int64_t _2_y;
    int64_t* _1_t3;
    int64_t* _1_t7;
    int64_t _1_$retval;
    _2_x = 10;
    _2_y = 10;
    _1_t3 = &_2_x;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:5:11:\n    _ = f(&mut x, true)\n         ^";
    $line_idx--;
    (void)_3_f(_1_t3, 1);
    _1_t7 = &_2_y;
    $lines[$line_idx++] = "tests/integration/errors/errdefer.orng:6:11:\n    _ = f(&mut y, false)\n         ^";
    $line_idx--;
    (void)_3_f(_1_t7, 0);
    _1_$retval = $add_int64_t(_2_x, _2_y, "tests/integration/errors/errdefer.orng:2:3:\nfn main() -> Int {\n ^");
    return _1_$retval;
}

struct0 _3_f(int64_t* _3_x,uint8_t _3_fail) {
    struct0 _3_$retval;
    **&_3_x = 4;
    if (_3_fail) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _3_$retval = (struct0) {.tag=0};
    **&_3_x = 115;
    return _3_$retval;
BB4:
    _3_$retval = (struct0) {.tag=1};
    return _3_$retval;
}

int main()
{
  printf("%ld",_1_main());
  return 0;
}
