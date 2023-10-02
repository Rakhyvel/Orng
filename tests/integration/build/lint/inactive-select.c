/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    uint64_t tag;
    union {
        int64_t _0;
        int64_t _1;
    };
} struct0;

/* Function forward definitions */
int64_t _1_main();
struct0 _3_f();

/* Function definitions */
int64_t _1_main() {
    struct0 _1_t0;
    int64_t _1_$retval;
$lines[$line_idx++] = "tests/integration/lint/inactive-select.orng:3:15:\n    let x = f()\n             ^";    _1_t0 = _3_f();
    $line_idx--;
    $tag_check(_1_t0.tag, 1, "tests/integration/lint/inactive-select.orng:2:3:\nfn main() -> Int {\n ^");
    _1_$retval = _1_t0._1;
    return _1_$retval;
}

struct0 _3_f() {
    struct0 _3_$retval;
    _3_$retval = (struct0) {.tag=0, ._0=4};
    return _3_$retval;
}

int main()
{
  printf("%ld",_1_main());
  return 0;
}
